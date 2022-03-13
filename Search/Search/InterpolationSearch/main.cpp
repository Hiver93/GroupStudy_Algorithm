#include <iostream>

int ISearch(int* arr, int first, int last, int target)
{
	int mid;

	if (arr[first] > target || arr[last] < target)
		return -1;

	mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return  ISearch(arr, first, mid - 1, target);
	else
		return ISearch(arr, mid + 1, last, target);
}

int main()
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		printf("실패\n");
	else
		printf("저장 인덱스 : %d\n", idx);
	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 10);
	if (idx == -1)
		printf("실패\n");
	else
		printf("저장 인덱스 : %d\n", idx);
	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
	if (idx == -1)
		printf("실패\n");
	else
		printf("저장 인덱스 : %d\n", idx);

	return 0;
}