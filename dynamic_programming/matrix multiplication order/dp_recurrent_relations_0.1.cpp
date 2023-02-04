#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream in("input.txt");
	size_t n = 0;
	in >> n;
	pair<int, int>* matrix = new pair<int, int>[n];
	for (size_t i = 0; i < n; ++i) {
		in >> matrix[i].first >> matrix[i].second;
	}
	in.close();
	int** dp = new int* [n];
	for (size_t i = 0; i < n; i++) {
		dp[i] = new int[n];
	}
	for (size_t i = 0; i < n; i++) {
		dp[i][i] = 0;
	}
	int min;
	int value;
	for (size_t j = 1; j < n; j++) {
		for (int i = j - 1; i >= 0; i--) {
			min = INT_MAX;
			for (size_t k = i; k < j; k++) {
				value = dp[i][k] + dp[k + 1][j] + matrix[i].first * matrix[k].second * matrix[j].second;
				if (value < min) {
					min = value;
				}
			}
			dp[i][j] = min;
		}
	}
	ofstream out("output.txt");
	out << dp[0][n - 1] << endl;
	out.close();
	return 0;
}