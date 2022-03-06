#pragma once
#include <string>
#include "Heap.h"

typedef HData QData;

class PriorityQueue
{
private:
	Heap* heap;
public:
	PriorityQueue(int size, PriorityComp comp);
	bool IsEmpty();
	void Enqueue(QData data);
	QData Dequeue();
};

