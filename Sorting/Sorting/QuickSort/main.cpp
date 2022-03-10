#include<iostream>

void Swap(int* arr, int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int low = left+1;
	int high = right;
	int pivot = arr[left];

	int i = left;
	while (low <= high)
	{
		while (arr[low] <= pivot && low <= right)
		{
			low++;
		}
		while (arr[high] >= pivot && high >= left+1)
		{
			high--;
		}
		if(low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	QuickSort(arr, left, high - 1);
	QuickSort(arr, high + 1, right);
}

int main()
{
	//int arr[7] = {3,2,4,1,7,6,5};
	int arr[3] = { 3,3,3 };
	int len = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, len-1);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	
}