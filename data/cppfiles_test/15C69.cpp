#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 105;
long long f[N][N];
long long cnt[N][N];
vector<int> q[N];
int maxn = 0;
void dfs(int rt, int u, int fa, int dep) {
  cnt[rt][dep]++;
  maxn = max(maxn, dep);
  for (auto &v : q[u]) {
    if (v == fa) continue;
    dfs(rt, v, u, dep + 1);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
      q[i].clear();
    }
    for (int i = 1; i <= n - 1; i++) {
      int u, v;
      cin >> u >> v;
      q[u].push_back(v);
      q[v].push_back(u);
    }
    if (k == 2) {
      cout << (long long)n * (n - 1) % mod / 2 % mod << '\n';
      continue;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      memset(cnt, 0, sizeof cnt);
      int mx_d = 0;
      for (auto &u : q[i]) {
        maxn = 0;
        dfs(u, u, i, 0);
        mx_d = max(mx_d, maxn);
      }
      for (int w = 0; w <= mx_d; w++) {
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        f[0][1] = cnt[q[i][0]][w];
        for (int ii = 1; ii < q[i].size(); ii++) {
          f[ii][0] = 1;
          for (int j = 1; j <= min(k, ii + 1); j++)
            f[ii][j] = (f[ii - 1][j] +
                        (long long)f[ii - 1][j - 1] * cnt[q[i][ii]][w] % mod) %
                       mod;
        }
        ans = (ans + f[q[i].size() - 1][k]) % mod;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
