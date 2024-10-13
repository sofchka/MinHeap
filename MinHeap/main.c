#include "minheap.h"

int main()
{
	srand(time(NULL));

	MinHeap *a;
	unitHeap(&a, N);

	if (a != NULL)
	{
		int size = rand() % N + 1;
		for (int i = 0; i < size; ++i)
			myPush(a, rand() % 100);
		if (a->array != NULL) //if rand and push worked well
		{
			printf("Min Heap elements:\n");
			print(a);
			printf("\nMinimum element is: %d\n", getmin(a));
			printf("Maximum element is: %d\n", getmax(a));
			printf("After Poping the first element:\n");
			myPop(a);
			print(a);
			printf("\nMinimum element is: %d\n", getmin(a));
			printf("Maximum element is: %d\n", getmax(a));
			int index;
			printf("Put index to remove: ");
			scanf("%d", &index);
			printf("After Removeing the [%d] element:\n", index);
			myRemove(a, index);
			print(a);
			printf("Minimum element is: %d\n", getmin(a));
			printf("Maximum element is: %d\n", getmax(a));
		}
		else
			printf("The min heap is empty.\n");
		free(a->array);
		free(a); //free malloc
	}
	return (0);
}
