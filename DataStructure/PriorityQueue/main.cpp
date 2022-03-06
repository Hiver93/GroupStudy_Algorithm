#include <iostream>
#include <string>
//#include "SimpleHeap.h"
//#include "Heap.h"
#include "PriorityQueue.h"
bool compare(std::string str1, std::string str2);
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
		//Heap heap(100,compare1);

		//heap.Insert('A');
		//heap.Insert('B');
		//heap.Insert('C');
		//std::cout << heap.Delete();

		//heap.Insert('A');
		//heap.Insert('B');
		//heap.Insert('C');
		//std::cout << heap.Delete();

		//while(!(heap.IsEmpty()))
		//{
		//	std::cout << heap.Delete();
		//}
		//Heap heap(100, compare);

		//heap.Insert("abc");
		//heap.Insert("def");
		//heap.Insert("de");
		//std::cout << heap.Delete();

		//heap.Insert("abc");
		//heap.Insert("def");
		//heap.Insert("de");
		//std::cout << heap.Delete();

		//while (!(heap.IsEmpty()))
		//{
		//	std::cout << heap.Delete()<<std::endl;
		//}

	}

	// PriorityQueue
	{
		PriorityQueue pQ(100, compare);

		pQ.Enqueue("abc");
		pQ.Enqueue("def");
		pQ.Enqueue("de");
		std::cout << pQ.Dequeue();

		pQ.Enqueue("abc");
		pQ.Enqueue("def");
		pQ.Enqueue("de");
		std::cout << pQ.Dequeue();

		while (!(pQ.IsEmpty()))
		{
			std::cout << pQ.Dequeue() << std::endl;
		}
	}
}

bool compare1(char a, char b)
{
	if (a < b)
		return 1;
	return 0;
}

bool compare(std::string str1, std::string str2)
{
	if (str1.length() == str2.length())
	{
		for (int i = 0; i < str1.length(); i++)
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
	else if (str1.length() < str2.length())
	{
		return 1;
	}
	else
		return 0;

}