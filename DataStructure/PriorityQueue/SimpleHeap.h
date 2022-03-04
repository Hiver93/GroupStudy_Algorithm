#pragma once
#include <iostream>

typedef int Priority;
typedef char HData;

typedef struct _heapElem{
	Priority pr;
	HData data;
}HeapElem;
class SimpleHeap
{
private:
	int numOfData;
	int size;
	HeapElem* heapArr;
	int GetParentIdx(int idx);
	int GetLChildIdx(int idx);
	int GetRChildIdx(int idx);
	int GetHiPriChildIdx(int idx);
public:
	SimpleHeap(int size);
	bool IsEmpty();
	void Insert(HData data, Priority pr);
	HData Delete();
};


