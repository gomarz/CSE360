/***************************************************
Implementation file for Matrix class
*************************************************/
#include "Matrix.h"
#include<fstream>
#include <stdexcept>
//using namespace std;

/**************************************************
default constructor
**************************************************/
Matrix::Matrix(int r, int c, int v)
{
	rows = r;
	cols = c;
	value = v;

	matrix = new int *[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = value;
		}
	}
}

/******************************************************
copy constructor
******************************************************/
Matrix::Matrix(const Matrix& old)
{
	rows = old.rows;
	cols = old.cols;
	matrix = old.matrix;
}

//Add two matrices
Matrix Matrix::operator+(const Matrix& op2)
{
	Matrix addMatrix(rows, cols);
	if (rows == op2.rows && cols == op2.cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				addMatrix.matrix[i][j] = matrix[i][j] + op2.matrix[i][j];
			}
		}
		return addMatrix;
	}

	else
	{
		std::cout << "Rows or columns do not match. Cannot perform addition - please transpose first \n";
		return 0;
	}
}


//Multiply two matrices
Matrix Matrix::operator*(const Matrix& op2)
{
	Matrix multMatrix(rows, cols);
	if (rows == op2.rows && cols == op2.cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				multMatrix.matrix[i][j] = matrix[i][j] * op2.matrix[i][j];
			}
		}
		return multMatrix;
	}

	else
	{
		std::cout << "Rows or columns do not match. Cannot perform multiplication - please transpose first \n";
		return 0;
	}
}

//Multiply a Matrice by an int
Matrix Matrix::operator*(const int& op2)
{
	Matrix scalarMat(rows, cols);

	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < cols; j++)
		{
			scalarMat.matrix[i][j] = matrix[i][j] * op2;
		}

	}
	return scalarMat;
}

//subtract matrices
Matrix Matrix::operator-(const Matrix& op2)
{
	Matrix subtractMatrix(rows, cols);
	if (rows == op2.rows && cols == op2.cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				subtractMatrix.matrix[i][j] = matrix[i][j] - op2.matrix[i][j];
			}
		}
		return subtractMatrix;
	}

	else
	{
		std::cout << "Rows or columns do not match. Cannot perform subtraction - please transpose first \n";
		return 0;
	}
}

//Transpose a matrice
Matrix Matrix::operator!()
{
	Matrix transMat(this->cols, this->rows);

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			transMat.matrix[i][j] = this->matrix[j][i];
		}
	}
	return transMat;
}

Matrix Matrix::operator=(const Matrix &op2)
{
	Matrix deepCopy(op2.rows,op2.cols);
	deepCopy.matrix = new int*[op2.rows];

	for (int i = 0; i < op2.rows; i++)
	{
		deepCopy.matrix[i] = new int[op2.cols];
	}

	for (int i = 0; i < op2.rows; i++)
	{
		for (int j = 0; j < op2.cols; j++)
		{
			deepCopy.matrix[i][j] = op2.matrix[i][j];
		}
	}
	return deepCopy;
}

// Destructor
Matrix::~Matrix()
{

}

//Multiply matrice by an int on the right side
Matrix& operator*(int op1, Matrix op2)
{
	Matrix scalarMat(op2.rows, op2.cols);

	for (int i = 0; i < op2.rows; i++)
	{

		for (int j = 0; j < op2.cols; j++)
		{
			scalarMat.matrix[i][j] = op2.matrix[i][j] * op1;
		}

	}
	std::cout << scalarMat; //Print the new matrix..see below
	return scalarMat; //This should return the value but it doesn't.
	
}

//Friend  function for output
std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			out << m.matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return out;
}


//friend function for input
std::istream& operator >> (std::istream& in, Matrix& m)
{
	in >> m.rows >> m.cols;
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			in >> m.matrix[i][j];
		}

	}
	return in;
}



