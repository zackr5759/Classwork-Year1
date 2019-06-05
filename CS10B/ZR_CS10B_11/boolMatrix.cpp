#include <iostream>
#include <cassert>
#include "boolMatrix.h"
using namespace std;


boolMatrix::boolMatrix()
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			grid[i][j] = false;
		}
	}

}






void boolMatrix::print() const
{
	for (int i = 0; i < NUM_ROWS + 1; i++)
	{
		if (i == 0)
		{
			cout << " ";
			for (int j = 0; j < NUM_COLS; j++)
			{
				if (j < 10)
					cout << j; else cout << j - 10;
			}
			cout << endl;
		}
		else {
			cout << i - 1;
			for (int j = 0; j < NUM_COLS; j++)
			{
				if (grid[i-1][j] == true)
				{
					cout << "*";
				}
				else cout << " ";
			}
			cout << endl;
		}
		
	}
}






void boolMatrix::set(int inRow, int inCol, bool inBool)
{
	grid[inRow][inCol] = inBool;
	assert(inRow <= NUM_ROWS || inCol <= NUM_COLS);
}






bool boolMatrix::get(int inRow, int inCol)
{
	return grid[inRow][inCol];
	assert(inRow <= NUM_ROWS || inCol <= NUM_COLS);
}






int boolMatrix::rowCount(int inRow)
{
	int rowCount = 0;
	for (int count = 0; count < NUM_ROWS; count++)
	{
		if (grid[inRow][count] == true)
			rowCount++;
	}
	return rowCount;
	assert(inRow <= NUM_ROWS);
}







int boolMatrix::colCount(int inCol)
{
	int colCount = 0;
	for (int count = 0; count < NUM_COLS; count++)
	{
		if (grid[count][inCol] == true)
			colCount++;
	}
	return colCount;
	assert(inCol <= NUM_COLS);
}






int boolMatrix::totalCount()
{
	int totalCount = 0;
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			if (grid[i][j] == true)
				totalCount++;

		}
	}
	return totalCount;
}









