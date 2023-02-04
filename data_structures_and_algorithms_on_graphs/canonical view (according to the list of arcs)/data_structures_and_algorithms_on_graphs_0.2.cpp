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

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    int a, b;
    int cn = n;

    while (n != 0) {
        --n;
        in >> a >> b;
        arr[b - 1] = a;
    }

    in.close();

    std::ofstream out("output.txt");

    for (int i = 0; i < cn; i++) {
        out << arr[i] << ' ';
    }

    out.close();
}