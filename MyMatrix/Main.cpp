#include <iostream>
#include <vector>
#include "Matrix.h"
#include "MyEquation.h"
using namespace std;


void MatrixProgram(float ** m,int row, int col)
{
	
	Matrix x(row, col);
	x.setValue(m,row,col);
choices:
	cout << "Please enter one of the following choices to be done:" << endl;
	cout << "1- Transpose matrix." << endl;
	cout << "2- Multiply matrix by a scalar number." << endl;
	cout << "3- Add 2 matrices." << endl;
	cout << "4- Multiply 2 matrices." << endl;
	cout << "5- Is the matrix symmetric?" << endl;
	cout << "6- Compare equality of 2 matrices" << endl;
	cout << "7- Is the matrix valid for multiplication?" << endl;
	cout << "8- Display the zero matrix." << endl;
	cout << "9- Display the identitiy matrix." << endl;
	cout << "10- Display the matrix." << endl;
	cout << "11- Change matrix values." << endl;
	cout << "12- Display matrix inverse." << endl;
	cout << "13- Exit program." << endl;


	Matrix transposed(x);
	Matrix ScalarMultiply(x);
	Matrix sum(x);
	Matrix multiply(x);
	Matrix Equality(x);
	Matrix Inverse(x);


	int choice;
	cin >> choice;

	if (choice == 1)
	{
		transposed = transposed.traspose();
		transposed.display();
		cout << endl;
	}
	else if (choice == 2)
	{
		int scalar;
		cout << "Please enter the value of the scalar value : ";
		cin >> scalar;
		ScalarMultiply = ScalarMultiply.scalarMultiply(scalar);
		ScalarMultiply.display();
		cout << endl;
	}
	else if (choice == 3)
	{
		int r, c;
		cout << "Please enter the order of the 2nd matrix: " << endl;
		cin >> r >> c;
		float** arr = new float*[r];
		for (int i = 0; i < r; i++)
		{
			arr[i] = new float[c];
		}
		cout << "Please enter the values of the 2nd matrix: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> arr[i][j];
			}
			cout << endl;
		}
		sum.setValue(arr, r, c);
		sum.sum(x);
		sum.display();
		cout << endl;
	}
	else if (choice == 4)
	{
		int r, c;
		cout << "Please enter the order of the 2nd matrix: " << endl;
		cin >> r >> c;
		float** arr = new float*[r];
		for (int i = 0; i < r; i++)
		{
			arr[i] = new float[c];
		}
		cout << "Please enter the values of the 2nd matrix: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> arr[i][j];
			}
			cout << endl;
		}
		multiply.setValue(arr, r, c);
		if (multiply.validForMutiplication(x))
		{
			multiply = multiply.multiply(x);
			multiply.display();
			cout << endl;
		}
		else
		{
			cout << "Matrices can't be multiplied!" << endl;
		}
	}
	else if (choice == 5)
	{
		if (x.isSymmetric())
			cout << "The matrix is symmetric!" << endl;
		else
			cout << "The matrix is not symmetric!" << endl;
	}
	else if (choice == 6)
	{
		int r, c;
		cout << "Please enter the order of the 2nd matrix: " << endl;
		cin >> r >> c;
		float** arr = new float*[r];
		for (int i = 0; i < r; i++)
		{
			arr[i] = new float[c];
		}
		cout << "Please enter the values of the 2nd matrix: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> arr[i][j];
			}
			cout << endl;
		}
		Equality.setValue(arr, r, c);
		if (Equality.equals(x))
		{
			cout << "The 2 matrices are equal!" << endl;
		}
		else
		{
			cout << "The 2 matrices are not equal!" << endl;
		}
	}
	else if (choice == 7)
	{
		int r, c;
		cout << "Please enter the order of the 2nd matrix: " << endl;
		cin >> r >> c;
		float** arr = new float*[r];
		for (int i = 0; i < r; i++)
		{
			arr[i] = new float[c];
		}
		cout << "Please enter the values of the 2nd matrix: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> arr[i][j];
			}
			cout << endl;
		}
		multiply.setValue(arr, r, c);
		if (multiply.validForMutiplication(x))
		{
			cout << "The matrices are valid for multiplication!" << endl;
		}
		else
		{
			cout << "The matrices are valid for multiplication!" << endl;
		}
	}
	else if (choice == 8)
	{
		Matrix::zeroMatrix(x.getRow(), x.getCol());
		cout << endl;
	}
	else if (choice == 9)
	{
		Matrix::identityMatrix(x.getRow());
		cout << endl;
	}
	else if (choice == 10)
	{
		x.display();
		cout << endl;
	}
	else if (choice == 11)
	{
		int r=x.getRow(), c=x.getCol();

		float** arr = new float*[r];
		for (int i = 0; i < r; i++)
		{
			arr[i] = new float[c];
		}
		cout << "Please enter the values of the new matrix: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> arr[i][j];
			}
			cout << endl;
		}
		x.setValue(arr, r, c);
	}
	else if (choice == 12)
	{
		Inverse.inverse();
		Inverse.display();
		cout << endl;
	}
	else if (choice == 13)
	{
		exit(0);
	}
	else
	{
		cout << "\nIncorrect choice!\n Please enter a valid operation.\n\n";
	}
	goto choices;
	
}

void EquationProgram()
{
choices:
	cout << "Please enter your choice: " << endl;
	cout << "1- Insert equation." << endl;
	cout << "2- Solve system." << endl;
	cout << "3- Swap equations." << endl;
	cout << "4- Exit." << endl;
	int choice;
	cin >> choice;
	MyEquations myEquations;
	if (choice == 1)
	{
		goto choices;
	}
	else if (choice == 2)
	{
		goto choices;
	}
	else if(choice == 3)
	{
		goto choices;
	}
	else if (choice == 4)
	{
		exit(0);
	}
	else
	{
		cout << "Incorrect choice!" << endl;
		goto choices;
	}
}
int main()
{
	

	int choice;
	cout << "Please enter the number of the program you want to work on:" << endl;
	cout << "1- Matrix program.\n" << "2- Equation program." << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Enter the order of the matrix:" << endl;
		int row, col;
		cin >> row >> col;

		cout << "Please enter the values of the matrix:" << endl;
		float ** m = new float*[row];
		for (int i = 0; i < row; i++)
		{
			m[i] = new float[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> m[i][j];
			}
			cout << endl;
		}
		MatrixProgram(m,row,col);
	}
		
	else if (choice == 2)
		EquationProgram();
	else
	{
		cout << "Incorrect choice!\nPlease enter a valid choice." << endl;
		main();
	}
	return 0;
}