#pragma once
#include <vector>
#include<iostream>
#include"Equation.h"
using namespace std;

class MyEquations
{
private:
	vector <Equation> myEquations;
public:
	void insertNewEquation(Equation x);
	void swapEquations(int i, int j);
	void Display();
	vector<float> solveSystem();
	MyEquations();
	~MyEquations();
};

