#pragma once
#include <iostream>

typedef std::string HData;
typedef bool (*PriorityComp)(HData d1, HData d2);

class Heap
{
private:
	int numOfData;
	int size;
	HData* heapArr;
	PriorityComp comp;
	int GetParentIdx(int idx);
	int GetLChildIdx(int idx);
	int GetRChildIdx(int idx);
	int GetHiPriChildIdx(int idx);
public:
	Heap(int size, PriorityComp comp);
	bool IsEmpty();
	void Insert(HData data);
	HData Delete();
};

