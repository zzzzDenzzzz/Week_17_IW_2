#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

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
	srand((unsigned int)time(NULL));

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = -9 + rand() % 19;
		}
	}
}

void printArray(int **arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << std::setw(2) << arr[i][j] << ' ';
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

void deleteRow(int **arr, int &rows, int cols, int number_row)
{
	delete[]arr[number_row];
	for (int i = number_row; i < rows - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	--rows;
}

void deleteRowsWithZero(int **arr, int &rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == 0)
			{
				deleteRow(arr, rows, cols, i);
				i--;
				break;
			}
		}
	}
}

int main()
{
	int rows = 10;
	int cols = 15;
	int **arr = creatArray(rows, cols);
	initArray(arr, rows, cols);
	printArray(arr, rows, cols);
	deleteRowsWithZero(arr, rows, cols);
	printArray(arr, rows, cols);
	deleteArray(arr, rows);

	return 0;
}