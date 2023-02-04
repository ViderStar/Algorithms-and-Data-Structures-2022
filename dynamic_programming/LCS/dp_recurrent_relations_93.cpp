#include <iostream>
#include <algorithm>

using namespace std;

void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i = -~i) {
        cin >> arr[i];
    }
}

void outputArray(int* arr, int size) {
    for (int i = 0; i < size; i = -~i) {
        cout << arr[i] << " ";
    }
}

void main()
{
    int n;
    cin >> n;

    int* A = new int[n];
    int* B = new int[n];

    inputArray(A, n);
    inputArray(B, n);

    int** matrixDP = new int* [-~n];

    for (int i = 0; i <= n; i = -~i) {
        matrixDP[i] = new int[-~n];
    }

    for (int i = 0; i <= n; i = -~i) {
        matrixDP[0][i] = 0;
        matrixDP[i][0] = 0;
    }

    for (int i = 1; i <= n; i = -~i) {
        for (int j = 1; j <= n; j = -~j) {
            if (A[~-i] == B[~-j]) {
                matrixDP[i][j] = -~matrixDP[~-i][~-j];
            }
            else {
                matrixDP[i][j] = max(matrixDP[i][~-j], matrixDP[~-i][j]);
            }
        }
    }

    int k = matrixDP[n][n];
    int tempK = k;

    cout << k << '\n';

    int* indexA = new int[k];
    int* indexB = new int[k];

    int indexI = n;
    int indexJ = n;

    while (k != 0) {
        if (A[~-indexI] == B[~-indexJ]) {
            k = ~- k;
            indexI = ~- indexI;
            indexJ = ~- indexJ;
            indexA[k] = indexI;
            indexB[k] = indexJ;
        }
        else {
            if (matrixDP[indexI][indexJ] == matrixDP[indexI][~- indexJ]) {
                indexJ = ~- indexJ;
            }
            else {
                indexI = ~- indexI;
            }
        }
    }

    outputArray(indexA, tempK);
    cout << '\n';
    outputArray(indexB, tempK);

}