#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#define p pair<int, long long>

using namespace std;

const int MAX = INT32_MAX;

int main() {
    ifstream in("input.txt");
    int n, m;
    in >> n >> m;

    vector<vector<p>> matrixGraph(n);

    for (int i = 0; i < m; ++i) {
        int b, e, w;
        in >> b >> e >> w;
        p temp(b - 1, w);
        p temp2(e - 1, w);
        matrixGraph[e - 1].push_back(temp);
        matrixGraph[b - 1].push_back(temp2);
    }

    in.close();

    long long* distance = new long long[n];

    distance[0] = 0;

    for (int i = 1; i < n; ++i) {
        distance[i] = MAX;
    }

    set<p> q;

    p temp(0, 0);
    q.insert(temp);

    while (q.empty() == false) {
        int v = q.begin()->first;
        q.erase(q.begin());

        for (int i = 0; i < matrixGraph[v].size(); ++i) {
            int v2 = matrixGraph[v][i].first;
            long long w = matrixGraph[v][i].second;

            if (distance[v2] > distance[v] + w) {
                temp = p(v2, distance[v2]);
                q.erase(temp);
                distance[v2] = distance[v] + w;
                temp = p(v2, distance[v2]);
                q.insert(temp);
            }            
        }
    }

    ofstream out("output.txt");
    out << distance[n-1] << endl;
    out.close();    
}