/* AUTO-GENERATED FILE, DO NOT EDIT! */
#include "shadow/hello/HelloWorld.meta"

struct _IArray {
	void *_Iarray;
	int_shadow_t _Idims;
	int_shadow_t _Ilengths[1];
};

static struct _IArray _Iarray0 = {
	(void *)"shadow.hello@HelloWorld", (int_shadow_t)1, {(int_shadow_t)23}
};
static struct _Pshadow_Pstandard_CString _Istring0 = {
	&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray0
};
struct _Pshadow_Pstandard_CClass _Pshadow_Phello_CHelloWorld_Iclass = {
	&_Pshadow_Pstandard_CClass_Imethods, &_Istring0
};

uint_shadow_t _Pshadow_Phello_CHelloWorld_MgetBoth(struct _Pshadow_Phello_CHelloWorld* this, struct _Pshadow_Pstandard_CString** _Ireturn1) {
	boolean_shadow_t _Itemp0;
	boolean_shadow_t _Itemp1;
	boolean_shadow_t _Itemp2;
	boolean_shadow_t _Itemp3;
	boolean_shadow_t _Itemp4;
	_Itemp0 = this->self != ((void *)0);
	if ( _Itemp0 )
		goto label0;
	else
		goto label5;
label0: (void)0;
	_Itemp1 = this->self->self != ((void *)0);
	if ( _Itemp1 )
		goto label1;
	else
		goto label5;
label1: (void)0;
	_Itemp2 = this->self != ((void *)0);
	if ( _Itemp2 )
		goto label2;
	else
		goto label5;
label2: (void)0;
	_Itemp3 = this->self->self != ((void *)0);
	if ( _Itemp3 )
		goto label3;
	else
		goto label5;
label3: (void)0;
	_Itemp4 = this->self->self->self != ((void *)0);
	if ( _Itemp4 )
		goto label4;
	else
		goto label5;
label4: (void)0;
	*_Ireturn1 = this->self->self->self->message;
	return this->self->self->times;
	goto label6;
label5: (void)0;
	static struct _IArray _Iarray1 = {
		(void *)"NullPointerException!", (int_shadow_t)1, {(int_shadow_t)21}
	};
	static struct _Pshadow_Pstandard_CString _Istring1 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray1
	};
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(&_Istring1);
	goto label6;
label6: (void)0;
	*_Ireturn1 = this->message;
	return this->times;
}

struct _Pshadow_Pstandard_CString* _Pshadow_Phello_CHelloWorld_MgetMessage(struct _Pshadow_Phello_CHelloWorld* this) {
	boolean_shadow_t _Itemp0;
	_Itemp0 = this->self != ((void *)0);
	if ( _Itemp0 )
		goto label0;
	else
		goto label1;
label0: (void)0;
	return this->self->message;
	goto label2;
label1: (void)0;
	static struct _IArray _Iarray2 = {
		(void *)"NullPointerException!", (int_shadow_t)1, {(int_shadow_t)21}
	};
	static struct _Pshadow_Pstandard_CString _Istring2 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray2
	};
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(&_Istring2);
	goto label2;
label2: (void)0;
	return this->message;
}

void _Pshadow_Phello_CHelloWorld_Mdoit(struct _Pshadow_Phello_CHelloWorld* this) {
	uint_shadow_t _Itemp0;
	uint_shadow_t _Itemp1;
	boolean_shadow_t _Itemp2;
	uint_shadow_t i;
	i = ((uint_shadow_t)0);
	goto label1;
label0: (void)0;
	_Itemp0 = i + ((uint_shadow_t)1);
	_Pshadow_Pio_CConsole_Mprint_R_Fuint(_Itemp0);
	static struct _IArray _Iarray3 = {
		(void *)": ", (int_shadow_t)1, {(int_shadow_t)2}
	};
	static struct _Pshadow_Pstandard_CString _Istring3 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray3
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring3);
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(this->message);
	_Itemp1 = i + ((uint_shadow_t)1);
	i = _Itemp1;
	goto label1;
