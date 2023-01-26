#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> a, h, p;
vector<pair<int, int>> query;
struct dsu {
 private:
  int _n;
  vector<int> arr;
  vector<int> rank;

 public:
  dsu() : _n(0) {}
  dsu(int n) : _n(n) {
    arr.clear();
    for (int i = 0; i < _n; ++i) arr.push_back(i);
    rank.clear();
    rank.resize(_n, 0);
  }
  int parent(int x) {
    if (x == arr[x]) return x;
    return (arr[x] = parent(arr[x]));
  }
  bool same(int x, int y) { return parent(x) == parent(y); }
  void join(int x, int y) {
    x = parent(x);
    y = parent(y);
    if (rank[x] < rank[y]) {
      arr[x] = y;
      rank[y] += 1;
    } else if (rank[x] > rank[y]) {
      arr[y] = x;
      rank[x] += 1;
    } else {
      arr[x] = y;
      rank[y] += 1;
    }
  }
  vector<vector<int>> groups() {
    int x = 0;
    vector<int> temp(_n, -1);
    for (int i = 0; i < _n; i++) {
      int a = parent(i);
      if (temp[a] == -1) temp[a] = x++;
    }
    vector<vector<int>> res(x, vector<int>{});
    for (int i = 0; i < _n; i++) {
      res[temp[parent(i)]].push_back(i);
    }
    return res;
  }
};
void dfs(int r, int par = -1) {
  if (par == -1) {
    h[r] = 0;
    p[r] = -1;
  } else {
    h[r] = h[par] + 1;
    p[r] = par;
  }
  for (auto v : g[r]) {
    if (v == par) continue;
    dfs(v, r);
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  a.resize(n);
  g.resize(n);
  dsu d(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (d.same(x, y)) continue;
    d.join(x, y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int q;
  cin >> q;
  query = vector<pair<int, int>>(q);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    a[x]++, a[y]++;
    query[i] = {x, y};
  }
  bool yes = true;
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2) {
      yes = false;
      cnt += (a[i] % 2);
    }
  }
  if (!yes) {
    cout << "NO" << '\n';
    cout << cnt / 2 << '\n';
    return;
  }
  cout << "YES" << '\n';
  h = vector<int>(n);
  p = vector<int>(n);
  dfs(0);
  for (auto qq : query) {
    int x = qq.first;
    int org = x;
    int y = qq.second;
    if (h[x] > h[y]) {
      swap(x, y);
    }
    vector<int> path;
    vector<int> rt;
    while (h[y] > h[x]) {
      path.push_back(y);
      y = p[y];
    }
    if (x != y) {
      while (true) {
        path.push_back(y);
        rt.push_back(x);
        y = p[y];
        x = p[x];
        if (x == y) {
          path.push_back(x);
          break;
        }
      }
      while (int(rt.size()) > 0) {
        path.push_back(rt.back());
        rt.pop_back();
      }
    } else
      path.push_back(x);
    if (path[0] != org) reverse(path.begin(), path.end());
    cout << int(path.size()) << '\n';
    for (auto p : path) {
      cout << p + 1 << " ";
    }
    cout << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
