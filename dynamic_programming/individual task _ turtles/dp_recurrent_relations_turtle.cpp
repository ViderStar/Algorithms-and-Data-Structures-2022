#include <iostream>
#include <fstream>
#include <algorithm>

const unsigned int d = 1e9 + 7;

int main() {
  std::ifstream in("input.txt");

  int n, m;
  in >> n;
  in >> m;

  in.close();

  int maxL = std::max(n, m);
  int minL = std::min(n, m);

  unsigned int** dp = new unsigned int*[maxL];

  for (int i = 0; i < maxL; ++i) {
    dp[i] = new unsigned int[i + 1];
    dp[i][0] = 1;
  }

  for (int i = 1; i < maxL; ++i) {
    for (int j = 1; j < i; ++j) {
      dp[i][j] = (dp[i][j - 1] % d + dp[i - 1][j] % d) % d;
    }
    dp[i][i] = ((dp[i][i - 1] % d) * 2) % d;
  }

  std::ofstream out("output.txt");

  out << dp[maxL - 1][minL - 1] % d;

  out.close();
}