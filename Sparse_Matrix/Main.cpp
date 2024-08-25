#include <iostream>

#include "SparseMatrix.h"

int main() {
	SparseMatrix mat(10, 10);
	mat.set_value(5, 3, 5);
	mat.set_value(7, 3, 7);
	mat.set_value(2, 3, 2);
	mat.set_value(0, 3, 2);
	mat.set_value(6, 5, 6);
	mat.set_value(4, 5, 4);
	mat.set_value(3, 7, 3);
	mat.set_value(1, 7, 1);

	
	SparseMatrix mat2(10, 10);
	mat2.set_value(1, 2, 1);
	mat2.set_value(2, 2, 2);
	mat2.set_value(1, 5, 6);
	mat2.set_value(1, 5, 4);

	mat.add_matrix(&mat2);

	mat.print_matrix_nonzero();
}