label1: (void)0;
	_Itemp2 = i < this->times;
	if ( _Itemp2 )
		goto label0;
	else
		goto label2;
label2: (void)0;
	_Pshadow_Pio_CConsole_MprintLine();
	return;
}

uint_shadow_t _Pshadow_Phello_CHelloWorld_MgetTimes(struct _Pshadow_Phello_CHelloWorld* this) {
	return this->times;
}

struct _Pshadow_Pstandard_CObject* _Pshadow_Phello_CHelloWorld_MgetSelfObject(struct _Pshadow_Phello_CHelloWorld* this) {
	return this->self;
}

uint_shadow_t _Pshadow_Phello_CHelloWorld_Mfibonacci_Ruint_Ruint(uint_shadow_t first, uint_shadow_t second, uint_shadow_t* _Ireturn1, uint_shadow_t* _Ireturn2, uint_shadow_t* _Ireturn3, uint_shadow_t* _Ireturn4, uint_shadow_t* _Ireturn5, uint_shadow_t* _Ireturn6, uint_shadow_t* _Ireturn7, uint_shadow_t* _Ireturn8, struct _Pshadow_Pstandard_CString** _Ireturn9, uint_shadow_t* _Ireturn10, struct _Pshadow_Pstandard_CObject** _Ireturn11) {
	uint_shadow_t _Itemp0;
	uint_shadow_t _Itemp1;
	uint_shadow_t _Itemp2;
	uint_shadow_t _Itemp3;
	uint_shadow_t _Itemp4;
	uint_shadow_t _Itemp5;
	uint_shadow_t _Itemp6;
	uint_shadow_t _Itemp7;
	uint_shadow_t _Itemp8;
	uint_shadow_t _Itemp9;
	struct _Pshadow_Pstandard_CObject* _Itemp10;
	uint_shadow_t third;
	_Itemp0 = first + second;
	third = _Itemp0;
	uint_shadow_t fourth;
	_Itemp1 = second + third;
	fourth = _Itemp1;
	uint_shadow_t fifth;
	_Itemp2 = third + fourth;
	fifth = _Itemp2;
	uint_shadow_t sixth;
	_Itemp3 = fourth + fifth;
	sixth = _Itemp3;
	uint_shadow_t seventh;
	_Itemp4 = fifth + sixth;
	seventh = _Itemp4;
	uint_shadow_t eighth;
	_Itemp5 = sixth + seventh;
	eighth = _Itemp5;
	uint_shadow_t ninth;
	_Itemp6 = seventh + eighth;
	ninth = _Itemp6;
	_Itemp7 = third - second;
	_Itemp8 = first + second;
	_Itemp9 = eighth + ninth;
	_Itemp10 = malloc(sizeof(struct _Pshadow_Pstandard_CObject));
	_Pshadow_Pstandard_CObject_Mconstructor(_Itemp10);
	*_Ireturn1 = second;
	*_Ireturn2 = _Itemp8;
	*_Ireturn3 = fourth;
	*_Ireturn4 = fifth;
	*_Ireturn5 = sixth;
	*_Ireturn6 = seventh;
	*_Ireturn7 = eighth;
	*_Ireturn8 = ninth;
	static struct _IArray _Iarray4 = {
		(void *)"String Test", (int_shadow_t)1, {(int_shadow_t)11}
	};
	static struct _Pshadow_Pstandard_CString _Istring4 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray4
	};
	*_Ireturn9 = &_Istring4;
	*_Ireturn10 = _Itemp9;
	*_Ireturn11 = _Itemp10;
	return _Itemp7;
}

