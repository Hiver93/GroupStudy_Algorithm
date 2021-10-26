#include <iostream>
#include "ArrayStack.h"


// IsNumber 숫자인지 확인하는 함수
// SizingStack char배열에 맞는 사이즈를 반환하는 함수
// Calculate 후위 표기법으로 들어온 char배열을 계산하여 반환하는 함수
// GetPostFix 중위 표기법으로 들어온 char배열을 후위표기법으로 변환하여 출력하는 함수

static class Calculator
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

	int SizingStack(const char* charArr)
	{
		int i = 0;
		while (charArr[i] != '\0')
		{
			i++;
		}

		return i + 1;
	}

public:
	

	double Calculate(const char* inputData)
	{
		int i = 0;

		ArrayStack* arrStack = new ArrayStack(SizingStack(inputData));
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
						temp += ((inputData[i]-(double)'0') / decimalCount);
						decimalCount *= 10;
						i++;
					}
					else
					{
						temp *= 10;
						temp += (inputData[i] - (double)'0');
						i++;
					}					
				}
				arrStack->Push(temp);

			}
			else if ('*' <= inputData[i] && inputData[i] <= '/')
			{
				if (inputData[i] == '+')
				{
					arrStack->Push(arrStack->Pop() + arrStack->Pop());
				}
				else if (inputData[i] == '-')
				{
					arrStack->Push(arrStack->Pop() - arrStack->Pop());
				}
				else if (inputData[i] == '*')
				{
					arrStack->Push(arrStack->Pop() * arrStack->Pop());
				}
				else if (inputData[i] == '/')
				{
					arrStack->Push(arrStack->Pop() / arrStack->Pop());
				}
				i++;
			}
			else
			{
				i++;
			}
			
		}
		double returnValue = arrStack->Pop();
		delete arrStack;
		return returnValue;

	}

	char* GetPostfix(const char* infix)
	{
		char* postfix = new char[SizingStack(infix)];
		ArrayStack* arrStack = new ArrayStack(SizingStack(infix));
		int i = 0;
		int postfixCount = 0;
		bool existSpacing = false;
		while (infix[i] != '\0')
		{
			if (!('0' <= infix[i] && infix[i] <= '9') && infix[i] != '.'&& infix[i] !=' ')
			{				
				if (infix[i] == ')')
				{		
					char temp;
					while(true)
					{
						temp = arrStack->Pop();
						if (temp == '(')
							break;

						*(postfix + postfixCount) = temp;
						postfixCount++;

					}
					i++;
				}
				else
				{
					/*else
					{
						*(postfix + postfixCount) = infix[i];
						postfixCount++;
					}*/
					arrStack->Push(infix[i]);
					i++;
				}
			}
			else
			{
				if (infix[i] == ' ')
				{
					if (!existSpacing)
					{
						*(postfix + postfixCount) = infix[i];
						postfixCount++;
						existSpacing = true;
					}
					else
						existSpacing = false;
				}
				else
				{
					*(postfix + postfixCount) = infix[i];
					postfixCount++;
				}
				i++;
			}
		}
		while (0 < arrStack->GetCount())
		{
			*(postfix + postfixCount) = arrStack->Pop();
			postfixCount++;
		}
		*(postfix + postfixCount) = '\0';

		
		return postfix;
	}
};

int main()
{
	Calculator cal = Calculator();
	char cArr[12] = "1 1.5 3 + *";
	std::cout << cal.Calculate(cArr) << std::endl;

	char* text = cal.GetPostfix("( 10.1 + 2 ) * 2");
	std::cout << text << std::endl;

	std::cout << cal.Calculate(text)<< std::endl;

	delete[] text;

	std::cout << std::endl;
	std::cout << 0;

}