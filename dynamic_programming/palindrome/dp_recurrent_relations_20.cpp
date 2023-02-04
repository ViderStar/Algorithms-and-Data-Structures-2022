#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

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

string reverseString(string str) {
    string res = "";
    for (int i = str.size() - 1; i >= 0; i = ~- i) {
        res += str[i];
    }
    return res;
}

void main()
{
    string str;

    ifstream in("input.txt");

    getline(in, str);

    in.close();

    string strReverse = reverseString(str);

    int n = str.size();

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
            if (str[~-i] == strReverse[~-j]) {
                matrixDP[i][j] = -~matrixDP[~-i][~-j];
            }
            else {
                matrixDP[i][j] = max(matrixDP[i][~-j], matrixDP[~-i][j]);
            }
        }
    }

    int k = matrixDP[n][n];
    int tempK = k;

    ofstream out("output.txt");

    out << k << '\n';

    string result = "";

    int indexI = n;
    int indexJ = n;

    while (k != 0) {
        if (str[~-indexI] == strReverse[~-indexJ]) {
            k = ~- k;
            indexI = ~- indexI;
            indexJ = ~- indexJ;
            result += str[indexI];
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

    out << result << '\n';

    out.close();
}