void _Pshadow_Phello_CHelloWorld_Mmain_R_Pshadow_Pstandard_CString_A1(struct _IArray * args) {
	boolean_shadow_t _Itemp0;
	uint_shadow_t _Itemp1;
	uint_shadow_t _Itemp2;
	uint_shadow_t _Itemp3;
	uint_shadow_t _Itemp4;
	uint_shadow_t _Itemp5;
	uint_shadow_t _Itemp6;
	uint_shadow_t _Itemp7;
	uint_shadow_t _Itemp8;
	uint_shadow_t _Itemp9;
	struct _Pshadow_Pstandard_CString* _Itemp10;
	uint_shadow_t _Itemp11;
	struct _Pshadow_Pstandard_CObject* _Itemp12;
	uint_shadow_t _Itemp13;
	uint_shadow_t _Itemp14;
	uint_shadow_t _Itemp15;
	boolean_shadow_t _Itemp16;
	struct _Pshadow_Phello_CHelloWorld* _Itemp17;
	struct _Pshadow_Phello_CHelloWorld* _Itemp18;
	uint_shadow_t _Itemp19;
	struct _Pshadow_Pstandard_CString* _Itemp20;
	boolean_shadow_t _Itemp21;
	struct _Pshadow_Phello_CHelloWorld* _Itemp22;
	struct _Pshadow_Phello_CHelloWorld* _Itemp23;
	struct _Pshadow_Phello_CHelloWorld* _Itemp24;
	struct _Pshadow_Phello_CHelloWorld* _Itemp25;
	boolean_shadow_t _Itemp26;
	struct _Pshadow_Phello_CHelloWorld* _Itemp27;
	boolean_shadow_t _Itemp28;
	boolean_shadow_t _Itemp29;
	struct _Pshadow_Phello_CHelloWorld* _Itemp30;
	boolean_shadow_t _Itemp31;
	boolean_shadow_t _Itemp32;
	boolean_shadow_t _Itemp33;
	struct _Pshadow_Phello_CHelloWorld* _Itemp34;
	struct _Pshadow_Pstandard_CObject* _Itemp35;
	boolean_shadow_t _Itemp36;
	struct _Pshadow_Pstandard_CObject* _Itemp37;
	boolean_shadow_t _Itemp38;
	boolean_shadow_t _Itemp39;
	struct _Pshadow_Pstandard_CObject* _Itemp40;
	boolean_shadow_t _Itemp41;
	boolean_shadow_t _Itemp42;
	boolean_shadow_t _Itemp43;
	struct _Pshadow_Pstandard_CObject* _Itemp44;
	struct _Pshadow_Phello_CHelloWorld* _Itemp45;
	struct _Pshadow_Pstandard_CString* _Itemp46;
	struct _Pshadow_Pstandard_CString* _Itemp47;
	struct _Pshadow_Phello_CHelloWorld* _Itemp48;
	struct _Pshadow_Pstandard_CString* _Itemp49;
	struct _Pshadow_Pstandard_CString* _Itemp50;
	struct _Pshadow_Phello_CHelloWorld* _Itemp51;
	struct _Pshadow_Pstandard_CString* _Itemp52;
	struct _Pshadow_Pstandard_CString* _Itemp53;
	struct _Pshadow_Phello_CHelloWorld* _Itemp54;
	struct _Pshadow_Pstandard_CString* _Itemp55;
	struct _Pshadow_Pstandard_CString* _Itemp56;
	struct _Pshadow_Pstandard_CObject* _Itemp57;
	struct _Pshadow_Pstandard_CObject* _Itemp58;
	struct _Pshadow_Pstandard_CString* _Itemp59;
	struct _Pshadow_Pstandard_CString* _Itemp60;
	struct _Pshadow_Pstandard_CObject* _Itemp61;
	struct _Pshadow_Pstandard_CString* _Itemp62;
	struct _Pshadow_Pstandard_CString* _Itemp63;
	boolean_shadow_t _Itemp64;
	struct _Pshadow_Pstandard_CObject* _Itemp65;
	struct _Pshadow_Pstandard_CString* _Itemp66;
	struct _Pshadow_Pstandard_CString* _Itemp67;
	boolean_shadow_t _Itemp68;
	boolean_shadow_t _Itemp69;
	struct _Pshadow_Pstandard_CObject* _Itemp70;
	struct _Pshadow_Pstandard_CString* _Itemp71;
	struct _Pshadow_Pstandard_CString* _Itemp72;
	struct _Pshadow_Pstandard_CString* name;
	static struct _IArray _Iarray5 = {
		(void *)"Fibonacci", (int_shadow_t)1, {(int_shadow_t)9}
	};
	static struct _Pshadow_Pstandard_CString _Istring5 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray5
	};
	name = &_Istring5;
	uint_shadow_t start;
	start = ((uint_shadow_t)0);
	uint_shadow_t temp;
	temp = ((uint_shadow_t)10000000);
	goto label4;
