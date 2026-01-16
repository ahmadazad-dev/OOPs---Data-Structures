//#include<iostream>
//#include<fstream>
//#include<iomanip>
//using namespace std;
//int** InputMatrix(ifstream& Inputfile, int& rows, int& columns) {
//	Inputfile >> rows;
//	Inputfile >> columns;
//	int** matrix = new int* [rows];
//	for (int i = 0;i < rows;i++) {
//		*(matrix + i) = new int[columns];
//	}
//	for (int** iptr = matrix;iptr < matrix + rows;iptr++) {
//		for (int* jptr = *iptr;jptr < *iptr + columns;jptr++) {
//			Inputfile >> *jptr;
//		}
//	}
//	return matrix;
//}
//void OutputMatrix(int** Matrix, const int& rows, const int& columns) {
//	for (int** iptr = Matrix;iptr < Matrix + rows;iptr++) {
//		for (int* jptr = *iptr;jptr < *iptr + columns;jptr++) {
//			cout << *jptr <<setw(3)<< " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//int** AddMatrix(int** MatrixA, int** MatrixB, const int& rows, const int& columns) {
//	int** Resultant = new int* [rows];
//	for (int i = 0;i < rows;i++) {
//		*(Resultant + i) = new int[columns];
//	}
//	for (int** iptr = MatrixA, ** jptr = MatrixB, ** kptr = Resultant;iptr < MatrixA + rows;iptr++, jptr++, kptr++) {
//		for (int* lptr = *iptr, * mptr = *jptr, * nptr = *kptr; lptr < *iptr + columns;lptr++, mptr++, nptr++) {
//			*nptr = *lptr + *mptr;
//		}
//	}
//	return Resultant;
//}
//int** TransposeofMatrix(int** matrix, const int& rows, const int& columns) {
//	
//	int** transposedMatrix = new int* [columns];
//	for (int i = 0; i < columns; ++i) {
//		*(transposedMatrix+i) = new int[rows];
//	}
//	for (int i = 0;i < columns;i++) {
//		for (int j = 0;j < rows;j++) {
//			*(*(transposedMatrix + j) + i) = *(*(matrix + i) + j);
//		}
//	}
//
//	return transposedMatrix;
//}
//bool IsSymmetric(int** matrix, const int& rows, const int& columns) {
//	if (rows == columns) {
//		int** transposeMatrix = TransposeofMatrix(matrix, rows, columns);
//		bool flag = true;
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < columns;j++) {
//				if (*(*(transposeMatrix + i) + j) == *(*(matrix + i) + j)) {
//					flag = true;
//				}
//				else {
//					flag = false;
//					return false;
//				}
//			}
//		}
//	}
//	else {
//		return false;
//	}
//
//}
//void InterchangeRows(int*& row1, int*& row2) {
//	int* temp = row1;
//	row1 = row2;
//	row2 = temp;
//}
//
//void InterchangeRows(int** matrix, const int& rows, const int& columns) {
//	int num1, num2;
//	do {
//		cout << "Enter Row number 1: ";
//		cin >> num1;
//		if (num1 < rows && num1 >= 0) {
//			break;
//		}
//	} while (true);
//	do {
//		cout << "Enter Row number 2: ";
//		cin >> num2;
//		if (num2 < rows && num2 >= 0) {
//				break;
//			}
//	} while (true);
//
//	cout << "After Interchanging " << endl;
//	InterchangeRows(matrix[num1], matrix[num2]);
//	OutputMatrix(matrix, rows, columns);
//}
//int main() {
//	int Matrix_one_rows = 0, Matrix_two_rows = 0, Matrix_three_rows = 0, Matrix_three_columns = 0, Matrix_one_columns = 0, Matrix_two_columns = 0;
//	ifstream Inputfile("Input.txt");
//
//	//Taking Input From File
//	int** First_Matrix = InputMatrix(Inputfile, Matrix_one_rows, Matrix_one_columns);
//	int** Second_Matrix = InputMatrix(Inputfile, Matrix_two_rows, Matrix_two_columns);
//	int** Third_Matrix = InputMatrix(Inputfile, Matrix_three_rows, Matrix_three_columns);
//	Inputfile.close();
//	//Displaying Matrices
//	cout << "Matrix A:" << endl;
//	OutputMatrix(First_Matrix, Matrix_one_rows, Matrix_one_columns);
//	cout << "Matrix B:" << endl;
//	OutputMatrix(Second_Matrix, Matrix_two_rows, Matrix_two_columns);
//	cout << "Matrix C:" << endl;
//	OutputMatrix(Third_Matrix, Matrix_three_rows, Matrix_three_columns);
//
//	//Addition of Matrices
//	int** Resultant_Matrix=nullptr;
//	cout << "Matrix A + Matrix B:" << endl;
//	if (Matrix_one_rows == Matrix_two_rows && Matrix_one_columns == Matrix_two_columns) {
//		Resultant_Matrix = AddMatrix(First_Matrix, Second_Matrix, Matrix_one_rows, Matrix_one_columns);
//		OutputMatrix(Resultant_Matrix, Matrix_one_rows, Matrix_one_columns);
//	}
//	else {
//		cout << "Addition Not Possible" << endl;
//	}
//	cout << endl;
//	cout << "Matrix B + Matrix C:" << endl;
//	if (Matrix_three_rows == Matrix_two_rows && Matrix_three_columns == Matrix_two_columns) {
//		Resultant_Matrix = AddMatrix(Third_Matrix, Second_Matrix, Matrix_three_rows, Matrix_three_columns);
//		OutputMatrix(Resultant_Matrix, Matrix_two_rows, Matrix_two_columns);
//	}
//	else {
//		cout << "Addition Not Possible" << endl;
//	}
//	cout << endl;
//	cout << "Matrix A + Matrix C:" << endl;
//	if (Matrix_one_rows == Matrix_three_rows && Matrix_one_columns == Matrix_three_columns) {
//		Resultant_Matrix = AddMatrix(First_Matrix, Third_Matrix, Matrix_one_rows, Matrix_one_columns);
//		OutputMatrix(Resultant_Matrix, Matrix_one_rows, Matrix_one_columns);
//	}
//	else {
//		cout << "Addition Not Possible" << endl;
//	}
//	cout << endl;
//	int** Transpose_Matrix;
//	//Taking Transpose of Matrix
//	cout << "Transpose of Matrix A: " << endl;
//	Transpose_Matrix = TransposeofMatrix(First_Matrix, Matrix_one_rows, Matrix_one_columns);
//	OutputMatrix(Transpose_Matrix, Matrix_one_columns, Matrix_one_rows);
//	cout << endl;
//	cout << "Transpose of Matrix B: " << endl;
//	Transpose_Matrix = TransposeofMatrix(Second_Matrix, Matrix_two_rows, Matrix_two_columns);
//	OutputMatrix(Transpose_Matrix, Matrix_two_columns, Matrix_two_rows);
//	cout << endl;
//	cout << "Transpose of Matrix C: " << endl;
//	Transpose_Matrix = TransposeofMatrix(Second_Matrix, Matrix_three_rows, Matrix_three_columns);
//	OutputMatrix(Transpose_Matrix, Matrix_three_rows, Matrix_three_columns);
//	cout << endl;
//
//	//Checking if the Matrix Is Symmetric or not
//	bool IsMyMatrixASymmetric = IsSymmetric(First_Matrix, Matrix_one_rows, Matrix_one_columns);
//	if (IsMyMatrixASymmetric == true) {
//		cout << " Matrix A is Symmetric" << endl;
//	}
//	else {
//		cout << "Matrix A is not Symmetric" << endl;
//	}
//	bool IsMyMatrixBSymmetric = IsSymmetric(Second_Matrix, Matrix_two_rows, Matrix_two_columns);
//	if (IsMyMatrixBSymmetric == true) {
//		cout << " Matrix B is Symmetric" << endl;
//	}
//	else {
//		cout << "Matrix B is not Symmetric" << endl;
//	}
//	bool IsMyMatrixCSymmetric = IsSymmetric(Third_Matrix, Matrix_three_rows, Matrix_three_columns);
//	if (IsMyMatrixCSymmetric == true) {
//		cout << " Matrix C is Symmetric" << endl;
//	}
//	else {
//		cout << "Matrix C is not Symmetric" << endl;
//	}
//	cout << endl;
//
//	//Interchanging Rows 
//	cout << "Interchanging Matrix A Rows " << endl;
//	InterchangeRows(First_Matrix, Matrix_one_rows, Matrix_one_columns);
//	cout << "Interchanging Matrix B Rows " << endl;
//	InterchangeRows(Second_Matrix, Matrix_two_rows, Matrix_two_columns);
//	cout << "Interchanging Matrix C Rows " << endl;
//	InterchangeRows(Third_Matrix, Matrix_three_rows, Matrix_three_columns);
//
//	return 0;
//}
