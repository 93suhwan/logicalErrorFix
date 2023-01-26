#include <bits/stdc++.h>
using namespace std;
const int N = 14, MOD = 1e9 + 7;
int n;
long long a[N];
long long p[N][N];
long long H[N][1 << N];
long long f[1 << N];
long long g[1 << N];
long long pow_mod(long long x, int n) {
  long long y = 1;
  while (n) {
    if (n & 1) y = (long long)y * x % MOD;
    x = x * x % MOD;
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
      p[i][j] = a[i] * pow_mod(a[i] + a[j], MOD - 2) % MOD;
  int all = (1 << n) - 1;
  for (int i = 0; i < n; i++) {
    H[i][0] = 1;
    for (int j = 0; j < n; j++) H[i][1 << j] = p[i][j];
    for (int S = 1; S <= all; S++)
      H[i][S] = H[i][(S - 1) & S] * H[i][-S & S] % MOD;
  }
  int ans = 0;
  for (int S = 1; S < 1 << n; S++) {
    g[0] = 1;
    for (int tS = (S - 1) & S; tS; tS = (tS - 1) & S) {
      int mask = S ^ tS;
      int x = __builtin_ffs(mask) - 1;
      g[mask] = g[mask ^ (1 << x)] * H[x][all ^ S] % MOD;
      f[S] = (f[S] - f[tS] * g[mask]) % MOD;
    }
    int x = __builtin_ffs(S) - 1;
    g[S] = g[S ^ (1 << x)] * H[x][all ^ S] % MOD;
    f[S] = (f[S] + g[S]) % MOD;
    ans = (ans + f[S] * __builtin_popcount(S)) % MOD;
  }
  cout << (ans + MOD) % MOD << "\n";
}
