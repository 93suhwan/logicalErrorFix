#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, mod = 998244353;
long long c[maxn][maxn], f[maxn][maxn];
long long qpow(long long a, int b) {
  long long res(1);
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  cin.sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, x;
  c[0][0] = 1;
  for (int i = 1; i <= 500; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      if (c[i][j] >= mod) c[i][j] -= mod;
    }
  }
  for (int i = 1; i <= 500; ++i) f[2][i] = i;
  for (int i = 3; i <= 500; ++i) {
    for (int j = 1; j < i; ++j) f[i][j] = qpow(j, i);
    for (int j = i; j <= 500; ++j) {
      for (int k = i - 2; ~k; --k) {
        f[i][j] =
            (c[i][k] * qpow(i - 1, k) % mod * f[i - k][j - (i - 1)] + f[i][j]) %
            mod;
      }
      f[i][j] += f[i][i - 1];
      if (f[i][j] >= mod) f[i][j] -= mod;
    }
  }
  cin >> n >> x;
  cout << f[n][x] << '\n';
  return 0;
}
