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

int **sumTwoArrays(int **arr_1, int **arr_2, int rows, int cols)
{
	int **arr = creatArray(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = arr_1[i][j] + arr_2[i][j];
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
			std::cout << std::setw(3) << arr[i][j] << ' ';
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

	int rows, cols;
	inputRowsCols(rows, cols);

	int **arr_1 = creatArray(rows, cols);
	int **arr_2 = creatArray(rows, cols);

	initArray(arr_1, rows, cols);
	initArray(arr_2, rows, cols);
	printArray(arr_1, rows, cols);
	printArray(arr_2, rows, cols);

	int **arr_3 = sumTwoArrays(arr_1, arr_2, rows, cols);
	printArray(arr_3, rows, cols);

	deleteArray(arr_1, rows);
	deleteArray(arr_2, rows);
	deleteArray(arr_3, rows);

	return 0;
}