#include <bits/stdc++.h>
using namespace std;
const long long N = 2e2 + 10;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const long long INF = 0x3f3f3f3f;
long long n, k;
long long ne[N], h[N], e[N], idx = 1;
long long dp[N][N], cnt[N][N];
void add(long long a, long long b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void dfs(long long u, long long fa) {
  cnt[u][0] = 1;
  for (long long i = h[u]; i; i = ne[i]) {
    long long j = e[i];
    if (j == fa) continue;
    dfs(j, u);
    for (long long deep = 1; deep <= n; deep++)
      cnt[u][deep] += cnt[j][deep - 1];
  }
}
long long slove(long long u) {
  memset(cnt, 0, sizeof(cnt));
  dfs(u, -1);
  vector<long long> son;
  son.push_back(-1);
  for (long long i = h[u]; i; i = ne[i]) son.push_back(e[i]);
  long long len = (long long)son.size(), res = 0;
  for (long long d = 0; d <= n; d++) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (long long i = 1; i < len; i++) {
      if (cnt[son[i]][d] == 0) continue;
      for (long long j = 0; j <= n; j++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        if (j > 0)
          dp[i][j] =
              (dp[i][j] + (dp[i - 1][j - 1] * cnt[son[i]][d] % mod)) % mod;
      }
    }
    res = (res + dp[len - 1][k]) % mod;
  }
  return res;
}
signed main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    for (long long i = 1; i <= idx; i++) h[i] = 0;
    idx = 1;
    cin >> n >> k;
    for (long long i = 1; i < n; i++) {
      long long a, b;
      cin >> a >> b;
      add(a, b);
      add(b, a);
    }
    long long ans = 0;
    if (k == 2)
      ans = (n * (n - 1) / 2) % mod;
    else
      for (long long root = 1; root <= n; root++)
        ans = (ans + slove(root)) % mod;
    cout << ans << endl;
  }
  return 0;
}
