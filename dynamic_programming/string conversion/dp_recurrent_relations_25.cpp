#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int x, y, z;

    ifstream in("in.txt");

    in >> x >> y >> z;

    string str1, str2;

    getline(in, str1);
    getline(in, str1);
    getline(in, str2);

    in.close();

    int n1 = str1.length(), n2 = str2.length();
    n1 = -~ n1;
    n2 = -~ n2;

    int** dp = new int* [n1];

    for (int i = 0; i < n1; i = -~i) {
        dp[i] = new int[n2];
    }

    for (int i = 0; i < n2; i = -~i) {
        dp[0][i] = i * y;
    }

    for (int i = 0; i < n1; i = -~i) {
        dp[i][0] = i * x;
    }

    for (int i = 1; i < n1; i = -~i) {
        for (int j = 1; j < n2; j = -~j) {
            int delta = (str1[~-i] == str2[~-j] ? 0 : 1);
            dp[i][j] = min(dp[~- i][j] + x, min(dp[i][~- j] + y, dp[~- i][~- j] + min(z, x + y) * delta));
        }
    }

    ofstream out("out.txt");

    out << dp[~- n1][~- n2];

    out.close();
}