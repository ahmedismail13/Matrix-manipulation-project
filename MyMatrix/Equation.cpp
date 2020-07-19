#include "Equation.h"
#include <iostream>
#include <vector>
using namespace std;


int Equation::getNnumberOfCoefficients()
{
	return numberOfCoefficients;
}

vector<float> Equation::getLHS()
{
	return LHS;
}

float Equation::getSpecificCoefficient(int x)
{
	return LHS[x];
}

float Equation::getRHS()
{
	return RHS;
}
void Equation::display()
{
	for (int i = 0; i < numberOfCoefficients; i++)
	{
		if (i == 0)
		{
			cout << LHS[i] << "x" << i + 1 << " ";
		}
		else
		{
			if (LHS[i] > 0)
				cout << "+ " << LHS[i] << "x" << i + 1 << " ";
			else
				cout << " " << LHS[i] << "x" << i + 1 << " ";
		}
	}
	cout << "= " << RHS << endl;
}
Equation::Equation(int n, vector<float> lhs, float rhs)
{
	numberOfCoefficients = n;
	LHS = lhs;
	RHS = rhs;
}


Equation::~Equation()
{
}
