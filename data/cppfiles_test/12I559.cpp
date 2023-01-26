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
    if (a % 2 == c % 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
