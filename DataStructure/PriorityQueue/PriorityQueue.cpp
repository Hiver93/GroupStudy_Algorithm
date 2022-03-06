#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size, PriorityComp comp)
{
	heap = new Heap(size, comp);
}
bool PriorityQueue::IsEmpty()
{
	return heap->IsEmpty();
}
void PriorityQueue::Enqueue(QData data)
{
	heap->Insert(data);
}
QData PriorityQueue::Dequeue()
{
	return heap->Delete();
}