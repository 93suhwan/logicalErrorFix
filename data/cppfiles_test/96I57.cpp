#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MAXN = 5e2 + 10;
const double eps = 1e-8;
const int mod = 1e9 + 7;
ll n, m, k, t, l, r, tot = 0, ans = 0, b[MAXN], a[MAXN];
ll C[MAXN][MAXN], pw[MAXN][MAXN], dp[MAXN][MAXN];
char s[MAXN];
ll ksm(ll a, ll b) {
  ll t = a, y = 1;
  while (b) {
    if (b & 1) y = y * t % mod;
    t = t * t % mod;
    b >>= 1;
  }
  return y;
}
void add(ll &x, ll y) {
  x = (x + y) % mod;
  return;
}
void solve() {
  for (int i = 0; i <= k; i++) dp[0][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      if (j < i)
        dp[i][j] = pw[j][i];
      else {
        for (int t = 0; t <= i; t++)
          add(dp[i][j], dp[i - t][j - i + 1] * C[i][t] % mod *
                            pw[min(i - 1, j)][t] % mod);
      }
    }
  cout << dp[n][k] << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  C[0][0] = pw[0][0] = 1;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= n; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) pw[i][j] = ksm(i, j);
  solve();
  return 0;
}
