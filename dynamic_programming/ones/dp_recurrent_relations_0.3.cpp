#include <iostream>

using namespace std;


    
 
int main() {

	int n;
	int k;
	cin >> n >> k;
    if (k > n) {
        cout << "0";
        return 0;
    }
	unsigned long long numerator = 1, denominator = 1, m = 1, count, answer;
    const int rem = 1000000007;
    int mem = 1000000005;

    for (int i = n; i > n - k; --i)
        numerator = (numerator * i) % rem;
    for (int i = 1; i <= k; ++i) {
        denominator = (denominator * i) % rem;
    }
    while (mem > 0) {
        if (mem % 2 == 1) {
            m = (m * denominator) % rem;
        }
        denominator = (denominator * denominator) % rem;
        mem >>= 1;
    }
    answer = (numerator * m) % rem;
	cout << answer;
	return 0;
}