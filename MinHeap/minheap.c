#include "minheap.h"

//min num in min heap
int getmin(MinHeap *a)
{
	if (a->size == 0)
	{
		printf("Heap is empty.\n");
		return (-1);
	}
	return (a->array[0]);
}

//max num in min heap
int getmax(MinHeap *a)
{
	if (a->size == 0)
	{
		printf("Heap is empty.\n");
		return -1;
	}
	int start = a->size / 2;
	int max = a->array[start];
	for (int i = start + 1; i < a->size; ++i)
	{
		if (a->array[i] > max)
			max = a->array[i];
	}
	return (max);
}

//the empty array with malloc
void unitHeap(MinHeap **h, int cap)
{
	*h = malloc(sizeof(MinHeap));
	if (*h == NULL)
		return;

	(*h)->capacity = cap;
	(*h)->size = 0;
	(*h)->array = malloc((*h)->capacity * sizeof(int));
	
	if ((*h)->array == NULL)
	{
		free(*h);
		return;
	}
}

//minheap filling with a new number
void myPush(MinHeap *h, int FillNum)
{
	if (h->size >= h->capacity) //check if it's the end of heap capacity
		return;

	int hole = h->size++; //new hole for the num
	for (; hole > 0 && FillNum < h->array[(hole - 1)/2]; hole = (hole - 1) / 2) //check if the num is > than parent
	{
		h->array[hole] = h->array[(hole - 1)/2]; //if yes swap parent -> down
	}
	h->array[hole] = FillNum;
}

//removing an element from minheap
void myRemove(MinHeap *h, int i)
{
	if (h->size == 0)
	{
		printf("Heap is empty.\n");
		return;
	}
	if (h->size < i)
	{
		printf("No such element.\n");
		return;
	}

	h->array[i] = h->array[h->size - 1];
	h->size--;

	while(1)
	{
		int left = i * 2 + 1;
		int right = i * 2 + 2;
		int min = i;

		if (left < h->size && h->array[left] < h->array[min])
			min = left;
		if (right < h->size && h->array[right] < h->array[min])
			min = right;
		if (min == i)
			break;
		int tmp = h->array[i];
		h->array[i] = h->array[min];
		h->array[min] = tmp;
		i = min;
	}
}

//poping the first element from minheap
void myPop(MinHeap *h)
{
	myRemove(h, 0);
}

int rows(MinHeap *a)
{
	int rows = 0;
	int num = a->size;
	while(num >>= 1) //finding log2
	{
		rows++;
	}
	return (rows + 1); //+1 for last not complete line
}

//printing the lines with numbers
void printLayer(int elements, MinHeap *a, int *index, int spaces, int inner)
{
	for (int k = 0; k < spaces; k++)
		printf(" ");

	for (int k = 0; k < elements; k++)
	{
		if (*index < a->size)
		{
			printf("%2d", a->array[*index]); //%2d for numbers [0, 99]
			(*index)++;
			}
		else
			printf("  ");
		if (k < elements - 1)
		{
			for (int l = 0; l < inner; l++)
				printf(" ");
		}
	}
	printf("\n");
}

//printing the lines with branches
void printBranch(int elements, int max, int spaces, int inner)
{
	for (int k = 0; k < spaces - 1; k++)
		printf(" ");

	for (int k = 0; k < elements && max > 1; k++) //max is for the last not complete line
	{
		printf("/  \\");
		for (int l = 0; l < inner - 2; l++)
			printf(" ");
		max -= 2;
	}
	if (max == 1) //single branch
		printf("/");
	printf("\n");
}

//full heap printing function
void print(MinHeap *a)
{
	int row = rows(a);
	int len = pow(2, row - 1);
	len = len * 2 + 2 * (len - 1); //the full lenght
	int index = 0; //to not over print
	int count = 0; //number of elements we printed FOR the last not complete line

	for (int j = 0; j < row; ++j)
	{
		int elements = pow(2, j);
		int inner = (len - elements * 2 + 2) / elements;
		int spaces = (inner > 2) ? (inner - 2) / 2 : 0; //for first & Last lines where is no inner/spaces

		printLayer(elements, a, &index, spaces, inner);
		
		if (j != row - 1) //branches till The second-to-last line
		{
			count += elements; //printed numbers count
			int max = pow(2, j + 1); //next line's max elements
			if (j == row - 2) //if it's The second-to-last line
				max = a->size - count; //max elements of the next line
			printBranch(elements, max, spaces, inner);
		}
	}
 printf("Minimum element is: %d\n", getmin(a));
			printf("Maximum element is: %d\n", getmax(a));
}
