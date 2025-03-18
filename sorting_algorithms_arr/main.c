// Mini Tester

#include <stdio.h>
#include "sort.h"

void quick_sort_wrapper(int a[], int len)
{
    quick_sort(a, 0, len - 1);
}

void merge_sort_wrapper(int a[], int len)
{
    merge_sort(a, 0, len - 1);
}

void print(int a[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void test_sorting_algorithm(void (*sort_func)(int[], int), const char* name)
{
    printf("%s:\n", name);

    int a1[] = {110, 0, 1, 21, 12, 33333, -1, -1};
    int len1 = sizeof(a1) / sizeof(a1[0]);
    printf("Before: ");
    print(a1, len1);
    sort_func(a1, len1);
    printf("After: ");
    print(a1, len1);
    printf("\n");
}

int main()
{
    test_sorting_algorithm(bubble_sort, "Bubble Sort");
    test_sorting_algorithm(insertion_sort, "Insertion Sort");
    test_sorting_algorithm(heap_sort, "Heap Sort");
    test_sorting_algorithm(quick_sort_wrapper, "Quick Sort");
    test_sorting_algorithm(selection_sort, "Selection Sort");
    test_sorting_algorithm(shaker_sort, "Shaker Sort");
    test_sorting_algorithm(merge_sort_wrapper, "Merge Sort");
    test_sorting_algorithm(bubble_sort_opt, "Bubble Sort Opt");
    test_sorting_algorithm(bubble_sort_recurs, "Bubble Sort Recurs");

    return 0;
}
