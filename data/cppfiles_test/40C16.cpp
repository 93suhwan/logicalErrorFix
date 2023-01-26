#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, mod = 1e9 + 7;
const long long INF = 1e18;
const int N = 3e5 + 10;
int n, m, q;
int a[N], b[N], cnt[N];
vector<int> G[N];
int fa[N];
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
int path[N], idx;
void dfs(int u, int end, int fa) {
  path[++idx] = u;
  if (u == end) {
    cout << idx << "\n";
    for (int i = 1; i <= idx; i++) cout << path[i] << " ";
    cout << "\n";
    return;
  }
  for (int v : G[u]) {
    if (v == fa) continue;
    dfs(v, end, u);
  }
  idx--;
}
int main() {
  cin >> n >> m;
  iota(fa + 1, fa + 1 + n, 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    int fa_u = find(u);
    int fa_v = find(v);
    if (fa_u != fa_v) {
      fa[fa_u] = fa_v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i];
    cnt[a[i]]++, cnt[b[i]]++;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += cnt[i] % 2;
  if (sum) {
    cout << "NO\n" << sum / 2;
  } else {
    cout << "YES\n";
    for (int i = 1; i <= q; i++) {
      idx = 0;
      dfs(a[i], b[i], -1);
    }
  }
  return 0;
}