label0: (void)0;
	_Itemp0 = start == ((uint_shadow_t)2);
	if ( _Itemp0 )
		goto label1;
	else
		goto label2;
label1: (void)0;
	static struct _IArray _Iarray6 = {
		(void *)"Lucas", (int_shadow_t)1, {(int_shadow_t)5}
	};
	static struct _Pshadow_Pstandard_CString _Istring6 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray6
	};
	name = &_Istring6;
	goto label3;
label2: (void)0;
	goto label3;
label3: (void)0;
	struct _Pshadow_Pstandard_CObject* last;
	last = ((void *)0);
	struct _Pshadow_Pstandard_CString* test;
	test = ((void *)0);
	uint_shadow_t fib0;
	fib0 = 0;
	uint_shadow_t fib1;
	fib1 = 0;
	uint_shadow_t fib2;
	fib2 = 0;
	uint_shadow_t fib3;
	fib3 = 0;
	uint_shadow_t fib4;
	fib4 = 0;
	uint_shadow_t fib5;
	fib5 = 0;
	uint_shadow_t fib6;
	fib6 = 0;
	uint_shadow_t fib7;
	fib7 = 0;
	uint_shadow_t fib8;
	fib8 = 0;
	uint_shadow_t fib9;
	fib9 = 0;
	_Itemp1 = _Pshadow_Phello_CHelloWorld_Mfibonacci_Ruint_Ruint(start, ((uint_shadow_t)1), &_Itemp2, &_Itemp3, &_Itemp4, &_Itemp5, &_Itemp6, &_Itemp7, &_Itemp8, &_Itemp9, &_Itemp10, &_Itemp11, &_Itemp12);
	fib0 = _Itemp1;
	fib1 = _Itemp2;
	fib2 = _Itemp3;
	fib3 = _Itemp4;
	fib4 = _Itemp5;
	fib5 = _Itemp6;
	fib6 = _Itemp7;
	fib7 = _Itemp8;
	fib8 = _Itemp9;
	test = _Itemp10;
	fib9 = _Itemp11;
	last = _Itemp12;
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray7 = {
		(void *)" 0: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring7 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray7
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring7);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib0);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray8 = {
		(void *)" 1: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring8 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray8
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring8);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib1);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray9 = {
		(void *)" 2: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring9 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray9
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring9);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib2);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray10 = {
		(void *)" 3: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring10 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray10
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring10);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib3);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray11 = {
		(void *)" 4: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring11 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray11
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring11);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib4);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray12 = {
		(void *)" 5: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring12 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray12
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring12);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib5);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray13 = {
		(void *)" 6: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring13 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray13
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring13);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib6);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray14 = {
		(void *)" 7: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring14 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray14
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring14);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib7);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray15 = {
		(void *)" 8: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring15 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray15
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring15);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib8);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray16 = {
		(void *)" 9: ", (int_shadow_t)1, {(int_shadow_t)4}
	};
	static struct _Pshadow_Pstandard_CString _Istring16 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray16
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring16);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(fib9);
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(name);
	static struct _IArray _Iarray17 = {
		(void *)" 10: ", (int_shadow_t)1, {(int_shadow_t)5}
	};
	static struct _Pshadow_Pstandard_CString _Istring17 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray17
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring17);
	_Itemp13 = fib8 + fib9;
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(_Itemp13);
	_Pshadow_Pio_CConsole_MprintLine();
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(test);
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CObject(last);
	_Pshadow_Pio_CConsole_MprintLine();
	_Itemp14 = start + ((uint_shadow_t)1);
	start = _Itemp14;
	_Itemp15 = temp - ((uint_shadow_t)10000);
	temp = _Itemp15;
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(temp);
	goto label4;
