#include <bits/stdc++.h>
using namespace std;
const long long maxn = 109;
const long long mod = 1e9 + 7;
vector<long long> vec[maxn];
long long deep[maxn], zi[maxn][maxn], n, k;
void dfs(long long u, long long father, long long rt) {
  deep[u] = deep[father] + 1;
  zi[rt][deep[u]]++;
  for (auto v : vec[u]) {
    if (v == father) continue;
    dfs(v, u, rt);
  }
}
long long f[maxn][maxn], w[maxn];
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
      vec[l].push_back(r);
      vec[r].push_back(l);
    }
    if (k == 2)
      cout << n * (n - 1) / 2 << endl;
    else {
      long long res = 0;
      for (long long i = 1; i <= n; i++) {
        deep[i] = 0;
        for (auto v : vec[i]) dfs(v, i, v);
        for (long long j = 1; j <= n; j++) {
          w[0] = 0;
          for (auto v : vec[i]) w[++w[0]] = zi[v][j];
          res = (res + DP()) % mod;
        }
        for (auto v : vec[i])
          for (long long j = 1; j <= n; j++) zi[v][j] = 0;
      }
      cout << res << endl;
    }
    for (long long i = 1; i <= n; i++) vec[i].clear();
  }
}
