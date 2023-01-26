#include <bits/stdc++.h>
using namespace std;
const int N = 14, MOD = 1e9 + 7;
int n;
int a[N];
int p[N][N];
int H[N][1 << N];
int f[1 << N];
int g[1 << N];
int pow_mod(int x, int n) {
  int y = 1;
  while (n) {
    if (n & 1) y = 1LL * y * x % MOD;
    x = 1LL * x * x % MOD;
    n >>= 1;
  }
  return y;
}
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      p[i][j] = 1LL * a[i] * pow_mod(a[i] + a[j], MOD - 2) % MOD;
  int all = (1 << n) - 1;
  for (int i = 0; i < n; i++) {
    H[i][0] = 1;
    for (int j = 0; j < n; j++) H[i][1 << j] = p[i][j];
    for (int S = 1; S <= all; S++)
      H[i][S] = 1LL * H[i][(S - 1) & S] * H[i][-S & S] % MOD;
  }
  int ans = 0;
  for (int S = 1; S < 1 << n; S++) {
    g[0] = 1;
    for (int tS = (S - 1) & S; tS; tS = (tS - 1) & S) {
      int mask = S ^ tS;
      int x = __builtin_ffs(mask) - 1;
      g[mask] = 1LL * g[mask - (-mask & mask)] * H[x][all ^ S] % MOD;
      f[S] = (f[S] - 1LL * f[tS] * g[mask]) % MOD;
    }
    int x = __builtin_ffs(S) - 1;
    g[S] = 1LL * g[S - (-S & S)] * H[x][all ^ S] % MOD;
    f[S] = (f[S] + g[S]) % MOD;
    ans = (ans + 1LL * f[S] * __builtin_popcount(S)) % MOD;
  }
  cout << (ans + MOD) % MOD << "\n";
}
