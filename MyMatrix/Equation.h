#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Equation
{
private:
	int numberOfCoefficients;
	vector<float> LHS;
	float RHS;
public:
	int getNnumberOfCoefficients();
	vector<float> getLHS();
	float getSpecificCoefficient(int x);
	float getRHS();
	void display();
	Equation(int n,vector<float> lhs,float rhs);
	~Equation();
};

