#include <bits/stdc++.h>
using namespace std;
const int maxn = 300030;
int par[maxn];
vector<int> graph[maxn];
int cnt[maxn];
vector<bool> vis;
vector<int> prv;
int find(int x) { return par[x] = (par[x] == x ? x : find(par[x])); }
void merge(int x, int y) { par[find(x)] = find(y); }
void dfs(int x) {
  vis[x] = true;
  for (int to : graph[x]) {
    if (!vis[to]) {
      prv[to] = x;
      dfs(to);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (find(x) != find(y)) {
      merge(x, y);
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
  }
  int q;
  cin >> q;
  vector<vector<int>> ans;
  while (q--) {
    vis.assign(n, false);
    prv.assign(n, -1);
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cnt[x] = (cnt[x] + 1) % 2;
    cnt[y] = (cnt[y] + 1) % 2;
    dfs(x);
    vector<int> cur;
    while (y != -1) {
      cur.push_back(y);
      y = prv[y];
    }
    reverse(cur.begin(), cur.end());
    ans.push_back(cur);
  }
  int res = 0;
  for (int i = 0; i < n; i++) res += cnt[i];
  if (res == 0) {
    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].size() << '\n';
      for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] + 1 << ' ';
      }
      cout << '\n';
    }
  } else {
    cout << "NO\n";
    cout << res / 2 << '\n';
  }
}
