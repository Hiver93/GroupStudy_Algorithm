#pragma once
#include "MyQueue.h"
#include <cstdlib>
#define CHE_TURM 15
#define BUL_TURM 15
#define DUB_TURM 24
enum Burger
{
	che,
	bul,
	dub
};
class BurgerSim
{
private:
	MyQueue* waiting;
	int makeProc = 0;
	int cheOrder=0, bulOrder=0, dubOrder=0;
	int size;
public:
	BurgerSim(int size);
	~BurgerSim();
	bool Simulate();
	void PrintResult();

};

