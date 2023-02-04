#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {
    ifstream in("input.txt");
    int n, m;
    in >> n >> m;

    list<int>* matrix = new list<int>[n];

    int a, b;
    for (int i = 0; i < m; ++i) {
        in >> a >> b;
        matrix[a - 1].push_front(b);
        matrix[b - 1].push_front(a);
    }

    in.close();

    ofstream out("output.txt");
    for (int i = 0; i < n; ++i) {
        list <int> ::iterator it = matrix[i].begin();
        int size = matrix[i].size();
        out << size << ' ';
        for (int j = 0; j < size; ++j) {
            out << *it++ << ' ';
        }
        out << '\n';
    }
    
    return 0;
}