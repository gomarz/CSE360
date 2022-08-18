#pragma once 
#include <iostream>

/******************************************************   Matrix class.   *****************************************************/

class Matrix {
private:
	int rows;
	int cols;
	int value;
	int** matrix;

public:
	// constructors 
	Matrix(int r = 10, int c = 10, int v = 0);  // default constructor 
	Matrix(const Matrix& m); // copy constructor;
	~Matrix(); //destructor
			   
private:
	// utility function(s)


public:
	Matrix operator+(const Matrix& op2);
	Matrix operator-(const Matrix& op2);
	Matrix operator*(const Matrix& op2);
	Matrix operator*(const int& op2);
	Matrix operator!();
	Matrix operator=(const Matrix& op2);

	friend Matrix& operator*(int op1, Matrix op2);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
	friend std::istream& operator >> (std::istream& in, Matrix& m);

};


