#include <iostream>

void InsertionSort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int data = arr[i];
		int j;
		for (j = i - 1; 0 <= j; j--)
		{			
			if (arr[j] < data)
			{
				break;
			}
			arr[j+1] = arr[j];
		}
		arr[j+1] = data;
	}
}

int main()
{
	int arr[5] = { 5,3,2,4,1 };

	InsertionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << ' ';

	return 0;
}