label4: (void)0;
	_Itemp16 = start <= ((uint_shadow_t)2);
	if ( _Itemp16 )
		goto label0;
	else
		goto label5;
label5: (void)0;
	struct _Pshadow_Phello_CHelloWorld* hello1;
	_Itemp17 = malloc(sizeof(struct _Pshadow_Phello_CHelloWorld));
	_Pshadow_Phello_CHelloWorld_Mconstructor(_Itemp17);
	hello1 = _Itemp17;
	uint_shadow_t defaultTimes;
	defaultTimes = 0u;
	struct _Pshadow_Pstandard_CString* defaultMessage;
	static struct _IArray _Iarray18 = {
		(void *)"", (int_shadow_t)1, {(int_shadow_t)0}
	};
	static struct _Pshadow_Pstandard_CString _Istring18 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray18
	};
	defaultMessage = &_Istring18;
	_Itemp18 = (struct _Pshadow_Phello_CHelloWorld*)hello1;
	_Itemp19 = _Itemp18->_Imethods->_MgetBoth(_Itemp18, &_Itemp20);
	defaultTimes = _Itemp19;
	defaultMessage = _Itemp20;
	static struct _IArray _Iarray19 = {
		(void *)"Default times: ", (int_shadow_t)1, {(int_shadow_t)15}
	};
	static struct _Pshadow_Pstandard_CString _Istring19 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray19
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring19);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(defaultTimes);
	_Pshadow_Pio_CConsole_MprintLine_R_Fuint(hello1->times);
	static struct _IArray _Iarray20 = {
		(void *)"Default message: ", (int_shadow_t)1, {(int_shadow_t)17}
	};
	static struct _Pshadow_Pstandard_CString _Istring20 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray20
	};
	_Pshadow_Pio_CConsole_Mprint_R_F_Pshadow_Pstandard_CString(&_Istring20);
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(defaultMessage);
	_Itemp21 = hello1->self != ((void *)0);
	if ( _Itemp21 )
		goto label6;
	else
		goto label22;
label6: (void)0;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(hello1->self->message);
	_Pshadow_Pio_CConsole_MprintLine();
	struct _Pshadow_Phello_CHelloWorld* hello2;
	_Itemp22 = malloc(sizeof(struct _Pshadow_Phello_CHelloWorld));
	_Pshadow_Phello_CHelloWorld_Mconstructor_Ruint(_Itemp22, ((uint_shadow_t)10));
	hello2 = _Itemp22;
	struct _Pshadow_Phello_CHelloWorld* hello3;
	_Itemp23 = malloc(sizeof(struct _Pshadow_Phello_CHelloWorld));
	static struct _IArray _Iarray21 = {
		(void *)"Five Times!", (int_shadow_t)1, {(int_shadow_t)11}
	};
	static struct _Pshadow_Pstandard_CString _Istring21 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray21
	};
	_Pshadow_Phello_CHelloWorld_Mconstructor_R_Pshadow_Pstandard_CString(_Itemp23, &_Istring21);
	hello3 = _Itemp23;
	struct _Pshadow_Phello_CHelloWorld* hello4;
	_Itemp24 = malloc(sizeof(struct _Pshadow_Phello_CHelloWorld));
	static struct _IArray _Iarray22 = {
		(void *)"Fifteen Times!", (int_shadow_t)1, {(int_shadow_t)14}
	};
	static struct _Pshadow_Pstandard_CString _Istring22 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray22
	};
	_Pshadow_Phello_CHelloWorld_Mconstructor_Ruint_R_Pshadow_Pstandard_CString(_Itemp24, ((uint_shadow_t)15), &_Istring22);
	hello4 = _Itemp24;
	_Itemp25 = (struct _Pshadow_Phello_CHelloWorld*)hello1;
	_Itemp25->_Imethods->_Mdoit(_Itemp25);
	_Itemp26 = hello2->self != ((void *)0);
	if ( _Itemp26 )
		goto label7;
	else
		goto label22;
