#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 7, mod = 998244353;
long long f[N];
long long qmi(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a, res %= mod;
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return res;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i <= n; i++) f[i] = 0;
    long long cnt = 0, sum = 0;
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      if (x == 0)
        cnt++, f[0]++;
      else if (x == 1)
        sum += qmi(2, f[x - 1]);
      else
        sum += f[x - 1] + f[x - 2];
      f[x] += f[x - 1];
      f[x] %= mod;
      sum %= mod;
    }
    cout << (sum + qmi(2, cnt) - 1 + mod) % mod << endl;
  }
  return 0;
}
