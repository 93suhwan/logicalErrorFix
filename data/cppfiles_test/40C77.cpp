#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, qq;
vector<int> to[N], res[N];
int sum[N], up[N], dep[N];
void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  up[u] = fa;
  for (int v : to[u])
    if (v != fa && !dep[v]) dfs(v, u);
}
int ss = 0;
void sol(int u, int fa) {
  if (sum[u] % 2) ++ss;
  for (int v : to[u]) {
    if (v != fa && dep[v] == dep[u] + 1) {
      sol(v, u);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  dfs(1, 1);
  cin >> qq;
  for (int i = 1; i <= qq; i++) {
    cin >> u >> v;
    vector<int> tmp;
    while (dep[v] > dep[u]) {
      tmp.push_back(v);
      v = up[v];
    }
    while (dep[u] > dep[v]) {
      res[i].push_back(u);
      u = up[u];
    }
    while (u != v) {
      res[i].push_back(u);
      tmp.push_back(v);
      u = up[u];
      v = up[v];
    }
    res[i].push_back(u);
    for (int j = tmp.size() - 1; j >= 0; j--) res[i].push_back(tmp[j]);
    for (int j = 0; j < res[i].size(); j++) {
      if (j != 0 && j != res[i].size() - 1) ++sum[res[i][j]];
      ++sum[res[i][j]];
    }
  }
  sol(1, 1);
  if (ss == 0) {
    cout << "YES" << endl;
    for (int i = 1; i <= qq; i++) {
      cout << res[i].size() << endl;
      for (int j : res[i]) cout << j << ' ';
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
    cout << ss / 2 << endl;
  }
  return 0;
}
