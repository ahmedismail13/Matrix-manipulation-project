#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

Matrix Matrix::traspose()
{
	Matrix transposed(col, row);
	for (int i = 0; i < transposed.row; i++)
	{
		for (int j = 0; j < transposed.col; j++)
		{
			transposed.arr[i][j] = arr[j][i];
		}
	}
	return transposed;
}

Matrix Matrix::scalarMultiply(int k)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] *= k;
		}
	}
	return *this;
}

Matrix Matrix::sum(Matrix x)
{
	if (row != x.row || col != x.col)
	{
		cout << "Matrcies sizes are not equal, the main matrix is returned." << endl;
		return *this;
	}
		
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] += x.arr[i][j];
		}
	}
	return *this;
}

Matrix Matrix::multiply(Matrix x)
{
	if (!validForMutiplication(x))
	{
		cout << "The Matrices is not valid for multiplication, the main matrix is returned." << endl;
		return *this;
	}
	else 
	{
		Matrix temp(row, x.col);
		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
			{
				float tempValue = 0;
				for (int k = 0; k < x.row; k++)
				{
					tempValue += (arr[i][k] * x.arr[k][j]);
				}
				temp.arr[i][j] = tempValue;
			}
		}
		return temp;
	}
}

bool Matrix::isSymmetric()
{
	bool flag = true;
	Matrix test(*this);
	test = test.traspose();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == test.arr[i][j])
				continue;
			else
				flag = false;
		}
	}
	return flag;
}

bool Matrix::equals(const Matrix x)
{
	if (row != x.row || col != x.col)
		return false;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == x.arr[i][j])
				continue;
			else
				return false;
		}
	}
	return true;
}

bool Matrix::validForMutiplication(const Matrix x)
{
	if (col == x.row)
		return true;
	else
		return false;
}

Matrix Matrix::zeroMatrix(int x, int y)
{
	Matrix temp(x, y);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			temp.arr[i][j] = 0;
		}
	}
	for (int i = 0; i < temp.row; i++)
	{
		for (int j = 0; j < temp.col; j++)
		{
			cout << temp.arr[i][j] << " ";
		}
		cout << endl;
	}
	return temp;
}

Matrix Matrix::identityMatrix(int x)
{
	Matrix temp(x, x);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (i == j)
				temp.arr[i][j] = 1;
			else
				temp.arr[i][j] = 0;
		}
	}
	for (int i = 0; i < temp.row; i++)
	{
		for (int j = 0; j < temp.col; j++)
		{
			cout << temp.arr[i][j] << " ";
		}
		cout << endl;
	}
	return temp;
}

void Matrix::display()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::setValue(float ** x, int r, int c)
{
	arr = x;
	row = r;
	col = c;
}

Matrix Matrix::inverse()
{
	if (determinant(getCol(),*this) != 0)
	{
		int i, j, k;
		float temp;
		for (i = 0; i < col; i++)
		{
			for (j = 0; j < 2 * col; j++)
			{
				if (j == (i + col))
				{
					arr[i][j] = 1;
				}
			}
		}
		for (i = col; i > 1; i--)
		{
			if (arr[i - 1][1] < arr[i][1]) 
			{
				for (j = 0; j < col * 2; j++)
				{
					temp = arr[i][j];
					arr[i][j] = arr[i - 1][j];
					arr[i - 1][j] = temp;
				}
			}
				
		}
		for (i = 0; i < col; i++)
		{
			for (j = 0; j < col * 2; j++)
				if (j != i)
				{
					temp = arr[j][i] / arr[i][i];
					for (k = 0; k < row * 2; k++)
						arr[j][k] -= arr[i][k] * temp;
				}
		}

		for (i = 0; i < col; i++)
		{
			temp = arr[i][i];
			for (j = 0; j < row * 2; j++)
				arr[i][j] = arr[i][j] / temp;
		}

		for (i = 0; i < row; i++)
		{
			for (int j = 0; j < row; j++)
				arr[i][j] = arr[i][j + row];
		}
		return *this;
	}
	else
	{
		cout << "The Matrix is either not square or uninvertable.\nThe matrix will remain unchanged." << endl;
		return *this;
	}

}

float Matrix::determinant(int n, Matrix mat)
{
	
	Matrix subMat(n, n);
	int subI, subJ;
	if (n == 2)
	{
		return ((mat.arr[0][0] * mat.arr[1][1]) - (mat.arr[1][0] * mat.arr[0][1]));
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			subI = 0;
			for (int j = 1; j < n; j++)
			{
				int subJ = 0;
				for (int k = 0; k < n; k++)
				{
					if (k==i)
						continue;
					subMat.arr[subI][subJ] = mat.arr[j][k];
					subJ++;
				}
				subI++;
			}
			det = det + (pow(-1, i) * mat.arr[0][i] * determinant(subMat.getCol()-1,subMat));
		}
	}
	return det;
}

int Matrix::getRow()
{
	return row;
}

int Matrix::getCol()
{
	return col;
}

float Matrix::getDet()
{
	return det;
}

Matrix::Matrix(int x, int y)
{
	row = x;
	col = y;
	arr = new float*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new float[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = 0;
		}
	}
}

Matrix::Matrix()
{
	row = 3;
	col = 3;
	arr = new float*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new float[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix & obj)
{
	row = obj.row;
	col = obj.col;
	arr = new float*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new float[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = obj.arr[i][j];
		}
	}
}


Matrix::~Matrix()
{
}
