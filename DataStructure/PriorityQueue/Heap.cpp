#include "Heap.h"

int Heap::GetHiPriChildIdx(int idx)
{
	if (GetLChildIdx(idx) < numOfData)
	{
		if (comp(heapArr[GetLChildIdx(idx)], heapArr[GetRChildIdx(idx)]))
		{
			return GetLChildIdx(idx);
		}
		else
			return GetRChildIdx(idx);
	}
	else if (GetLChildIdx(idx) == numOfData)
		return GetLChildIdx(idx);
	return 0;
}

Heap::Heap(int size, PriorityComp comp)
{
	this->comp = comp;
	numOfData = 0;
	heapArr = new HData[size + 1];
	this->size = size;
}
bool Heap::IsEmpty()
{
	return !numOfData;
}
void Heap::Insert(HData data)
{
	int idx = ++numOfData;
	if (size < numOfData)
	{
		std::cout << "범위 초과";
		exit(0);
	}
	HData elem;	
	elem = data;
	while (idx != 1)
	{
		if (comp(elem,heapArr[GetParentIdx(idx)]))
		{
			heapArr[idx] = heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else
			break;
	}
	heapArr[idx] = elem;	
}
HData Heap::Delete()
{
	HData retData;
	retData = heapArr[1];
	int idx = 1;
	HData elem;
	elem = heapArr[numOfData--];	
	while (GetHiPriChildIdx(idx) && comp(heapArr[GetHiPriChildIdx(idx)],elem))
	{		
		heapArr[idx] = heapArr[GetHiPriChildIdx(idx)];
		idx = GetHiPriChildIdx(idx);
	}
	heapArr[idx] = elem;	
	return retData;
}
int Heap::GetParentIdx(int idx)
{
	return idx / 2;
}
int Heap::GetLChildIdx(int idx)
{
	return idx * 2;
}
int Heap::GetRChildIdx(int idx)

{
	return idx * 2 + 1;
}