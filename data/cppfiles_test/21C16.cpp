#include <bits/stdc++.h>
using namespace std;
const int _ = 105;
int dp[_][_][_];
int vis[_][_][_];
int n, m, k, p;
int c[_][_];
int vc[_][_];
int tab[_];
int C(int u, int d) {
  if (u < 0 || u > d) return 0;
  if (vc[u][d]) return c[u][d];
  vc[u][d] = 1;
  if (u == 0 || u == d) return c[u][d] = 1;
  return c[u][d] = (C(u, d - 1) + C(u - 1, d - 1)) % p;
}
int Dp(int l, int s, int d) {
  if (vis[l][s][d]) return dp[l][s][d];
  vis[l][s][d] = 1;
  if (l < d) return dp[l][s][d] = 0;
  if (l < s) return dp[l][s][d] = (d == 0 ? tab[l] : 0);
  if (s == 1) return dp[l][s][d] = (d == 1 ? tab[l] : 0);
  for (int a = 1; a <= l; a++) {
    int tp = 0, mi = min(a - 1, d);
    for (int x = max(0, d + a - l); x <= mi; x++) {
      tp += (1ll * Dp(a - 1, s - 1, x) * Dp(l - a, s - 1, d - x)) % p;
      tp %= p;
    }
    dp[l][s][d] += 1ll * C(a - 1, l - 1) * tp % p;
    dp[l][s][d] %= p;
  }
  return dp[l][s][d];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> p;
  tab[0] = 1;
  for (int i = 1; i <= 100; i++) tab[i] = 1ll * tab[i - 1] * i % p;
  cout << Dp(n, m, k) << endl;
  return 0;
}
