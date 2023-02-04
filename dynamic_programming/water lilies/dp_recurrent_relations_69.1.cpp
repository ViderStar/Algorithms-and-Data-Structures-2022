#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("input.txt");
    int n;
    in >> n;
    if ((n < 1) || (n > 1000)) {
        in.close();
        return 1;
    }
    int* food = new int[n];
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        in >> arr[i];
    }
    in.close();
    ofstream out("output.txt");
    if (n == 1) {
        out << arr[0];
        out.close();
        return 0;
    }
    if (n == 2) {
        out << "-1";
        out.close();
        return 0;
    }
    if (n == 3) {
        out << arr[0] + arr[2];
        out.close();
        return 0;
    }
    if (n == 4) {
        out << arr[0] + arr[3];
        out.close();
        return 0;
    }
    food[0] = arr[0];
    food[1] = -1;
    food[2] = arr[0] + arr[2];
    for (int i = 3; i < n; i++) {
        food[i] = max(food[i - 3], food[i - 2]) + arr[i];
    }
    out << food[n - 1];
    out.close();
    return 0;
}