label7: (void)0;
	_Itemp27 = (struct _Pshadow_Phello_CHelloWorld*)hello2->self;
	_Itemp27->_Imethods->_Mdoit(_Itemp27);
	_Itemp28 = hello3->self != ((void *)0);
	if ( _Itemp28 )
		goto label8;
	else
		goto label22;
label8: (void)0;
	_Itemp29 = hello3->self->self != ((void *)0);
	if ( _Itemp29 )
		goto label9;
	else
		goto label22;
label9: (void)0;
	_Itemp30 = (struct _Pshadow_Phello_CHelloWorld*)hello3->self->self;
	_Itemp30->_Imethods->_Mdoit(_Itemp30);
	_Itemp31 = hello4->self != ((void *)0);
	if ( _Itemp31 )
		goto label10;
	else
		goto label22;
label10: (void)0;
	_Itemp32 = hello4->self->self != ((void *)0);
	if ( _Itemp32 )
		goto label11;
	else
		goto label22;
label11: (void)0;
	_Itemp33 = hello4->self->self->self != ((void *)0);
	if ( _Itemp33 )
		goto label12;
	else
		goto label22;
label12: (void)0;
	_Itemp34 = (struct _Pshadow_Phello_CHelloWorld*)hello4->self->self->self;
	_Itemp34->_Imethods->_Mdoit(_Itemp34);
	_Itemp35 = (struct _Pshadow_Pstandard_CObject*)hello1;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CObject(_Itemp35);
	_Itemp36 = hello2->self != ((void *)0);
	if ( _Itemp36 )
		goto label13;
	else
		goto label22;
label13: (void)0;
	_Itemp37 = (struct _Pshadow_Pstandard_CObject*)hello2->self;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CObject(_Itemp37);
	_Itemp38 = hello3->self != ((void *)0);
	if ( _Itemp38 )
		goto label14;
	else
		goto label22;
label14: (void)0;
	_Itemp39 = hello3->self->self != ((void *)0);
	if ( _Itemp39 )
		goto label15;
	else
		goto label22;
label15: (void)0;
	_Itemp40 = (struct _Pshadow_Pstandard_CObject*)hello3->self->self;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CObject(_Itemp40);
	_Itemp41 = hello4->self != ((void *)0);
	if ( _Itemp41 )
		goto label16;
	else
		goto label22;
label16: (void)0;
	_Itemp42 = hello4->self->self != ((void *)0);
	if ( _Itemp42 )
		goto label17;
	else
		goto label22;
label17: (void)0;
	_Itemp43 = hello4->self->self->self != ((void *)0);
	if ( _Itemp43 )
		goto label18;
	else
		goto label22;
label18: (void)0;
	_Itemp44 = (struct _Pshadow_Pstandard_CObject*)hello4->self->self->self;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CObject(_Itemp44);
	_Pshadow_Pio_CConsole_MprintLine();
	_Itemp45 = (struct _Pshadow_Phello_CHelloWorld*)hello1;
	_Itemp46 = _Itemp45->_Imethods->_MgetMessage(_Itemp45);
	_Itemp47 = (struct _Pshadow_Pstandard_CString*)_Itemp46;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(_Itemp47);
	_Itemp48 = (struct _Pshadow_Phello_CHelloWorld*)hello2;
	_Itemp49 = _Itemp48->_Imethods->_MgetMessage(_Itemp48);
	_Itemp50 = (struct _Pshadow_Pstandard_CString*)_Itemp49;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(_Itemp50);
	_Itemp51 = (struct _Pshadow_Phello_CHelloWorld*)hello3;
	_Itemp52 = _Itemp51->_Imethods->_MgetMessage(_Itemp51);
	_Itemp53 = (struct _Pshadow_Pstandard_CString*)_Itemp52;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(_Itemp53);
	_Itemp54 = (struct _Pshadow_Phello_CHelloWorld*)hello4;
	_Itemp55 = _Itemp54->_Imethods->_MgetMessage(_Itemp54);
	_Itemp56 = (struct _Pshadow_Pstandard_CString*)_Itemp55;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(_Itemp56);
	_Pshadow_Pio_CConsole_MprintLine();
	_Itemp57 = (struct _Pshadow_Pstandard_CObject*)hello1;
	_Itemp58 = (struct _Pshadow_Pstandard_CObject*)_Itemp57;
	_Itemp59 = _Itemp58->_Imethods->_MtoString(_Itemp58);
	_Itemp60 = (struct _Pshadow_Pstandard_CString*)_Itemp59;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(_Itemp60);
	_Itemp61 = (struct _Pshadow_Pstandard_CObject*)hello2;
	_Itemp62 = _Itemp61->_Imethods->_MtoString(_Itemp61);
	_Itemp63 = (struct _Pshadow_Pstandard_CString*)_Itemp62;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(_Itemp63);
	_Itemp64 = hello3->self != ((void *)0);
	if ( _Itemp64 )
		goto label19;
	else
		goto label22;
