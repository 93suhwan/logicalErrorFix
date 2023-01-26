#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > g(n * 31);
  vector<int> ix, a(n);
  int tot = 0;
  auto id = [&](const int &x) {
    static map<int, int> idx;
    if (!idx.count(x)) ix.push_back(x), idx[x] = ix.size();
    return idx[x];
  };
  function<void(int)> path_to_root;
  path_to_root = [&](const int &x) {
    static vector<bool> vis(n * 31);
    int k = 0;
    while ((1 << k) < x) k++;
    int fa = (1 << k) - x;
    int ix = id(x), ifa = id(fa);
    if (fa && !vis[ifa]) path_to_root(fa);
    g[ifa].push_back(ix);
    g[ix].push_back(ifa);
    vis[ix] = 1;
  };
  array<int, 3> ans = {0, 0, 0};
  vector<int> d(n * 31);
  auto bfs = [&](int u) {
    vector<bool> vis(n * 31, 0);
    queue<int> q;
    d[u] = 0;
    vis[u] = 1;
    q.push(u);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int v : g[u])
        if (!vis[v]) {
          vis[v] = 1;
          d[v] = d[u] + 1;
          q.push(v);
        }
    }
  };
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    a[i] = x;
    path_to_root(x);
  }
  d[id(0)] = 0;
  bfs(id(0));
  int p = 1;
  for (int i = 1; i <= ix.size(); i++)
    if (d[i] > d[p]) p = i;
  d[p] = 0;
  bfs(p);
  int q = 1;
  for (int i = 1; i <= ix.size(); i++)
    if (d[i] > d[q]) q = i;
  int x, y;
  for (int i = 0; i < n; i++) {
    if (a[i] == ix[p - 1]) x = i + 1;
    if (a[i] == ix[q - 1]) y = i + 1;
  }
  cout << x << ' ' << y << ' ' << d[q] << endl;
  return 0;
}
