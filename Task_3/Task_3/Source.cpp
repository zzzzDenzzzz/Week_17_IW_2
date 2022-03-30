#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<Windows.h>

void inputRowsCols(int &rows, int &cols)
{
	std::cout << "Enter rows: ";
	std::cin >> rows;
	std::cout << "Enter cols: ";
	std::cin >> cols;
	std::cout << std::endl;
}

void inputCols(int &cols)
{
	std::cout << "Enter cols: ";
	std::cin >> cols;
	std::cout << std::endl;
}

int **creatArray(int rows, int cols)
{
	int **arr = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

void initArray(int **arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = -9 + rand() % 19;
		}
	}
}

int **mulTwoMatrix(int **arr_1, int **arr_2, int rows_1, int cols_1, int cols_2)
{
	int **arr = creatArray(rows_1, cols_2);
	for (int i = 0; i < rows_1; i++)
	{
		for (int j = 0; j < cols_2; j++)
		{
			arr[i][j] = 0;
			for (int k = 0; k < cols_1; k++)
			{
				arr[i][j] += arr_1[i][k] * arr_2[k][j];
			}
		}
	}
	return arr;
}

void printArray(int **arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << std::right << std::setw(4) << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void deleteArray(int **arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

int main()
{
	srand((unsigned int)time(NULL));

	int rows_matrix_A, cols_matrix_A;
	inputRowsCols(rows_matrix_A, cols_matrix_A);
	int rows_matrix_B, cols_matrix_B;
	inputCols(cols_matrix_B);
	rows_matrix_B = cols_matrix_A;

	int **matrix_A = creatArray(rows_matrix_A, cols_matrix_A);
	int **matrix_B = creatArray(rows_matrix_B, cols_matrix_B);

	initArray(matrix_A, rows_matrix_A, cols_matrix_A);
	initArray(matrix_B, rows_matrix_B, cols_matrix_B);
	printArray(matrix_A, rows_matrix_A, cols_matrix_A);
	printArray(matrix_B, rows_matrix_B, cols_matrix_B);

	int **matrix_C = mulTwoMatrix(matrix_A, matrix_B, rows_matrix_A, cols_matrix_A, cols_matrix_B);
	int rows_matrix_C = rows_matrix_A;
	int cols_matrix_C = cols_matrix_B;
	printArray(matrix_C, rows_matrix_C, cols_matrix_C);

	deleteArray(matrix_A, rows_matrix_A);
	deleteArray(matrix_B, rows_matrix_B);
	deleteArray(matrix_C, rows_matrix_C);

	return 0;
}