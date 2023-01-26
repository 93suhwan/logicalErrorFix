#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int d4x[4] = {1, 0, -1, 0};
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long oo = 1e18;
const long long maxN = 1e6;
void maximize(int &a, int b) { a = max(a, b); }
void minimize(int &a, int b) { a = min(a, b); }
const int N = 505;
const long long MOD = 998244353;
long long dp[N][N], pw[N][N], fact[N], invf[N];
int n, x;
void add(long long &x, long long y) {
  x = x + y;
  if (x < 0) x += MOD;
  if (x >= MOD) x -= MOD;
}
long long Power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return (a % MOD);
  long long T = Power(a, b / 2);
  if (b % 2) return (T * T % MOD * a % MOD);
  return (T * T % MOD);
}
void CnkBuild() {
  const int mxN = 500;
  fact[0] = 1;
  for (int i = 1; i <= mxN; i++) fact[i] = (fact[i - 1] * i) % MOD;
  invf[mxN] = Power(fact[mxN], MOD - 2);
  for (int i = mxN - 1; i >= 0; i--) invf[i] = (invf[i + 1] * (i + 1)) % MOD;
}
long long C(int n, int k) {
  if (n < k || k < 0) return 0;
  return fact[n] * invf[n - k] % MOD * invf[k] % MOD;
}
long long f(int u, int v) {
  if (v > x || v < 1 || u < 1 || u > n) return 0;
  if (dp[u][v] != -1) return dp[u][v];
  dp[u][v] = 0;
  for (int j = 0; j <= n; j++) {
    if (u + j > n) break;
    if (u == 1 && !j) continue;
    int c = u + j;
    add(dp[u][v], f(c, v - c + 1) * 1ll * pw[c - 1][j] % MOD * C(c, j) % MOD);
  }
  return dp[u][v];
}
void solve() {
  cin >> n >> x;
  CnkBuild();
  for (int i = 0; i <= 500; i++) {
    pw[i][0] = 1;
    dp[i][0] = -1;
    for (int j = 1; j <= 500; j++) {
      pw[i][j] = pw[i][j - 1] * 1ll * i % MOD;
      dp[i][j] = -1;
    }
  }
  dp[n][1] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= x; j++) f(i, j);
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) ans = ans * 1ll * x % MOD;
  for (int i = 1; i <= x; i++) {
    long long sub = dp[1][i] * 1ll * (x - i + 1) % MOD;
    add(ans, -sub);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1, ddd = 0;
  while (tc--) {
    solve();
  }
}
