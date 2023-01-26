#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, m, k, p[N], ct[N], mt[N], fk;
bool G[N][N];
long long A[N], ans;
pair<int, int> d[N];
bool f[1 << N][N];
unordered_map<int, bool> ok;
inline bool solve() {
  int hsh = 0, tot = 0;
  for (int i = 1; i <= n; ++i)
    if (mt[i] > i) d[++tot] = make_pair(i, mt[i]), hsh = hsh * 12 + mt[i] - 1;
  if (ok.count(hsh)) return ok[hsh];
  int st = 1 << tot;
  for (int i = 0; i < st; ++i)
    for (int j = 1; j <= tot; ++j) f[i][j] = 0;
  for (int i = 1; i <= tot; ++i)
    if (G[d[i].first][d[i].second]) f[1 << (i - 1)][i] = 1;
  for (int i = 0; i < st; ++i)
    for (int j = 1; j <= tot; ++j)
      if (f[i][j]) {
        int u = d[j].first, v = d[j].second;
        for (int t = 0; t < tot; ++t)
          if (!(i & (1 << t)))
            if ((G[u][d[t + 1].first] & G[v][d[t + 1].second]) ||
                (G[u][d[t + 1].second] & G[v][d[t + 1].first]))
              f[i | (1 << t)][t + 1] = 1;
      }
  for (int i = 1; i <= tot; ++i)
    if (f[st - 1][i]) return ok[hsh] = true;
  return ok[hsh] = false;
}
bool dfs2(int u) {
  if (u >= n) return solve();
  if (mt[u]) return dfs2(u + 1);
  for (int i = u + 1; i <= n; ++i)
    if (!mt[i] && p[u] == p[i]) {
      mt[i] = u, mt[u] = i;
      if (dfs2(u + 1)) return true;
      mt[i] = 0, mt[u] = 0;
    }
  return false;
}
inline void work() {
  for (int i = 1; i <= k; ++i) ct[i] = 0;
  for (int i = 1; i <= n; ++i) ++ct[p[i]], mt[i] = 0;
  for (int i = 1; i <= k; ++i)
    if (ct[i] & 1) return;
  if (dfs2(1)) printf("%d\n", ++fk), ans += A[*max_element(p + 1, p + n + 1)];
}
void dfs1(int pos) {
  if (pos > n) return work();
  int mx = 0;
  for (int i = 1; i < pos; ++i) mx = max(mx, p[i]);
  for (int i = 1; i <= min(k, mx + 1); ++i) p[pos] = i, dfs1(pos + 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    A[i] = 1;
    for (int j = k; j >= k - i + 1; --j) A[i] *= j;
  }
  for (int i = 1, u, v; i <= m; ++i)
    scanf("%d%d", &u, &v), G[u][v] = G[v][u] = 1;
  dfs1(1);
  printf("%lld\n", ans);
  return 0;
}
