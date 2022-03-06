#include <iostream>
//#include "SimpleHeap.h"
#include "Heap.h"
bool compare(const char* str1, const char* str2);
bool compare1(char a, char b);
int main()
{
	
	// Simple Heap
	{
		//SimpleHeap heap(100);

		//heap.Insert('a', 1);
		//heap.Insert('b', 2);
		//heap.Insert('c', 3);
		//printf("%c \n", heap.Delete());

		//heap.Insert('A', 1);
		//heap.Insert('B', 2);
		//heap.Insert('C', 3);
		//printf("%c \n", heap.Delete());

		//while (!heap.IsEmpty())
		//	printf("%c \n", heap.Delete());

		//return 0;
	}

	// UsefulHeap
	{
		Heap heap(100,compare1);

		heap.Insert('A');
		heap.Insert('B');
		heap.Insert('C');
		std::cout << heap.Delete();

		heap.Insert('A');
		heap.Insert('B');
		heap.Insert('C');
		std::cout << heap.Delete();

		while(!(heap.IsEmpty()))
		{
			std::cout << heap.Delete();
		}

	}
}

bool compare1(char a, char b)
{
	if (a < b)
		return 1;
	return 0;
}

bool compare(const char* str1, const char* str2)
{
	if (strlen(str1) == strlen(str2))
	{
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] == str2[i])
				continue;
			if (str1[i] < str2[i])
				return 1;
			else
				return 0;
		}
		return 0;
	}
	else if (strlen(str1) < strlen(str2))
	{
		return 1;
	}
	else
		return 0;

}