#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int matr[110][110];

int main() {
    ifstream in("input.txt");
    int n, m, a, b;
    in >> n >> m;
    for (int i = 0; i < m; i++) {
        in >> a >> b;
        matr[a - 1][b - 1] = 1;
        matr[b - 1][a - 1] = 1;
    }
    in.close();
    ofstream out("output.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << matr[i][j] << " ";
        }
        out << endl;
    }
    out.close();
    return 0;
}