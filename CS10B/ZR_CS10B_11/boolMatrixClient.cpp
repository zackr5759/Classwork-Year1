#include <iostream>
#include "boolMatrix.h"
using namespace std;

int main() {
	boolMatrix matrix1;

	for (int i = 0; i < 50; i++) {
		matrix1.set(rand() % 20, rand() % 20, true);
	}

	matrix1.print();
	cout << endl;
	cout << matrix1.rowCount(10) << endl;
	cout << matrix1.colCount(10) << endl;
	cout << matrix1.totalCount() << endl;

	
}