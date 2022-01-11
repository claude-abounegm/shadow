/**
 * Authors: Claude Abounegm and Barry Wittman
 */
#include <Shadow.h>
#include <io/File.h>
#include <standard/String.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// EXPORTED METHODS
void _shadowIoFile_throwException(shadow_io_File_t* file, shadow_String_t* message);

#ifdef SHADOW_WINDOWS
	#include <Windows.h>
#else
	#include <unistd.h>
	#include <fcntl.h>
	#include <errno.h>
	#include <sys/types.h>
    #include <sys/stat.h>
#endif

static void reportError(char* error)
{
    shadow_String_t* message = NULL;
#ifdef SHADOW_WINDOWS
    DWORD errorCode = GetLastError();
    LPVOID messageBuffer = NULL;
    FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            errorCode,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPSTR) &messageBuffer,
            0, NULL );

    if(messageBuffer != NULL) {
        rsize_t totalLength = strlen(error) + strlen(": ") + strlen(messageBuffer);
        char* buffer = malloc(totalLength + 1);
        sprintf_s(buffer, totalLength + 1, "%s: %s", error, messageBuffer);
        int length = strlen(buffer);
        // Trim off trailing newlines
        while (length > 0 && (buffer[length - 1] == '\r' || buffer[length - 1] == '\n')) {
            buffer[length - 1] = '\0';
            --length;
        }
        message = shadowString_create(buffer);
        free(buffer);
        LocalFree(messageBuffer);
    }
    else
        message = shadowString_create(error);
    _shadowIoFile_throwException(NULL, message);
#else
    char messageBuffer[1024];
    if (strerror_r(errno, messageBuffer, sizeof(messageBuffer)) == 0) {
        size_t totalLength = strlen(error) + strlen(": ") + strlen(messageBuffer);
        char* buffer = malloc(totalLength + 1);
        sprintf(buffer, "%s: %s", error, messageBuffer);
        size_t length = strlen(buffer);
        // Trim off trailing newlines
        while (length > 0 && (buffer[length - 1] == '\r' || buffer[length - 1] == '\n')) {
            buffer[length - 1] = '\0';
            --length;
        }
        message = shadowString_create(buffer);
        free(buffer);
    }
    else
        message = shadowString_create(error);
#endif
    _shadowIoFile_throwException(NULL, message);
}

// Add support for wide characters? Perhaps something like: https://github.com/tapika/cutf
shadow_boolean_t __shadowIoFile_exists(shadow_String_t* str)
{
	char* path = shadowString_getCString(str);
	shadow_boolean_t ret;
#ifdef SHADOW_WINDOWS
	ret = GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES;
#else
	ret = access(path, F_OK) == 0;
#endif
	// Free the allocated string
	free(path);
	return ret;
}

shadow_long_t __shadowIoFile_open(shadow_String_t* str, shadow_int_t mode)
{
	char* path = shadowString_getCString(str);
    shadow_long_t result;
    bool error;
    int access = 0;
    const int READ = 1 << 0;
    const int WRITE = 1 << 1;

#ifdef SHADOW_WINDOWS
    DWORD creation;
    DWORD share = 0;
    if (mode & READ) {
        access |= GENERIC_READ;
        share |= FILE_SHARE_READ;
    }
    if (mode & WRITE) {
        access |= GENERIC_WRITE;
        share |= FILE_SHARE_WRITE;
        creation = OPEN_ALWAYS;
    }
    else
        creation = OPEN_EXISTING;

    HANDLE handle = CreateFileA(path, access, share, NULL, creation, FILE_ATTRIBUTE_NORMAL, NULL);
    error = handle == INVALID_HANDLE_VALUE;
    result = (shadow_long_t)handle;
#else
    access = 0;
    if ((mode & READ) && (mode & WRITE))
        access |= O_RDWR | O_CREAT;
    else if (mode & WRITE)
        access |= O_WRONLY | O_CREAT;
    else
        access |= O_RDONLY;
    int fd = open(path, access, 0664);
    error = fd == -1;
    result = (shadow_long_t)fd;
#endif

    // Free the allocated string
    free(path);
    if (error)
        reportError("Open file error");
    return result;
}

void __shadowIoFile_delete(shadow_String_t* str)
{
    char* path = shadowString_getCString(str);
    bool error;

#ifdef SHADOW_WINDOWS
    error = !DeleteFileA(path);
#else
    error = remove(path) == -1;
#endif

    // Free the allocated string
    free(path);
    if (error)
        reportError("Delete file error");
}

