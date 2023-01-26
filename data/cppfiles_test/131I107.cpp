#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int down(int x) {
  int w = 1;
  while (w < x) w <<= 1;
  return w - x;
}
int tot = 0;
int node[200005 << 5];
map<int, int> val2id;
int newNode(int val) {
  node[++tot] = val;
  val2id[val] = tot;
  return tot;
}
vector<int> G[200005 << 5];
int dep[200005 << 5];
int vis[200005 << 5];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int u, v;
    if (!val2id.count(a[i]))
      u = newNode(a[i]);
    else
      u = val2id[a[i]];
    int y = a[i];
    while (y) {
      y = down(y);
      if (!val2id.count(y))
        v = newNode(y);
      else
        v = val2id[y];
      G[u].push_back(v), G[v].push_back(u);
      u = v;
    }
  }
  function<void(int)> dfs = [&](int u) {
    for (auto v : G[u]) {
      if (vis[v]) continue;
      vis[v] = 1;
      dep[v] = dep[u] + 1;
      dfs(v);
    }
  };
  dep[1] = 0, vis[1] = 1;
  dfs(1);
  int mi = 0;
  for (int i = 1; i <= tot; i++) {
    if (dep[mi] < dep[i]) mi = i;
  }
  memset(dep, 0, sizeof(dep));
  memset(vis, 0, sizeof(vis));
  vis[mi] = 1;
  dfs(mi);
  int mj = 0;
  for (int i = 1; i <= tot; i++) {
    if (dep[mj] < dep[i]) mj = i;
  }
  int x = node[mi], y = node[mj], z = dep[mj];
  for (int i = 1; i <= n; i++) {
    if (a[i] == x) {
      mi = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != mi && a[i] == y) {
      mj = i;
      break;
    }
  }
  cout << mi << ' ' << mj << ' ' << z;
  return 0;
}
