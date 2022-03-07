#include <iostream>

typedef bool (*compare)(int a, int b);
bool Compare(int a, int b);
void HeapSort(int* arr, int n, compare comp)
{
	int* heap = new int[n+1];
	for (int i = 0; i < n; i++)
	{		
		int idx = i + 1;
		while (idx > 1)
		{
			if (comp(heap[idx / 2], arr[i]))
				break;
			heap[idx] = heap[idx / 2];
			idx /= 2;
		}
		heap[idx] = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		arr[i] = heap[1];
		int temp = heap[n - i];
		int idx = 1;
		while (1)
		{
			if (idx * 2 < n - i - 1)
			{
				if (comp(heap[idx * 2], heap[idx * 2 + 1]))
				{
					if (comp(heap[idx * 2], temp))
					{
						heap[idx] = heap[idx * 2];
						idx *= 2;
					}
					else
						break;
				}
				else
				{
					if (comp(heap[idx * 2+1], temp))
					{
						heap[idx] = heap[idx * 2+1];
						idx = idx * 2 + 1;
					}
					else
						break;
				}
			}
			else if (idx * 2 == n - i - 1)
			{
				if (comp(heap[idx * 2], temp))
				{
					heap[idx] = heap[idx * 2];
					idx *= 2;
				}
				else
					break;
			}
			else
				break;
		}
		heap[idx] = temp;
	}
	delete[] heap;
}

int main()
{
	int arr[10] = { 2,5,8,6,3,1,77,12,7,10 };

	HeapSort(arr, 10, Compare);

	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << ' ';
}

bool Compare(int a, int b)
{
	if (a < b)
		return 1;
	return 0;
}