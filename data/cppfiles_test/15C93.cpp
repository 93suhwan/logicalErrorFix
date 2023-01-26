#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  int ch = getchar(), f = 1;
  long long x = 0;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return f * x;
}
int solve();
int main() {
  for (int t = read(); t--; solve())
    ;
  return 0;
}
const int mod = 1e9 + 7;
vector<vector<int>> e(105);
int cnt[105];
long long sum[105][105];
long long fac[105], inv[105];
long long qpow(long long x, long long k) {
  long long ans = 1;
  for (; k; k >>= 1, x = x * x % mod) {
    if (k & 1) ans = ans * x % mod;
  }
  return ans;
}
void dfs(int x, int fa, int dep) {
  cnt[dep]++;
  for (auto t : e[x]) {
    if (t == fa) continue;
    dfs(t, x, dep + 1);
  }
}
long long C(int n, int m) {
  if (n < m) return 0;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int n, k;
int solve() {
  n = read(), k = read();
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = fac[i - 1] * i % mod, inv[i] = qpow(fac[i], mod - 2);
  if (k == 1) {
    for (int i = 1; i < n; ++i) read(), read();
    cout << n << endl;
    return 0;
  }
  if (k == 2) {
    for (int i = 1; i < n; ++i) read(), read();
    cout << 1ll * n * (n - 1) / 2 % mod << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i) e[i].clear();
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  long long ans = 0;
  memset(sum, 0, sizeof sum);
  for (int i = 1; i <= n; ++i) {
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= n; ++i) sum[i][0] = 1;
    for (auto t : e[i]) {
      memset(cnt, 0, sizeof cnt);
      dfs(t, i, 1);
      for (int d = 1; d <= n; ++d) {
        for (int j = k; j >= 1; --j) {
          sum[d][j] += sum[d][j - 1] * cnt[d] % mod;
          sum[d][j] %= mod;
        }
      }
    }
    for (int d = 1; d <= n; ++d) ans += sum[d][k], ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
