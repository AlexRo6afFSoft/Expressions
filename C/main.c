#include <stdio.h>
#include <stdlib.h>
#include "OOP/Facade/facade.h"

void* plus (void* a, void* b)
{
	int A = *((int*)a);
	int B = *((int*)b);
	int* C = malloc (sizeof (int));
	(*C) = A + B;
	return (void*)(C);
}

int main (int agrs, char** argc)
{
	addOp (plus);
	int a = 1, b = 2;
	printf ("%d", *((int*)(getOp (0)(&a, &b))));
	return 0;
}
