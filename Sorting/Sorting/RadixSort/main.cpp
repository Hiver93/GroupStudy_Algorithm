#include <iostream>
#include <queue>

void RadixSort(int* arr, int n, int maxLen)
{
	std::queue<int> bucket[10];
	int i, j;

	int div = 1;
	for (i = 0; i < maxLen; i++)
	{
		for (j = 0; j < n; j++)
		{
			bucket[(arr[j] / div) % 10].push(arr[j]);
		}
		div *= 10;
		int count = 0;
		for (j = 0; j < 10; j++)
		{
			while(!bucket[j].empty())
			{
				arr[count++] = bucket[j].front();
				bucket[j].pop();
			}
		}
	}

}

int main()
{
	int arr[5] = { 14,25,68,88,12 };
	RadixSort(arr, 5, 2);

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << ' ';
	}
}