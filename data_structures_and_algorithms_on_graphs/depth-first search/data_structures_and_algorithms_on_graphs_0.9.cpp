#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    
    int n;
    in >> n;

    int* resultArr = new int[n];
    int* isVisited = new int[n];
    int** graphMatrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        graphMatrix[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        resultArr[i] = 0;
        isVisited[i] = false;
        for (int j = 0; j < n; ++j) {
            in >> graphMatrix[i][j];
        }
    }

    in.close();

    stack<int> s;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            s.push(i);
            resultArr[i] = count + 1;
            ++count;
            while (s.empty() == false) {
                int k = s.top();
                bool isTop = false;
                for (int j = 0; j < n; ++j) {
                    if (graphMatrix[k][j] == 1 && !isVisited[j]) {
                        isVisited[j] = true;
                        resultArr[j] = count + 1;
                        ++count;
                        s.push(j);
                        isTop = true;
                        break;
                    }
                }
                if (!isTop) {
                    s.pop();
                }
            }
        }
    }

    ofstream out("output.txt");

    for (int i = 0; i < n; ++i) {
        out << ((resultArr[i] == 0) ? i + 1 : resultArr[i]) << ' ';
    }

    out.close();

}