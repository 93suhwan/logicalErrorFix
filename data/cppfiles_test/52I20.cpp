#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long temp = log2(k);
    long long terms = pow(2, temp);
    if (k == terms) {
      long long var = pow(n, temp);
      cout << var % m << "\n";
    } else {
      long long left = k - terms;
      long long ans = pow(n, temp);
      while (left > 0) {
        long long go = log2(left);
        long long ter = pow(2, go);
        left = left - ter;
        ans = ans + pow(n, go);
      }
      cout << (ans % m) << "\n";
    }
  }
}
