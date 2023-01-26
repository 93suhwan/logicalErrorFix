#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans *= a;
    }
    a *= a;
    b >>= 1;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    long long n, k;
    cin >> n >> k;
    if (n == 1)
      cout << 0 << endl;
    else if (k == 1)
      cout << n - 1 << endl;
    else {
      long long bef = 0;
      long long t = 1;
      while (t <= k and t <= n) {
        t *= 2;
        bef++;
      }
      n = n - t;
      cout << ceil(n / (float)k) + bef << endl;
    }
  }
}
