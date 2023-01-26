#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int vis[N];
int fa[N];
int find(int u) { return (u == fa[u] ? u : fa[u] = find(fa[u])); }
void solve() {
  int n, m;
  cin >> n >> m;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) fa[i] = i;
  vector<pair<int, int>> p;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > c) swap(a, c);
    int x = find(a);
    int y = find(c);
    if (x != y) {
      fa[y] = x;
      p.push_back(make_pair(a, c));
    }
  }
  vector<int> ss;
  for (int i = 1; i <= n; i++) {
    if (!vis[fa[i]]) {
      ss.push_back(fa[i]);
      vis[fa[i]] = 1;
    }
  }
  for (int i = 0; i < ss.size() - 1; i++) {
    p.push_back(make_pair(ss[i], ss[i + 1]));
  }
  for (auto i : p) {
    cout << i.first << " " << i.second << "\n";
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
