#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n, 1);  // 1 - element stored, 2 - element deleted
    int part = ceil(sqrt(n));
    vector<int> decomp(part);  // sum of part
    // fill decomp
    for (int i = 0; i < n; i++){
        decomp[i/part] += v[i];
    }

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        // find k-th element
        int pos = 0;
        int sum = 0;
        while (sum < k){
            sum += decomp[pos];
            pos++;
        }
        pos--;
        sum -= decomp[pos];
        int ind_from = pos * part;
        while(sum < k){
            sum += v[ind_from];
            ind_from++;
        }
        ind_from--;
        cout << ind_from + 1 << " ";
        v[ind_from] = 0;
        decomp[pos]--;
    }
    return 0;
}