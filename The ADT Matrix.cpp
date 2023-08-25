#include<iostream>
#include<conio.h>
#include <fstream>// library for file input and output
typedef int** dynamic;//defining the type or 2D dynamic array
using namespace std;
//===========================the matrix class=================================
class Matrix
{
private:
int rows, column;
dynamic matrix;//aray to initialize the 1st and 2nd matrix
dynamic result;//array to show the results
public:
//------------------------------------------------------------------------------------
void setMatrix(int ro,int col)//setting the result matrix
{
result = new int* [ro];//since the rows and column for the result matrix can
differ for each result
for (int i = 0; i < ro; i++)
{
result[i] = new int[col];
}
}
//------------------------------------------------------------------------------------
void getrows()//getting rows from the user
{
cout << "Enter number of rows of matrix: ";
cin >> rows;
}
void getColumnn()//getting column from the user
{
cout << "Enter number of column of matrix: ";
cin >> column;
}
//------------------------------------------------------------------------------------
~Matrix()//destructor for pointer defined dynamic arrays
{
delete[] result;
delete[] matrix;
}
//------------------------------------------------------------------------------------
void RnumInFile()//writing random numbers in the file
{
ofstream myfile;
myfile.open("numbers.txt");
if (!myfile)
{
cerr << "File not found " << endl;
}
srand(time(0));
for (int i = 0;i < 1000;i++)
{
myfile << rand() % 100 << endl;
}
}
//------------------------------------------------------------------------------------
void matrixIntial()//defining the matrix intial operations
{
getrows();
getColumnn();
intialization();
displayMatrix();
}
//------------------------------------------------------------------------------------
void displayMatrix()//displaying the intial matrix
{
for (int i = 0;i < rows;i++)
{
for (int j = 0;j < column;j++)
{
cout << matrix[i][j] << "\t";
}
cout << endl;
}
cout << endl;
}
//------------------------------------------------------------------------------------
void displayResult(int r, int c)//displaying the result matrix
{
for (int i = 0; i < r; i++)
{
for (int j = 0; j < c; j++)
{
cout << result[i][j] << "\t";
}
cout << endl;
}
cout << endl;
}
//=============================================================================
Matrix();
Matrix(int rm, int cm, dynamic m, int resr, int rescol, dynamic res);
void menu();
void intialization();
void operator*(Matrix m);
void operator+(Matrix m);
void operator-(Matrix m);
void transpose();
//============================================================================
};
//------------------------------------------------------------------------------------
Matrix::Matrix()//default constructor
{
rows = column = 0;
matrix = new int* [3];//default intialization of matrix
for (int i = 0; i < 3; i++)
{
matrix[i] = new int[3];
}
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
matrix[i][j] = 0;
}
}
result = new int* [3];//default intialization of result matrix
for (int i = 0; i < 3; i++)
{
result[i] = new int[3];
}
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
result[i][j] = 0;
}
}
}
//------------------------------------------------------------------------------------
Matrix::Matrix(int rm, int cm, dynamic m, int resr, int rescol, dynamic res) //parametrized
constructor
{
rows = rm;
column = cm;
matrix = new int* [rm];//parametrized intialization of matrix
for (int i = 0; i < rows; i++)
{
matrix[i] = new int[cm];
}
for (int i = 0; i < rm; i++)
{
for (int j = 0; j < cm; j++)
{
matrix[i][j] = m[i][j];
}
}
result = new int* [resr];//parametrized intialization of result matrix
for (int i = 0; i < resr; i++)
{
result[i] = new int[rescol];
}
for (int i = 0; i < resr; i++)
{
for (int j = 0; j < rescol; j++)
{
result[i][j] = res[i][j];
}
}
}
//------------------------------------------------------------------------------------
void Matrix::menu()//menu for the user to choose the operation
{
Matrix m1, m2;
char choice;
do {
cout << "\n Choose the operation you want to perform on matrix : " << endl;
cout << "Press A for Addition" << endl;
cout << "Press S for subtraction" << endl;
cout << "Press M for multiplication" << endl;
cout << "Press T for transpose" << endl; cin >> choice;
if (choice == 'A' || choice == 'a')
{
cout << "Enter rows and column for matrix 1" << endl;
m1.matrixIntial();
cout << "Enter rows and column for matrix 2" << endl;
m2.matrixIntial();
m1 + m2;
exit(0);
}
else if (choice == 'S' || choice == 's')
{
cout << "Enter rows and column for matrix 1" << endl;
m1.matrixIntial();
cout << "Enter rows and column for matrix 2" << endl;
m2.matrixIntial();
m1 - m2;
exit(0);
}
else if (choice == 'm' || choice == 'M')
{
cout << "Enter rows and column for matrix 1" << endl;
m1.matrixIntial();
cout << "Enter rows and column for matrix 2" << endl;
m2.matrixIntial();
m1* m2;
exit(0);
}
else if (choice == 't' || choice == 'T')
{
m2.matrixIntial();
m2.transpose();
exit(0);
}
else
cout << " You Entered Wrong choice, Kindly Retype :";
} while (choice != 'A' && choice != 'a' && choice != 'S' && choice != 'M' && choice !=
'm' && choice != 'T' && choice != 't');
}
//------------------------------------------------------------------------------------
void Matrix::intialization()//intializing the intial matrix by random numbers input from
file
{
matrix = new int* [rows];
for (int i = 0; i < rows; i++)
{
matrix[i] = new int[column];
}
ifstream myfile("numbers.txt");
if (!myfile)
{
	cerr << "File not found" << endl;
exit(1);
}
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < column; j++)
{
myfile >> matrix[i][j];
}
}
myfile.close();
}
//------------------------------------------------------------------------------------
void Matrix::operator+(Matrix m)//using operator overloading for addition
{
setMatrix(rows, column);//setting result matrix
if (rows != m.rows && column != m.column)
{
cerr << "Matrices cannot be subtracted" << endl;
cout << "Order of matrices are not same" << endl;
}
else
{
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < column; j++)
{
result[i][j] = matrix[i][j] + m.matrix[i][j];
}
}
cout << "Result of addition of two matrices are: " << endl;
displayResult(rows, column); //displaying result matrix
}
}
//------------------------------------------------------------------------------------
void Matrix::operator-(Matrix m)//using operator overloading for subraction
{
setMatrix(rows, column);//setting result matrix
if (rows != m.rows && column != m.column)
{
cerr << "Matrices cannot be added" << endl;
cout << "Order of matrices are not same" << endl;
}
else
{
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < column; j++)
{
result[i][j] = matrix[i][j] - m.matrix[i][j];
}
}
cout << "Result of subtraction of two matrices are: " << endl;
displayResult(rows, column);//displaying result
}
}
//------------------------------------------------------------------------------------
void Matrix::operator*(Matrix m)//using operator overloading for multiplication
{
setMatrix(rows, m.column);//setting result matrix
for (int i = 0; i < rows; i++)//intializing matrix with 0 before operation
//because same matrix is going to be used for addition with the other two
{
for (int j = 0; j < m.column; j++)
{
result[i][j] = 0;
}
}
if (column != m.rows)
{
cerr << "Multiplication is not possible" << endl;
cout << "Column of ist matrix is not equal to rows of 2nd matrix" << endl;
}
for (int i = 0; i < rows; ++i)
{
for (int j = 0; j < m.column; ++j)
{
for (int k = 0; k < column; ++k)
{
result[i][j] += matrix[i][k] * m.matrix[k][j];
}
}
}
cout << "Result of multiplication of matrices are: " << endl;
displayResult(rows, m.column);//displaying result
}
//------------------------------------------------------------------------------------
void Matrix::transpose()//getting the transpose of matrix
{
setMatrix(column, rows);//setting the result matrix
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < column; j++)
{
result[j][i] = matrix[i][j];
}
}
cout << "Transpose of a matrix is" << endl;
displayResult(column, rows);//displaying result
}
//------------------------------------------------------------------------------------
int main()
{
Matrix m1;
m1.menu();
system("pause");
return 0;
}
//------------------------------------------------------------------------------------