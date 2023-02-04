#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    
    int n;
    in >> n;

    int* resultArr = new int[n];
    int** graphMatrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        graphMatrix[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        resultArr[i] = 0;
        for (int j = 0; j < n; ++j) {
            in >> graphMatrix[i][j];
        }
    }

    in.close();

    queue<int> q;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (!resultArr[i]) {
            q.push(i);
            resultArr[i] = count + 1;
            ++count;
            while (q.empty() == false) {
                for (int j = 0; j < n; ++j) {
                    int k = q.front();
                    if (graphMatrix[k][j] != 0 && resultArr[j] == 0) {
                        resultArr[j] = count + 1;
                        ++count;
                        q.push(j);
                    }
                }
                q.pop();
            }
        }
    }

    ofstream out("output.txt");

    for (int i = 0; i < n; ++i) {
        out << ((resultArr[i] == 0) ? i + 1 : resultArr[i]) << ' ';
    }

    out.close();

}