#include <bits/stdc++.h>
using namespace std;
const int N = 555 + 5, M = 2e5 + 5, mod = 998244353, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = (c * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return c % mod;
}
long long inv(long long x) { return qpow(x, mod - 2); }
int a[N], b[N];
vector<int> g;
long long f[N][N];
long long C[N][N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= 500; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j <= i - 1)
        f[i][j] = qpow(j, i);
      else {
        for (int k = 2; k <= i; k++) {
          f[i][j] = (f[i][j] + f[k][j - i + 1] * qpow(i - 1, i - k) % mod *
                                   C[i][k] % mod) %
                    mod;
        }
        f[i][j] = (f[i][j] + qpow(i - 1, i)) % mod;
      }
    }
  }
  cout << f[n][m] << endl;
}
