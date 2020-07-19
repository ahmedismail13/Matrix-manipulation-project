#pragma once
class Matrix
{
private:
	int row, col;
	float** arr;
	float det = 0;
public:
	Matrix traspose();
	Matrix scalarMultiply(int k);
	Matrix sum(Matrix x);
	Matrix multiply(Matrix x);
	bool isSymmetric();
	bool equals(Matrix x);
	bool validForMutiplication(const Matrix x);
	static Matrix zeroMatrix(int x, int y);
	static Matrix identityMatrix(int x);
	void display();
	void setValue(float** x, int r, int c);
	Matrix inverse();
	float determinant(int n, Matrix mat);
	int getRow();
	int getCol();
	float getDet();
	Matrix(int x, int y);
	Matrix();
	Matrix(const Matrix &obj);
	~Matrix();
};

