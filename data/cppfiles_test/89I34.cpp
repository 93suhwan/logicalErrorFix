#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int dep[maxn], id = -1, flag[maxn], sta[maxn], cnt[maxn];
vector<int> g[maxn];
int ans = 0;
void dfs(int u, int f) {
  dep[u] = dep[f] + 1;
  bool ok = false;
  for (auto v : g[u]) {
    if (v == f) continue;
    ok = true;
    dfs(v, u);
  }
  if (!ok) {
    if (id == -1 || dep[id] > dep[u]) {
      id = u;
    }
    ans++;
  }
}
bool dfs2(int u, int f) {
  if (u == id) {
    flag[u] = 1;
    return true;
  }
  for (auto v : g[u]) {
    if (v == f) continue;
    if (dfs2(v, u)) {
      flag[u] = 1;
      return true;
    }
  }
  return false;
}
void dfs3(int u, int f) {
  int ct = 0, ct2 = 0, fg = false;
  for (auto v : g[u]) {
    if (v == f) continue;
    dfs3(v, u);
    ct++;
    if (!flag[v]) {
      cnt[u] += cnt[v];
      ct2 += sta[v];
    } else
      fg = true, cnt[u] += cnt[v];
  }
  if (!ct) return;
  if (!fg) {
    if (ct > ct2) {
      cnt[u]++;
      sta[u] = 1;
    } else if (ct == ct2) {
      if (u != 1) cnt[u]--;
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) cnt[i] = sta[i] = flag[i] = 0, g[i].clear();
    id = -1;
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    dfs3(1, 0);
    ans -= cnt[1];
    printf("%d\n", ans);
  }
}