label19: (void)0;
	_Itemp65 = (struct _Pshadow_Pstandard_CObject*)hello3->self;
	_Itemp66 = _Itemp65->_Imethods->_MtoString(_Itemp65);
	_Itemp67 = (struct _Pshadow_Pstandard_CString*)_Itemp66;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(_Itemp67);
	_Itemp68 = hello4->self != ((void *)0);
	if ( _Itemp68 )
		goto label20;
	else
		goto label22;
label20: (void)0;
	_Itemp69 = hello4->self->self != ((void *)0);
	if ( _Itemp69 )
		goto label21;
	else
		goto label22;
label21: (void)0;
	_Itemp70 = (struct _Pshadow_Pstandard_CObject*)hello4->self->self;
	_Itemp71 = _Itemp70->_Imethods->_MtoString(_Itemp70);
	_Itemp72 = (struct _Pshadow_Pstandard_CString*)_Itemp71;
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(_Itemp72);
	_Pshadow_Pio_CConsole_MprintLine();
	goto label23;
label22: (void)0;
	static struct _IArray _Iarray23 = {
		(void *)"NullPointerException!", (int_shadow_t)1, {(int_shadow_t)21}
	};
	static struct _Pshadow_Pstandard_CString _Istring23 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray23
	};
	_Pshadow_Pio_CConsole_MprintLine_R_F_Pshadow_Pstandard_CString(&_Istring23);
	goto label23;
label23: (void)0;
	return;
}

void _Pshadow_Phello_CHelloWorld_Mconstructor(struct _Pshadow_Phello_CHelloWorld* this) {
	this->_Imethods = &_Pshadow_Phello_CHelloWorld_Imethods;
	static struct _IArray _Iarray24 = {
		(void *)"Hello World!", (int_shadow_t)1, {(int_shadow_t)12}
	};
	static struct _Pshadow_Pstandard_CString _Istring24 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray24
	};
	this->message = &_Istring24;
	this->times = ((uint_shadow_t)5);
	this->self = ((void *)0);
	this->self = this;
	this->times = ((uint_shadow_t)5);
	static struct _IArray _Iarray25 = {
		(void *)"Hello World!", (int_shadow_t)1, {(int_shadow_t)12}
	};
	static struct _Pshadow_Pstandard_CString _Istring25 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray25
	};
	this->message = &_Istring25;
	return;
}

void _Pshadow_Phello_CHelloWorld_Mconstructor_Ruint(struct _Pshadow_Phello_CHelloWorld* this, uint_shadow_t times) {
	this->_Imethods = &_Pshadow_Phello_CHelloWorld_Imethods;
	static struct _IArray _Iarray26 = {
		(void *)"Hello World!", (int_shadow_t)1, {(int_shadow_t)12}
	};
	static struct _Pshadow_Pstandard_CString _Istring26 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray26
	};
	this->message = &_Istring26;
	this->times = ((uint_shadow_t)5);
	this->self = ((void *)0);
	this->self = this;
	this->times = times;
	static struct _IArray _Iarray27 = {
		(void *)"Hello World!", (int_shadow_t)1, {(int_shadow_t)12}
	};
	static struct _Pshadow_Pstandard_CString _Istring27 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray27
	};
	this->message = &_Istring27;
	return;
}

