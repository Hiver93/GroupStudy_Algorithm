#include <iostream>

int* MyMergeSort(int* arr3, int n)
{
	if (n == 1)
	{
		int* arr = new int[n];
		arr[0] = arr3[0];
		return arr;
	}

	int* arr1 = MyMergeSort(arr3, n / 2);
	int* arr2 = MyMergeSort(arr3 + n / 2, n / 2 + n % 2);
	int* arr = new int[n];
	int i1 = 0;
	int i2 = 0;
	while (i1 != n/2&&i2!=n/2+n%2)
	{
		if (arr1[i1] <= arr2[i2])
		{
			arr[i1+i2] = arr1[i1];
			i1++;
		}
		else
		{
			arr[i1+i2] = arr2[i2];
			i2++;
		}
	}
	if (i1 == n / 2)
	{
		while (i2 != n / 2 + n % 2)
		{
			arr[i1 + i2] = arr2[i2];
			i2++;
		}
	}
	else
	{
		while(i1 != n / 2)
		{
			arr[i1 + i2] = arr1[i1];
			i1++;
		}
	}
	delete[] arr1;
	delete[] arr2;
	return arr;
}

void MergeTwoArea(int* arr, int left, int mid, int right)
{
	int idx1 = left;
	int idx2 = mid + 1;
	int i;
	
	int* sortArr = new int[right + 1];

	int idx = left;
	while (idx1 <= mid && idx2 <= right)
	{
		if (arr[idx1] <= arr[idx2])
		{
			sortArr[idx] = arr[idx1++];
		}
		else
			sortArr[idx] = arr[idx2++];
		idx++;
	}

	if (idx1 > mid)
	{
		for (i = idx2; i <= right; i++, idx++)
			sortArr[idx] = arr[i];
	}
	else
	{
		for (i = idx1; i <= mid; i++, idx++)
			sortArr[idx] = arr[i];
	}
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	delete[] sortArr;
}

void MergeSort(int* arr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

int main()
{
	{
		//int n;
		//std::cin >> n;
		//int* arr = new int[n];
		//for (int i = 0; i < n; i++)
		//{
		//	std::cin >> arr[i];
		//}

		//int* arr1 = MyMergeSort(arr, n);

		//for (int i = 0; i < n; i++)
		//{
		//	std::cout << arr1[i] << '\n';
		//}
	}
	int arr[7] = { 3,2,4,1,7,6,5 };
	int i;

	MergeSort(arr, 0, 6);

	for (i = 0; i < 7; i++)
	{
		std::cout << arr[i] << ' ';
	}

	return 0;
}