#include <iostream>
#include <fstream>

using namespace std;

int m, c, n;


int h(int x, int i) {
    return (x % m + c * i) % m ;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ifstream in("input.txt");

    in >> m >> c >> n;

    int* arr = new int[m];

    int count = 0;

    for (int i = 0; i < m; ++i) {
        arr[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        int num;
        in >> num;
        int j = 0;
        int k = h(num, j);
        while (true) {
            if (arr[k] == num) {
                break;
            }
            if (arr[k] == -1) {
                arr[k] = num;
                ++count;
                break;
            }
            j++;
            k = h(num, j);
        }
        if (count >= m) {
            break;
        }
    }
    
    in.close();

    std::ofstream out("output.txt");

    for (int i = 0; i < m; ++i) {
        out << arr[i] << ' ';
    }

    out.close();
}