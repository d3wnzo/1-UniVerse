#include <iostream>
using namespace std;

// Fungsi untuk menginput elemen matriks
void inputMatrix(int matrix[3][3], int rows, int cols) {
    cout << "Masukkan elemen matriks (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Fungsi untuk mengurangi dua matriks
void subtractMatrices(int mat1[3][3], int mat2[3][3], int result[3][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Fungsi untuk mencetak elemen matriks
void printMatrix(int matrix[3][3], int rows, int cols) {
    cout << "Hasil matriks:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows = 3, cols = 3;
    int mat1[3][3], mat2[3][3], result[3][3];

    // Input matriks pertama
    inputMatrix(mat1, rows, cols);

    // Input matriks kedua
    inputMatrix(mat2, rows, cols);

    // Mengurangi matriks
    subtractMatrices(mat1, mat2, result, rows, cols);

    // Mencetak hasil pengurangan matriks
    printMatrix(result, rows, cols);

    return 0;
}
