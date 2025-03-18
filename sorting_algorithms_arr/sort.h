#ifndef SORT_H
#define SORT_H

void swap(int *a, int *b);
void bubble_sort(int a[], int len);
void bubble_sort_opt(int a[], int len);
void bubble_sort_recurs(int a[], int len);
void insertion_sort(int a[], int len);
void heap_sort(int a[], int len);
void quick_sort(int a[], int low, int high);
void selection_sort(int a[], int len);
void shaker_sort(int a[], int len);
void merge_sort(int a[], int left, int right);

#endif
