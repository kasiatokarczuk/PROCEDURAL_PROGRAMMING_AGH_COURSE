#pragma once
#include "stdlib.h"

typedef struct _lel* LEptr;
struct _lel {
	int data;
	LEptr next;
};

LEptr reverse(LEptr first);

LEptr rotate(LEptr first, int step);