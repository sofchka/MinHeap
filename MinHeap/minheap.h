#ifndef LIB_H
# define LIB_H

//libraries
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# define N 31

//struct
typedef struct _MinHeap
{
	int size;
	int *array;
	int capacity;
} MinHeap;

//functions
void unitHeap(MinHeap **h, int cap);
void myPush(MinHeap *h, int FillNum);
void print(MinHeap *a);
int getmin(MinHeap *a);
int getmax(MinHeap *a);
void myPop(MinHeap *h);
void myRemove(MinHeap *h, int i);

#endif
