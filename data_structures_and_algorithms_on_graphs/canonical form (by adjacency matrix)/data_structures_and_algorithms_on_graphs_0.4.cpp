#include <iostream>
#include <fstream>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ifstream in("input.txt");

    int n;
    in >> n;

    int** arr = new int*[n];
    int* resArr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        resArr[i] = 0;
        for (int j = 0; j < n; ++j) {
            in >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1) {
                resArr[j] = i + 1;
            }
        }
    }

    in.close();

    std::ofstream out("output.txt");

    for (int i = 0; i < n; i++) {
        out << resArr[i] << ' ';
    }

    out.close();
}