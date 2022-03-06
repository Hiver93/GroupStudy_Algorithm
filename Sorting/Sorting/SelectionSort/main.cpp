#include <iostream>
void SelectionSort(int* arr, int n)
{
	int idx;
	for (int i = 0; i < n; i++)
	{
		idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[idx] > arr[j])
			{
				idx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}

}

int main()
{
	int arr[4] = { 3,4,2,1 };

	SelectionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
	{
		std::cout << arr[i] << ' ';
	}

	return 0;
}