void _Pshadow_Phello_CHelloWorld_Mconstructor_R_Pshadow_Pstandard_CString(struct _Pshadow_Phello_CHelloWorld* this, struct _Pshadow_Pstandard_CString* message) {
	this->_Imethods = &_Pshadow_Phello_CHelloWorld_Imethods;
	static struct _IArray _Iarray28 = {
		(void *)"Hello World!", (int_shadow_t)1, {(int_shadow_t)12}
	};
	static struct _Pshadow_Pstandard_CString _Istring28 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray28
	};
	this->message = &_Istring28;
	this->times = ((uint_shadow_t)5);
	this->self = ((void *)0);
	this->self = this;
	this->times = ((uint_shadow_t)5);
	this->message = message;
	return;
}

void _Pshadow_Phello_CHelloWorld_Mconstructor_Ruint_R_Pshadow_Pstandard_CString(struct _Pshadow_Phello_CHelloWorld* this, uint_shadow_t times, struct _Pshadow_Pstandard_CString* message) {
	this->_Imethods = &_Pshadow_Phello_CHelloWorld_Imethods;
	static struct _IArray _Iarray29 = {
		(void *)"Hello World!", (int_shadow_t)1, {(int_shadow_t)12}
	};
	static struct _Pshadow_Pstandard_CString _Istring29 = {
		&_Pshadow_Pstandard_CString_Imethods, (boolean_shadow_t)1, &_Iarray29
	};
	this->message = &_Istring29;
	this->times = ((uint_shadow_t)5);
	this->self = ((void *)0);
	this->self = this;
	this->times = times;
	this->message = message;
	return;
}

struct _Pshadow_Pstandard_CClass* _Pshadow_Phello_CHelloWorld_MgetClass(struct _Pshadow_Phello_CHelloWorld* this) {
	return &_Pshadow_Phello_CHelloWorld_Iclass;
}

struct _Pshadow_Phello_CHelloWorld_Itable _Pshadow_Phello_CHelloWorld_Imethods = {
	_Pshadow_Phello_CHelloWorld_MgetClass,
	_Pshadow_Pstandard_CObject_MtoString,
	_Pshadow_Phello_CHelloWorld_MgetBoth,
	_Pshadow_Phello_CHelloWorld_MgetMessage,
	_Pshadow_Phello_CHelloWorld_Mdoit,
	_Pshadow_Phello_CHelloWorld_MgetTimes,
	_Pshadow_Phello_CHelloWorld_MgetSelfObject,
	_Pshadow_Phello_CHelloWorld_Mfibonacci_Ruint_Ruint,
	_Pshadow_Phello_CHelloWorld_Mmain_R_Pshadow_Pstandard_CString_A1,
};

int main(int argc, char **argv) {
	int i, argsLength = argc - 1; ++argv;
	struct _Pshadow_Pstandard_CString **args = calloc(argsLength, sizeof(struct _Pshadow_Pstandard_CString *));
	for (i = 0; i < argsLength; ++i) {
		struct _Pshadow_Pstandard_CString *arg = malloc(sizeof(struct _Pshadow_Pstandard_CString));
		arg->_Imethods = &_Pshadow_Pstandard_CString_Imethods;
		arg->ascii = ((boolean_shadow_t)1);
		arg->data = malloc(sizeof(struct _IArray));
		arg->data->_Iarray = (void *)argv[i];
		arg->data->_Idims = (int_shadow_t)1;
		arg->data->_Ilengths[0] = strlen(argv[i]);
		args[i] = arg;
	}
	struct _IArray *argsArray = malloc(sizeof(struct _IArray));
	argsArray->_Iarray = (void *)args;
	argsArray->_Idims = 1;
	argsArray->_Ilengths[0] = argsLength;
	_Pshadow_Phello_CHelloWorld_Mmain_R_Pshadow_Pstandard_CString_A1(argsArray);
	return 0;
}

