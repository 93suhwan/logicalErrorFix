#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
vector<int> edges[MAX];
int n, m, d[MAX], col[MAX];
int fa[MAX], deep[MAX], siz[MAX], son[MAX];
int top[MAX], id[MAX], idx;

void add(int u, int v) {
  edges[u].push_back(v);
  edges[v].push_back(u);
}

void dfs1(int u, int pre, int dep) {
  fa[u] = pre;
  deep[u] = dep;
  siz[u] = 1;
  for (auto& v : edges[u]) {
    if (v == pre) continue;
    dfs1(v, u, dep + 1);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}

void dfs2(int u, int utop) {
  top[u] = utop;
  id[u] = ++idx;
  if (son[u]) dfs2(son[u], utop);
  for (auto& v : edges[u]) {
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
  }
  dfs1(1, 0, 1);
  dfs2(1, 1);
  vector<pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    s.emplace_back(deep[i] - deep[top[i]], i);
  }
  sort(s.begin(), s.end(), greater<>());
  int red = 0, blue = 0;
  for (auto& [x, u] : s) {
    if (red == m) break;
    if (d[u]) continue;
    ++red;
    col[u] = 1;
    while (u && !d[u]) {
      d[u] = 1;
      u = fa[u];
    }
  }
  if (red < m) {
    if (abs((red - (n - red))) <= 1) {
      cout << (long long)(n - red) * red << "\n";
    } else {
      int p = max(red, min(n / 2, m));
      cout << (long long)(n - p) * p << "\n";
    }
  } else {
    for (int i = 1; i <= n; i++) {
      blue += (d[i] == 0);
    }
    cout << (long long)(n - red - blue) * (red - blue) << "\n";
  }
  return 0;
}
