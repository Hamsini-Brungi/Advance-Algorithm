#include <iostream>
using namespace std;

void inputMatrix(int rows, int cols, int matrix[50][50]) {
    cout << "Please input the matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[50][50]) {
    cout << "The matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int countNonZero(int rows, int cols, int matrix[50][50]) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

void generateSparseMatrix(int rows, int cols, int matrix[50][50], int nonZero, int sparseRep[3][50]) {
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseRep[0][index] = i;
                sparseRep[1][index] = j;
                sparseRep[2][index] = matrix[i][j];
                index++;
            }
        }
    }
}

void displaySparseMatrix(int nonZero, int sparseRep[3][50]) {
    cout << "Sparse matrix representation (row, column, value):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < nonZero; j++) {
            cout << sparseRep[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;

    
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    int matrix[50][50]; 
    int sparseRep[3][50]; 

    inputMatrix(rows, cols, matrix);


    displayMatrix(rows, cols, matrix);

    int nonZeroElements = countNonZero(rows, cols, matrix);

    generateSparseMatrix(rows, cols, matrix, nonZeroElements, sparseRep);


    displaySparseMatrix(nonZeroElements, sparseRep);

    return 0;
}
