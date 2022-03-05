#include <iostream>
#include "SimpleHeap.h"
typedef SimpleHeap Heap;

int main()
{
	// Simple Heap
	{
		Heap heap(100);

		heap.Insert('a', 1);
		heap.Insert('b', 2);
		heap.Insert('c', 3);
		printf("%c \n", heap.Delete());

		heap.Insert('A', 1);
		heap.Insert('B', 2);
		heap.Insert('C', 3);
		printf("%c \n", heap.Delete());

		while (!heap.IsEmpty())
			printf("%c \n", heap.Delete());

		return 0;
	}
}