#include <iostream>
using namespace std;

void multiplyMatrices(int mat1[4][2], int mat2[2][3], int result[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int matrix[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int mat1[4][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };


    int mat2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };


    int result[4][3];


    multiplyMatrices(mat1, mat2, result);


    cout << "Hasil perkalian matriks:" << endl;
    printMatrix(result);

    return 0;
}
