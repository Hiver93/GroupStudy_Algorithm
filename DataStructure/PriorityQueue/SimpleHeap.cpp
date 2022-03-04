#include "SimpleHeap.h"

SimpleHeap::SimpleHeap(int size)
{
	numOfData = 0;
	heapArr = new HeapElem[size + 1];
	this->size = size;
}
bool SimpleHeap::IsEmpty()
{
	return !numOfData;
}
void SimpleHeap::Insert(HData data, Priority pr)
{
	int idx = ++numOfData;
	if (size < numOfData)
	{
		std::cout << "범위 초과";
		exit(0);
	}
	HeapElem elem = { pr,data };
	while (idx != 1)
	{
		if (heapArr[GetParentIdx(idx)].pr >= pr)
		{
			heapArr[idx] = heapArr[GetParentIdx(idx)];			
			idx = GetParentIdx(idx);
		}
		else
			break;
	}
	heapArr[idx] = elem;
}
HData SimpleHeap::Delete()
{
	HData retData = heapArr[1].data;
	int idx = 1;
	HeapElem elem = heapArr[numOfData--];
	while (GetHiPriChildIdx(idx) && heapArr[GetHiPriChildIdx(idx)].pr < elem.pr)
	{
		heapArr[idx] = heapArr[GetHiPriChildIdx(idx)];
		idx = GetHiPriChildIdx(idx);
	}
	heapArr[idx] = elem;
	return retData;
}
int SimpleHeap::GetParentIdx(int idx)
{
	return idx / 2;
}
int SimpleHeap::GetLChildIdx(int idx)
{
	return idx * 2;
}
int SimpleHeap::GetRChildIdx(int idx)
{
	return idx * 2 + 1;
}
int SimpleHeap::GetHiPriChildIdx(int idx)
{
	if (idx * 2 < numOfData)
	{
		if (heapArr[GetLChildIdx(idx)].data < heapArr[GetRChildIdx(idx)].data)
			return idx * 2;
		else
			return idx * 2 + 1;
	}
	else if (idx * 2 == numOfData)
		return idx * 2;
	return 0;
}