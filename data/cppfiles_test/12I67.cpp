#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
long long st[4 * 200001];
long long binExp(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % 1000000007;
    x = (x * x) % 1000000007;
    n >>= 1;
  }
  return res;
}
long long modInv(long long i) { return binExp(i, 1000000007 - 2); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long d = 0;
    if ((a % 2 == 0) && (c % 2 == 0)) {
      long long u = (a * b) / 2 - c;
      if (u >= a / 2) d = 1;
    }
    if (a % 2 == 1) {
      if (((c - (b / 2)) % 2 == 0) && c >= b / 2) d = 1;
    }
    if (d == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
