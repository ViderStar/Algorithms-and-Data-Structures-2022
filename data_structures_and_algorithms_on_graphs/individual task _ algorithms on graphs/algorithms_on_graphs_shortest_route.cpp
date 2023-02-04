#include <iostream>
#include <fstream>
#define MAX INT32_MAX

using namespace std;

int main() {
    ifstream in("input.txt");
    int n, m;
    in >> n >> m;

    int** matrix = new int*[n];
    int* distance = new int[n];
    int* vertexWeight = new int[n];
    bool* isVisited = new bool[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
        distance[i] = MAX;
        vertexWeight[i] = 0;
        isVisited[i] = false;
    }

    for (int i = 0; i < m; ++i) {
        int v1, v2, w;
        in >> v1 >> v2 >> w;
        matrix[v1 - 1][v2 - 1] = w + 1;
        matrix[v2 - 1][v1 - 1] = w + 1;
        ++vertexWeight[v1 - 1];
        ++vertexWeight[v2 - 1];
    }

    int start, final, q;
    in >> start >> final >> q;
    in.close();

    distance[start - 1] = 0;

    for (int i = 0; i < n; ++i) {
        if (!isVisited[final - 1]) {
            int v, distV = MAX;

            for (int j = 0; j < n; ++j) {
                if (isVisited[j] == false && distance[j] < distV) {
                    v = j;
                    distV = distance[j];
                }
            }

            if (distV == MAX) {
                break;
            }

            for (int j = 0; j < n; ++j) {
                int resultDist = distance[v] + matrix[v][j] + vertexWeight[v] * q - 1;
                distance[j] = matrix[v][j] && resultDist < distance[j] ? resultDist : distance[j];
            }
            isVisited[v] = true;
        }
        else {
            break;
        }
    }

    ofstream out("output.txt");
    if (distance[final - 1] == MAX) {
        out << "No";
    }
    else {
        out << "Yes\n";
        out << distance[final - 1];
    }
    out.close();
}