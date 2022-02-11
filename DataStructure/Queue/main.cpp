#include <iostream>
#include "MyQueue.h"
#include "MyLinkedQueue.h"

int main()
{
	//MyQueue* Q = new MyQueue(3);
	//cout << "Q->Enqueue(1);" << endl;
	//cout << "Q->Enqueue(1);" << endl;
	//cout << "Q->Enqueue(3);" << endl;
	//Q->Enqueue(1);
	//Q->Enqueue(2);
	//Q->Enqueue(3);
	//cout << endl;
	//cout << "Q->PrintAll();" << endl;
	//Q->PrintAll();
	//cout << endl;
	//cout << "Q->Dequeue();" << endl;
	//Q->Dequeue();
	//cout << endl;
	//cout << "Q->PrintAll();" << endl;
	//Q->PrintAll();
	//cout << endl;
	//cout << "Q->Dequeue();" << endl;
	//Q->Dequeue();
	//cout << endl;
	//cout << "IsEmpty?" << endl;
	//if (Q->IsEmpty())
	//{
	//	std::cout << "empty"<<endl;
	//}
	//else
	//	std::cout << "not empty"<<endl;
	//cout << endl;
	//cout << "Q->Dequeue();" << endl;
	//Q->Dequeue();
	//cout << endl;
	//cout << "IsEmpty?" << endl;
	//if (Q->IsEmpty())
	//{
	//	std::cout << "empty" << endl;
	//}
	//else
	//	std::cout << "not empty"<<endl;
	//cout << endl;

	//Q->Enqueue(1);
	//Q->Enqueue(2);
	//Q->Enqueue(3);
	//Q->Reset(2);
	//Q->Enqueue(4);
	//Q->Enqueue(4);
	//Q->Enqueue(4);
	//Q->PrintAll();


	//delete Q;

	MyLinkedQueue* LQ = new MyLinkedQueue();

	LQ->Enqueue(1);
	LQ->Enqueue(2);
	LQ->Enqueue(3);
	LQ->Enqueue(4);

	for (int i = 0; i < 4; i++)
	{
		cout << LQ->Dequeue() << ' ';
	}
	LQ->Enqueue(4);
	LQ->PrintAll();

	return 0;
}