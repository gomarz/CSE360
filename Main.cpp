#include "Matrix.h"
#include<fstream>
#include <iostream>
#include <string>
using namespace std;

Matrix returnMat(string inputOne,Matrix a, Matrix b, Matrix c)
{
	if (inputOne.at(0) == '!') //check if the operand contains the transpose symbol
	{
		//if it does and the next symbol is A, store the transposed first matrix
		if (inputOne.at(1) == toupper('a'))
		{

			return !a;
		}

		//if it does and the next symbol is B, store the transposed first matrix
		else if (inputOne.at(1) == toupper('b'))
		{
			return !b;
		}

		//if it does and the next symbol is C, store the transposed first matrix
		else if (inputOne.at(1) == toupper('c'))
		{
			return !c;
		}

		//Otherwise, its an invalid combination
		else
			cout << "Invalid 1st Operand entered! \n";
		return 0;
	}//

	 //If there is no character for transposal, next character is A, B, OR C
	else if ((inputOne.at(0) == 'A') || (inputOne.at(0) == 'B') || (inputOne.at(0) == 'C'))
	{
		//return the appropriate matrix
		if (inputOne.at(0) == 'A')
			return a;
		else if (inputOne.at(0) == 'B')
			return b;
		else if (inputOne.at(0) == 'C')
			return c;
	
	}
	cout << "\nInvalid Operand entered!\n"; //otherwise, its invalid

	return 0;

}

//converts the operand from a char into its appropriate representation
char getOperand(char operand,Matrix inputOne, Matrix inputTwo)
{
	switch (operand)
	{
	case '+':

		cout << inputOne +  inputTwo;
		break;
	case '-':
		cout << inputOne - inputTwo;
		break;
	case '*':
		cout << inputOne * inputTwo;
		break;

	default:
		cout << "invalid Operator!";
		break;
	}
	return 0;
}
//converts the operand from a char into its appropriate representatio
//this is for multiplying by an int, from the left
char getOperand(char operand, int inputOne, Matrix inputTwo)
{
	switch (operand)
	{
	case '*':
		cout << inputOne * inputTwo;
		break;

	default:
		cout << "invalid Operator or operation!";
		break;
	}
	return 0;
}

//converts the operand from a char into its appropriate representatio
//this is for multiplying by an int, from the right
char getOperand(char operand, Matrix inputOne, int inputTwo)
{
	switch (operand)
	{
	case '*':
		cout << inputOne * inputTwo;
		break;

	default:
		cout << "invalid Operator or Operation!";
		break;
	}		
	return 0;
}


int main()
{
	//Creating three matrices to fill
	Matrix m1;
	Matrix m2;
	Matrix m3;

	//opening the stream
	ifstream theFile("Matrix.txt");

	//if the file does not exist
	if (!theFile)
	{
		cout << "Invalid File! Closing.....\n";
	}

	//otherwise, fill the matrix, run program
	else
	{
		cout << "//***************Loading Matrices. . . .**************//\n";
		theFile >> m1 >> m2 >> m3;
		theFile.close(); //close the file when done



	//Print the Matrices
		cout << "Matrix A:" << "\n";
		cout << m1 << "\n";
		cout << "Matrix B:" << "\n";
		cout << m2 << "\n";
		cout << "Matrix C:" << "\n";
		cout << m3 << "\n";

		char input; //holds the char to determine if hte program should keep running or end;
		string inputOperandOne; // Holds the char representation of the 1st Matrix entered
		string inputOperandTwo; // Holds the char representation of the 2nd Matrix entered 
		char matOperator; //holds the char representation of the mathematical operator

		//I could not find a way to read for the ! operand without causing massive problems
		//So I had to use a delimiter, in this case a comma for the first operand
		
			do {
			cout << "\nPlease enter the operation you would like to perform.\nEx. To add A to itself, type 'A,*A'.\nTo transpose, append an '!' to the matrix. (like !A)\n";
			
			getline(cin, inputOperandOne, ','); // grab the first operand, using ',' as delimiter

			cin >> matOperator; //grab the operator
			
			getline(cin, inputOperandTwo); //grab the second operand

			//Print out the operation being attempted
			cout << "\nPerforming operation: " << inputOperandOne << matOperator << inputOperandTwo << "\n-----------------\n Result: \n";


			//check to see what the operands contain. If the first is a digit
			if (isdigit(inputOperandOne.at(0)) && !isdigit(inputOperandTwo.at(0)))
			{
				//run getOperand, using the first Operands value as an int
				getOperand(matOperator, stoi(inputOperandOne), returnMat(inputOperandTwo, m1, m2, m3));
			}
			//else if the second operand is a digit
			else if (!isdigit(inputOperandOne.at(0)) && isdigit(inputOperandTwo.at(0)))
			{
				//run getOperand, using the second Operands value as an int
				getOperand(matOperator, returnMat(inputOperandOne, m1, m2, m3), stoi(inputOperandTwo));
			}

			else
			{
				//otherwise, use returnMat, for both 
				getOperand(matOperator, returnMat(inputOperandOne, m1, m2, m3), returnMat(inputOperandTwo, m1, m2, m3));
			}

			//Print the original arrays
			cout << "\nMatrix A:" << "\n";
			cout << m1 << "\n";
			cout << "Matrix B:" << "\n";
			cout << m2 << "\n";
			cout << "Matrix C:" << "\n";
			cout << m3 << "\n";

			//Asks user if they want to continue, or quit
			cout << "\n Press Q to quit, or any other key to continue\n";
			cin >> input;


		} while (toupper(input) != 'Q'); //
	}
}
	