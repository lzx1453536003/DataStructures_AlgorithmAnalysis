#include<iostream>

using namespace std;


void main()
{
	int a[] = { 15, 22, 35, 9, 23, 16, 33, 15, 23, 68, 1, 33, 25, 14 };


	/*void quick_sort(int array[], int left_index, int right_index);
	quick_sort(a, 0, 13);*/

	/*void bubble_sort(int array[], int len);
	bubble_sort(a, 14);*/

	void merge_sort(int array[], int left_index, int right_index);
	merge_sort(a, 0, 13);

	for (int i = 0; i < 14; i++)
	{
		cout << a[i] << "  ";
	}
	getchar();
}

void bubble_sort(int array[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i; j < len - 1; j++)
		{
			if (array[i] > array[j + 1])
			{
				int temp = array[i];
				array[i] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}


void quick_sort(int array[], int left_index, int right_index)
{
	if (left_index >= right_index)
	{
		return;
	}
	int base_index = left_index;
	int i = base_index + 1;
	int j = right_index;
	while (i < j)
	{
		while (i < j && array[j] >= array[base_index])
			j--;
		while (i < j && array[i] <= array[base_index])
			i++;
		if (j == i)
		{
			break;
		}
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	//此时 i==j
	if (array[i] < array[base_index])
	{
		int temp = array[i];
		array[i] = array[base_index];
		array[base_index] = temp;
		base_index = i;
	}
	else if (array[i] > array[base_index] && i > base_index + 1)
	{
		i--;
		int temp = array[i];
		array[i] = array[base_index];
		array[base_index] = temp;
		base_index = i;
	}

	for (int i = 0; i < 14; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	quick_sort(array, left_index, base_index - 1);
	quick_sort(array, base_index + 1, right_index);


}

void merge_sort(int array[], int left_index, int right_index)
{
	if (left_index >= right_index)
	{
		return;
	}

	//
	int pivot_index = (right_index + left_index) / 2;
	merge_sort(array, left_index, pivot_index);
	merge_sort(array, pivot_index + 1, right_index);

	//merge
	int len = right_index - left_index + 1;
	int i = left_index;
	int j = pivot_index + 1;
	int* temp_array = (int*)malloc(sizeof(int)*len);
	for (int n = 0; n < len; n++)
	{
		if (i < pivot_index + 1 && j < right_index + 1)
		{
			if (array[i] <= array[j])
			{
				temp_array[n] = array[i];
				i++;
			}
			else
			{
				temp_array[n] = array[j];
				j++;
			}
		}
		else if (i < pivot_index + 1 && j > right_index)
		{
			temp_array[n] = array[i];
		}
		else if (i > pivot_index && j < right_index + 1)
		{
			temp_array[n] = array[j];
		}
	}

	for (int n = left_index; n < right_index + 1; n++)
	{
		array[n] = temp_array[n - left_index];
	}

	free(temp_array);

}

void heap_sort(int array[], int start_index, int end_index)
{
	if (start_index >= end_index)
	{
		return;
	}

	void heap_adjust(int array[], int start_index, int end_index);
	heap_adjust(array, start_index, end_index);
	int temp = array[start_index];
	array[end_index] = array[start_index];
	array[start_index] = temp;

	heap_sort(array, start_index, end_index - 1);
}

void heap_adjust(int array[], int start_index, int end_index)
{
	//子节点的位置 = 2 * (parent(父结点)) + 1

	
}