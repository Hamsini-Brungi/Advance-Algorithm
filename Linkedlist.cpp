#include <iostream>
using namespace std;

struct Element {
    int x;
    int y;
    int data;
    Element* nextElement;
};

Element* createElement(int x, int y, int data) {
    Element* newElement = new Element();
    newElement->x = x;
    newElement->y = y;
    newElement->data = data;
    newElement->nextElement = nullptr;
    return newElement;
}

Element* matrixToLinkedList(int** matrix, int numRows, int numCols) {
    Element* start = nullptr;
    Element* end = nullptr;

    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            if (matrix[r][c] != 0) {
                Element* newElement = createElement(r, c, matrix[r][c]);
                if (start == nullptr) {
                    start = newElement;
                    end = newElement;
                } else {
                    end->nextElement = newElement;
                    end = newElement;
                }
            }
        }
    }
    return start;
}

void displayList(Element* start) {
    Element* current = start;
    while (current != nullptr) {
        cout << "(" << current->x << ", " << current->y << ", " << current->data << ") -> ";
        current = current->nextElement;
    }
    cout << "NULL" << endl;
}

int main() {
    int numRows, numCols;
    cout << "Enter the number of rows and columns for the sparse matrix: ";
    cin >> numRows >> numCols;
    
    int** matrix = new int*[numRows];
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new int[numCols];
    }

    cout << "Enter matrix elements: ";
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Sparse matrix: " << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    Element* start = matrixToLinkedList(matrix, numRows, numCols);
    cout << "Linked list representation of the sparse matrix: " << endl;
    displayList(start);

    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
