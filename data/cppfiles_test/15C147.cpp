#include <bits/stdc++.h>
using namespace std;
const long long N = 100 + 10;
const long long mod = 1e9 + 7;
vector<long long> G[N];
long long deep[N], st[N][N], n, k;
void dfs(long long u, long long father, long long rt) {
  deep[u] = deep[father] + 1;
  st[rt][deep[u]]++;
  for (auto v : G[u]) {
    if (v == father) continue;
    dfs(v, u, rt);
  }
}
long long f[N][N], w[N];
void upd(long long &x, long long y) { x = (x + y) % mod; }
long long DP() {
  for (long long i = 1; i <= w[0]; i++)
    for (long long j = 0; j <= i && j <= k; j++) f[i][j] = 0;
  f[0][0] = 1;
  for (long long i = 1; i <= w[0]; i++)
    for (long long j = 0; j <= i && j <= k; j++) {
      if (j) upd(f[i][j], f[i - 1][j - 1] * w[i] % mod);
      upd(f[i][j], f[i - 1][j]);
    }
  return f[w[0]][k];
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (long long i = 1; i < n; i++) {
      long long l, r;
      scanf("%lld%lld", &l, &r);
      G[l].push_back(r);
      G[r].push_back(l);
    }
    if (k == 2)
      cout << n * (n - 1) / 2 << endl;
    else {
      long long res = 0;
      for (long long i = 1; i <= n; i++) {
        deep[i] = 0;
        for (auto v : G[i]) dfs(v, i, v);
        for (long long j = 1; j <= n; j++) {
          w[0] = 0;
          for (auto v : G[i]) w[++w[0]] = st[v][j];
          res = (res + DP()) % mod;
        }
        for (auto v : G[i])
          for (long long j = 1; j <= n; j++) st[v][j] = 0;
      }
      cout << res << endl;
    }
    for (long long i = 1; i <= n; i++) G[i].clear();
  }
}
