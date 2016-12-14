#include <iostream>
#include <stdlib.h>
using namespace std;

class PrimeNumbersUntil_n {
public:
	PrimeNumbersUntil_n(int number);
	~PrimeNumbersUntil_n();
	int findPrimeNumbers();
	void printPrimeNumbers();
private:
	int* data;
	int count;
	int number;
};

PrimeNumbersUntil_n::PrimeNumbersUntil_n(int num)
{
	number = num;
	data = new int[number / 2];
}

PrimeNumbersUntil_n::~PrimeNumbersUntil_n()
{
	delete[] data;
}


int PrimeNumbersUntil_n::findPrimeNumbers()
{
	int count = 0;
	for (int i = 2; i <= number; i++)
	{
		//i-t vizsgáljuk, hogy prím-e?
		int j;
		for (j = 2; j <= i / 2; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j>i / 2)
		{
			data[count] = i;
			count++;
		}
	}
	for (int i = 0; i<count; i++)
	{
		cout << data[i] << endl;
	}
	return count;
}


void PrimeNumbersUntil_n::printPrimeNumbers()
{
	for (int i = 0; i<count; i++)
	{
		cout << data[i] << endl;
	}
}


int main(int argc, const char* argv[])
{
	int a = atoi(argv[1]); //because the first command line argument is a char type variable
						   //so we have to convert it to int type by atoi() function 
	PrimeNumbersUntil_n p1(a);
	p1.findPrimeNumbers();
	p1.printPrimeNumbers();
	//system("pause");
	return 0;
}