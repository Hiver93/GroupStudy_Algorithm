#include "BurgerSim.h"

BurgerSim::BurgerSim(int size)
{
	waiting = new MyQueue(size);
	this->size = size;
}
BurgerSim::~BurgerSim()
{
	delete waiting;
}

void BurgerSim::PrintResult()
{
	printf("Simulate Result\n");
	printf("Cheese Burger : %d\n", cheOrder);
	printf("Bul Burger : %d\n", bulOrder);
	printf("Double Burger : %d\n", dubOrder);
	printf("Waiting Room size : %d\n", size);
}

bool BurgerSim::Simulate()
{
	for (int i = 0; i < 3600; i++)
	{
		if (i % 15 == 0)
		{
			if (waiting->IsFull())
			{
				cout << "대기열 초과" << endl;
				waiting->Reset();
				return false;
			}
			switch (rand() % 3)
			{
			case che:
			{
				waiting->Enqueue(CHE_TURM); 
				cheOrder++;
				break;
			}
			case bul:
			{
				waiting->Enqueue(BUL_TURM); 
				bulOrder++;
				break;
			}
			case dub:
			{
				waiting->Enqueue(DUB_TURM);
				dubOrder++;
				break;
			}
			default:
				break;
			}
		}

		if (makeProc <= 0 && !waiting->IsEmpty())
		{
			makeProc = waiting->Dequeue();
		}

		makeProc--;
	}
	PrintResult();
	waiting->Reset();
	return true;
}