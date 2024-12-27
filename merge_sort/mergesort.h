#pragma once
#include "stdlib.h"


typedef struct _lel* LEptr;

struct _lel {
	int data;
	LEptr next;
};

LEptr mergesort(LEptr first);

LEptr strip_monoprefix(LEptr first);

LEptr merge_monotonic(LEptr L, LEptr R);