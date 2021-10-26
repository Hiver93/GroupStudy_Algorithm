#include "pch.h"

class Token
{
public:
	bool isNumber = 0;
	double token = 0;
	Token() {}
	Token(char data)
	{
		token = data;
	}
	Token(double data)
	{
		token = data;
		isNumber = 1;
	}
};

// CreateNewNode 노드 생성 함수
// RemoveNode 노드 삭제 함수
// Push 원소 삽입 함수
// Pop 원소 삭제 및 반환 함수
// GetCount 원소 개수 반환 함수
class ArrayStack
{
private:
	int _capacity;
	int top = -1;
	std::vector<Token*> nodeList;

public:
	ArrayStack(int capacity)
	{
		_capacity = capacity;
		nodeList.resize(capacity);
	}

	Token* CreateNewNode(double data)
	{
		return new Token(data);
	}

	Token* CreateNewNode(char data)
	{
		return new Token(data);
	}

	void RemoveNode(int index)
	{
		delete nodeList[index];
		nodeList[index] = nullptr;
	}

	void Push(double data)
	{
		top++;
		nodeList[top] = CreateNewNode(data);
	}
	void Push(char data)
	{
		top++;
		nodeList[top] = CreateNewNode(data);
	}

	double Pop()
	{
		double returnData = nodeList[top]->token;
		RemoveNode(top);
		top--;
		return returnData;
	}

	int GetCount()
	{
		return top + 1;
	}

	~ArrayStack() // 포인터를 널값으로 바꿀 필요가 없기 때문에 delete만 이용하여 제거
	{
		while (0 <= top)
		{
			delete nodeList[top];
			top--;
		}
	}
};

class Calculator
{
private:
	bool IsNumber(char currentChar)
	{
		if ('0' <= currentChar && currentChar <= '9')
		{
			return true;
		}

		return false;
	}

	int Sizing(const char* charArr)
	{
		int i = 0;
		while (charArr[i] != '\0')
		{
			i++;
		}
		return i + 1;
	}

	double Operate(double oper, double data1, double data2)
	{
		if (oper == (double)'+')
		{
			return data1 + data2;
		}
		if (oper == (double)'-')
		{
			return data1 - data2;
		}
		if (oper == (double)'*')
		{
			return data1 * data2;
		}
		if (oper == (double)'/')
		{
			return data1 / data2;
		}
	}

public:
	std::vector<Token*> tokenList;

	bool IsRightData()
	{
		int operCount = 0;
		int numberCount = 0;
		int i = 0;

		return true;
	}

	void SetToken(const char* inputData)
	{
		for (int i = 0; i < tokenList.size(); i++)
		{
			delete tokenList[i];
			tokenList[i] = nullptr;
		}
		tokenList.clear();
		tokenList.resize(Sizing(inputData));

		int i = 0;
		int index = 0;
		while (inputData[i] != '\0')
		{
			if (IsNumber(inputData[i]))
			{
				double temp = 0;
				double decimalCount = 10;
				while (('0' <= inputData[i] && inputData[i] <= '9') || inputData[i] == '.')
				{
					if (inputData[i] == '.')
					{
						i++;
						while ('0' <= inputData[i] && inputData[i] <= '9')
						{
							temp += ((inputData[i] - (double)'0') / decimalCount);
							decimalCount *= 10;
							i++;
						}
					}
					else
					{
						temp *= 10;
						temp += (inputData[i] - (double)'0');
						i++;
					}
				}
				tokenList[index] = new Token(temp);
				index++;
			}
			if ('*' <= inputData[i] && inputData[i] <= '/'|| inputData[i] == '(' || inputData[i] == ')')
			{
				tokenList[index] = new Token(inputData[i]);
				index++;
				i++;
			}
			if(inputData[i] == ' ')
			{
				i++;
			}
		}

	}

	void Calculate(const char* inputData)
	{
		SetToken(inputData);
		int i = 0;
		ArrayStack arrStack = ArrayStack(tokenList.size());
		while (tokenList[i] != nullptr)
		{
			if (tokenList[i]->isNumber)
			{
				arrStack.Push(tokenList[i]->token);
				i++;
			}
			else
			{
				if (arrStack.GetCount() < 2)
				{
					std::cout << "오류 : 잘못된 계산식입니다." << std::endl;
					return;
				}
				else
				{
					double data1 = arrStack.Pop();
					double data2 = arrStack.Pop();
					arrStack.Push(Operate(tokenList[i]->token, data2, data1));
					i++;
				}
			}
		}
		if (arrStack.GetCount() != 1)
		{
			std::cout << "오류 : 잘못된 계산식입니다." << std::endl;
		}
		else
			std::cout << arrStack.Pop() <<std::endl;
	}

	void GetPostfix(const char* inputData)
	{
		SetToken(inputData);	    
		int i = 0;
		int isPrepared = 0;
		int but = 0;
		ArrayStack arrStack = ArrayStack(tokenList.size());
		while (tokenList[i] != nullptr)
		{
			if (tokenList[i]->isNumber)
			{
				std::cout << tokenList[i]->token << " ";
				if (isPrepared&&!but)
				{
					std::cout << (char)arrStack.Pop() << " ";
					isPrepared--;
				}
				i++;
			}
			else
			{
				if(tokenList[i]->token == '*'|| tokenList[i]->token == '/')
				{
					arrStack.Push((char)tokenList[i]->token);
					isPrepared++;
				}
				else if (tokenList[i]->token == ')')
				{
					char temp;
					while (1)
					{
						temp = (char)arrStack.Pop();
						if (temp == '(')
						{
							but--;
							if (isPrepared)
							{
								std::cout << (char)arrStack.Pop() << " ";
							}
							break;
						}
						std::cout << temp << " ";
					}
				}
				else
				{
					if ((char)tokenList[i]->token == '(')
					{
						but++;
					}
					arrStack.Push((char)tokenList[i]->token);
				}
				i++;
			}
		}
		while(arrStack.GetCount() != 0)
		{
			std::cout << (char)arrStack.Pop() << " ";
		}

	}

	~Calculator()
	{
		for (int i = 0; i < tokenList.size(); i++)
		{
			delete tokenList[i];
		}
	}
};




int main()
{
	char arr[30] = "12 2 3 + +";
	Calculator cal = Calculator();
	cal.Calculate(arr);
	char arr2[30] = "12 + 3 * (4 + 2) / 1.58";

	cal.GetPostfix(arr2);

	return 0;
}