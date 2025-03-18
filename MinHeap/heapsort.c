#include <stdio.h>
#include <stdlib.h>


void print(int a[], int size);


void make_heap(int a[], int size, int i)
{
	while(1)
	{
		int max = i;

		int child_1 = 2 * i + 1;
		int child_2 = 2 * i + 2;
		if (child_1 < size && a[child_1] > a[i])
		{
			max = child_1;
		}
		if (child_2 < size && a[child_2] > a[max])
		{
			max = child_2;
		}
		if (max != i)
		{
			int temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
		else
		{
			break;
		}
		i = max;
	}
}

void make_sort(int a[], int size)
{
	for (int i = size - 1; i > 0; --i)
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		
		make_heap(a, i, 0);
	}
}

void print(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = {2, 5, 8, 1, 10, 25, 9,  7};
	int size = sizeof(a) / sizeof(a[0]);

	print(a, size);

	for (int i = size / 2 - 1; i >= 0; --i)
	{
		make_heap(a, size, i);
	}

	print(a, size);

	make_sort(a, size);

	print(a, size);
}
