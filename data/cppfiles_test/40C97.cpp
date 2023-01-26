#include <bits/stdc++.h>
using namespace std;
vector<int> g[300001];
int par[300001];
int dep[300001];
bool vis[300001];
map<pair<int, int>, int> cnt;
void dfs(int v, int p, int d = 0) {
  vis[v] = 1;
  par[v] = p;
  dep[v] = d;
  for (int i : g[v]) {
    if (vis[i]) continue;
    dfs(i, v, d + 1);
  }
}
vector<int> getPath(int a, int b) {
  bool rev = 0;
  if (dep[a] < dep[b]) {
    swap(a, b);
    rev = 1;
  }
  vector<int> patha, pathb;
  patha.push_back(a);
  while (dep[a] > dep[b]) {
    a = par[a];
    patha.push_back(a);
  }
  pathb.push_back(b);
  while (a != b) {
    a = par[a];
    patha.push_back(a);
    b = par[b];
    pathb.push_back(b);
  }
  for (int i = ((int)pathb.size()) - 2; i >= 0; i--) {
    patha.push_back(pathb[i]);
  }
  for (int i = 0; i + 1 < patha.size(); i++) {
    cnt[{patha[i], patha[i + 1]}]++;
    cnt[{patha[i + 1], patha[i]}]++;
  }
  if (rev) {
    reverse(patha.begin(), patha.end());
  }
  return patha;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 1, 0);
  int q;
  cin >> q;
  vector<vector<int>> ans;
  while (q--) {
    int x, y;
    cin >> x >> y;
    vector<int> path = getPath(x, y);
    ans.push_back(path);
  }
  int c = 0;
  for (int i = 1; i <= n; i++) {
    int cc = 0;
    for (int j : g[i]) {
      cc += cnt[{i, j}] % 2;
    }
    c += cc % 2;
  }
  c /= 2;
  if (c > 0) {
    cout << "NO\n";
    cout << c;
  } else {
    cout << "YES\n";
    for (vector<int> i : ans) {
      cout << i.size() << '\n';
      for (int j : i) {
        cout << j << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
