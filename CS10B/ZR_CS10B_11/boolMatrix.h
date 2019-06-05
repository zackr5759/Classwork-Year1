#ifndef BOOLMATRIX_H
#define BOOLMATRIX_H

class boolMatrix {
public:
	static const int NUM_ROWS = 20;
	static const int NUM_COLS = 20;

	boolMatrix();
	int rowCount(int inRow);
	int colCount(int inCol);
	int totalCount();
	void set(int inRow, int inCol, bool inBool);
	bool get(int inRow, int inCol);
	void print()const;

private:

	bool grid[NUM_ROWS][NUM_COLS];

};

#endif