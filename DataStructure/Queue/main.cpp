#include <iostream>
#include "MyQueue.h"

int main()
{
	MyQueue* Q = new MyQueue(3);
	Q->Enqueue(1);
	Q->Enqueue(2);
	Q->Enqueue(3);
	/*std::cout << Q->Dequeue() << ' ';
	std::cout << Q->Dequeue() << ' ';
	std::cout << Q->Dequeue() << ' ';*/
	Q->PrintAll();
	Q->Dequeue();
	Q->PrintAll();
	if (Q->IsEmpty())
	{
		std::cout << "empty";
	}
	else
		std::cout << "not empty";
    
	return 0;
}