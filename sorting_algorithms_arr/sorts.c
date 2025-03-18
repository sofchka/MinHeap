void	swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// Bubble Sort
void	bubble_sort(int a[], int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
				swap (&a[j], &a[j + 1]);
		}
	}
}

// Bubble Sort Optimized
void	bubble_sort_opt(int a[], int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int swapped = 0;
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap (&a[j], &a[j + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}

// Bubble Sort Recursive
void	bubble_sort_recurs(int a[], int len)
{
	if (len == 1)
		return ;

	int swapped = 0;
	for (int i = 0; i < len - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			swap(&a[i], &a[i + 1]);
			swapped = 1;
		}
	}
	if (swapped == 0)
		return ;
	bubble_sort_recurs(a, len - 1);
}

// Insertion Sort
void	insertion_sort(int a[], int len)
{
	for (int i = 1; i < len; ++i)
	{
		int tmp = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > tmp)
		{
			a[j] = a[j - 1];
			--j;
		}
		a[j] = tmp;
	}
}

// Heap Sort
void	heap_maker(int a[], int len, int i)
{
	int max = i;
	int child_1 = 2 * i + 1;
	int child_2 = 2 * i + 2;
	if (child_1 < len && a[child_1] > a[max])
		max = child_1;
	if (child_2 < len && a[child_2] > a[max])
		max = child_2;
	if (max != i)
	{
		swap(&a[max], &a[i]);
		heap_maker(a, len, max);
	}
}

void	heap_sort(int a[], int len)
{
	if (len <= 1)
		return ;
	for (int i = len / 2 - 1; i >= 0; --i)
		heap_maker(a, len, i);

	for (int i = len - 1; i > 0; --i)
	{
		swap(&a[0], &a[i]);
		heap_maker(a, i, 0);
	}
}

// Quick Sort
int	split(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low - 1;

	for (int j = low; j < high; ++j)
	{
		if (pivot > a[j])
		{
			i++;
			swap(&a[j], &a[i]);
		}
	}
	i++;
	swap(&a[i], &a[high]);
	return (i);
}

void	quick_sort(int a[], int low, int high)
{
	if (low < high)
	{
		int split_index = split(a, low, high);
		quick_sort(a, low, split_index - 1);
		quick_sort(a, split_index + 1, high);
	}
}

// Selection Sort
void	selection_sort(int a[], int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
			swap(&a[i], &a[min]);
	}
}

// Shaker Sort
void	shaker_sort(int a[], int len)
{
	int left = 0, right = len - 1;
	int sorted;

	do {
		sorted = 0;

		for (int j = left; j < right; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap (&a[j], &a[j + 1]);
				sorted = 1;
			}
		}
		right--;

		for (int j = right; j > left; --j)
		{
			if (a[j] < a[j - 1])
			{
				swap (&a[j], &a[j - 1]);
				sorted = 1;
			}
		}
		left++;
	} while (sorted);
}

// Merge Sort
void	merge(int a[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int arr1[n1], arr2[n2]; // or	//int *arr1 = (int *)malloc(n1 * sizeof(int));
					//int *arr2 = (int *)malloc(n2 * sizeof(int));
	for (int i = 0; i < n1; i++)
		arr1[i] = a[left + i];
	for (int j = 0; j < n2; j++)
		arr2[j] = a[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (arr1[i] <= arr2[j])
			a[k] = arr1[i++];
		else
			a[k] = arr2[j++];
		k++;
	}
	while (i < n1)
		a[k++] = arr1[i++];
	while (j < n2)
		a[k++] = arr2[j++];	//free(arr1);
}					//free(arr2);


void	merge_sort(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);

		merge(a, left, mid, right);
	}
}
