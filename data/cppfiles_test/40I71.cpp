#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
int dx[2] = {
    -1,
    0,
};
int dy[2] = {0, -1};
const int N = 300005;
int n, m;
vector<int> g[N];
int p[N], sp[21][N], depth[N], cnt[N];
int find(int x) {
  if (p[x] == x)
    return x;
  else
    return p[x] = find(p[x]);
}
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) p[x] = y;
}
void dfs(int v, int p) {
  sp[0][v] = p;
  for (int nv : g[v]) {
    if (nv == p) continue;
    depth[nv] = depth[v] + 1;
    dfs(nv, v);
  }
}
int LCA(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  int diff = depth[x] - depth[y];
  for (int i = 0; i < 21; i++) {
    if (diff & (1 << i)) x = sp[i][x];
  }
  if (x != y) {
    for (int i = 20; i >= 0; i--) {
      if (sp[i][x] != sp[i][y]) {
        x = sp[i][x];
        y = sp[i][y];
      }
    }
    x = sp[0][x];
  }
  return x;
}
void get_path(int x, int y) {
  int l = LCA(x, y);
  vector<int> a, b;
  while (x != l) {
    a.push_back(x);
    x = sp[0][x];
  }
  a.push_back(l);
  while (y != l) {
    b.push_back(y);
    y = sp[0][y];
  }
  reverse(b.begin(), b.end());
  cout << a.size() + b.size() << "\n";
  for (auto to : a) cout << to << ' ';
  for (auto to : b) cout << to << ' ';
  cout << "\n";
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u = find(u);
    v = find(v);
    if (u == v) continue;
    if (u != v) p[u] = v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= n; j++) sp[i][j] = sp[i - 1][sp[i - 1][j]];
  }
  int q;
  cin >> q;
  vector<pair<int, int> > query;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cnt[u]++;
    cnt[v]++;
    query.push_back({u, v});
  }
  vector<int> node;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] % 2) node.push_back(i);
  }
  if (node.empty()) {
    cout << "YES"
         << "\n";
    for (auto p : query) get_path(p.first, p.second);
  } else {
    cout << "NO"
         << "\n";
    cout << node.size() / 2;
  }
}