shadow_long_t __shadowIoFile_positionGet(shadow_long_t handle)
{
    if (handle == -1L) {
        shadow_String_t* message = shadowString_create("Cannot retrieve position when file is not open");
        _shadowIoFile_throwException(NULL, message);
    }

    shadow_long_t result;
    bool error;

#ifdef SHADOW_WINDOWS
    LARGE_INTEGER location;
    LARGE_INTEGER zero;
    zero.QuadPart = 0;
    location.QuadPart = 0;
    error = !SetFilePointerEx((HANDLE)handle, zero, &location, FILE_CURRENT);
    result = (shadow_long_t)location.QuadPart;
#else
    off_t location = lseek((int)handle, 0, SEEK_CUR);
    error = location == -1;
    result = (shadow_long_t)location;
#endif

    if (error)
        reportError("Get position error");

    return result;
}

void __shadowIoFile_positionSet(shadow_long_t handle, shadow_long_t position)
{
    if (handle == -1L) {
        shadow_String_t* message = shadowString_create("Cannot set position when file is not open");
        _shadowIoFile_throwException(NULL, message);
    }

    shadow_long_t result;
    bool error;

#ifdef SHADOW_WINDOWS
    error = !SetFilePointerEx((HANDLE)handle, (LARGE_INTEGER)position, NULL, FILE_BEGIN);
#else
    error = lseek((int)handle, (off_t)position, SEEK_SET) == -1;
#endif

    if (error)
        reportError("Set position error");
}

shadow_long_t __shadowIoFile_sizeGet(shadow_String_t* str)
{
    char* path = shadowString_getCString(str);
    bool error;
    shadow_long_t size;

#ifdef SHADOW_WINDOWS
    WIN32_FILE_ATTRIBUTE_DATA data;
    error = !GetFileAttributesExA (path, GetFileExInfoStandard, &data);
    size = (((shadow_long_t) data.nFileSizeHigh) << 32) + (shadow_long_t)data.nFileSizeLow;
#else
    struct stat data;
    error = stat (path, &data) == -1;
    size = (shadow_long_t)data.st_size;
#endif

    // Free the allocated string
    free(path);
    if (error)
        reportError("Get file size error");

    return size;
}


void __shadowIoFile_sizeSet(shadow_long_t handle, shadow_long_t size)
{
    bool error;

#ifdef SHADOW_WINDOWS
    shadow_long_t currentPosition = __shadowIoFile_positionGet(handle);
    if (currentPosition < size)
        currentPosition = size;
    // Move to size, set end of file, move position back to current position
    error = !SetFilePointerEx ((HANDLE)handle, (LARGE_INTEGER)size, NULL, FILE_BEGIN) ||
    	    !SetEndOfFile ((HANDLE)handle) ||
    	    !SetFilePointerEx ((HANDLE)handle, (LARGE_INTEGER)currentPosition, NULL, FILE_BEGIN);
#else
    error = ftruncate((int)handle, (off_t)size) == -1;
#endif

    if (error)
        reportError("Set file size error");
}

void __shadowIoFile_close(shadow_long_t handle)
{
#ifdef SHADOW_WINDOWS
	CloseHandle((HANDLE)handle);
#else
	close((int)handle);
#endif
}

shadow_long_t __shadowIoFile_read(shadow_long_t handle, shadow_Array_t* array)
{
    ArrayData data;
    shadowArray_getData(array, &data);
    bool error;
    shadow_long_t result = 0;
#ifdef SHADOW_WINDOWS
    DWORD bytesRead;
    error = !ReadFile((HANDLE)handle, data.data, (DWORD)data.size, &bytesRead, NULL);
    DWORD lastError = GetLastError();
    // End of file is not an error, return -1
    if (bytesRead == 0 && (lastError == ERROR_HANDLE_EOF || lastError == ERROR_BROKEN_PIPE)) {
        result = -1L;
        error = false;
    }
    else
        result = (shadow_long_t)bytesRead;
#else
    ssize_t bytesRead = read((int)handle, data.data, (size_t)data.size);
    error = bytesRead == -1;
    if (bytesRead == 0)
        result = -1L;
    else
        result = (shadow_long_t)bytesRead;
#endif

    if (error)
        reportError("Read error");

    return result;
}
shadow_long_t __shadowIoFile_write(shadow_long_t handle, shadow_Array_t* array, shadow_long_t bytes)
{
    ArrayData data;
    shadowArray_getData(array, &data);
    // Never exceed the array length
    if (bytes > data.size)
        bytes = data.size;
    bool error;
    shadow_long_t result = 0;
#ifdef SHADOW_WINDOWS
    DWORD bytesWritten;
    error = !WriteFile((HANDLE)handle, data.data, (DWORD)bytes, &bytesWritten, NULL);
    result = (shadow_long_t)bytesWritten;
#else
    ssize_t bytesWritten = write((int)handle, data.data, (size_t)bytes);
    error = bytesWritten == -1;
    result = (shadow_long_t)bytesWritten;
#endif

    if (error)
        reportError("Write error");

    return result;
}
