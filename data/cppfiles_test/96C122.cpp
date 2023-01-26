#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510, mod = 998244353;
long long power(long long a, long long n) {
  if (!n) return 1;
  long long tmp = power(a, n / 2);
  tmp = tmp * tmp % mod;
  if (n & 1) tmp = tmp * a % mod;
  return tmp;
}
long long n, x, f[MAXN][MAXN], c[MAXN][MAXN], g[MAXN][MAXN];
void dp() {
  for (int i = (2); i <= (n); i++) {
    for (int j = (1); j <= (x); j++) {
      if (j < i) {
        f[i][j] = power(j, i);
        continue;
      }
      f[i][j] = power(i - 1, i);
      for (int cnt = (0); cnt <= (i - 1); cnt++) {
        long long val = c[i][cnt] * g[i - 1][cnt] % mod;
        val = val * f[i - cnt][j - (i - 1)] % mod;
        f[i][j] = (f[i][j] + val) % mod;
      }
    }
  }
}
int main() {
  c[0][0] = 1;
  for (int i = (1); i <= (500); i++) {
    c[i][0] = 1;
    for (int j = (1); j <= (i); j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    for (int j = (0); j <= (500); j++) {
      g[i][j] = power(i, j);
    }
  }
  cin >> n >> x;
  dp();
  cout << f[n][x];
  return 0;
}
