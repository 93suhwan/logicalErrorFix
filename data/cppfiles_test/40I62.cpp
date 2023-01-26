#include <bits/stdc++.h>
using namespace std;
const int mxn = 300000;
int n, m, q;
int a[mxn], d[mxn], p[mxn], pp[mxn], rk[mxn];
vector<int> g[mxn], v[mxn];
int fnd(int x) { return x == pp[x] ? x : pp[x] = fnd(pp[x]); }
void dfs(int c) {
  for (int i : g[c])
    if (i != p[c]) d[i] = d[c] + 1, p[i] = c, dfs(i);
}
pair<int, int> dfs2(int c) {
  pair<int, int> z = {0, a[c]};
  for (int i : g[c])
    if (i != p[c]) {
      pair<int, int> x = dfs2(i);
      z.first += x.first + (x.second && z.second), z.second ^= x.second;
    }
  return z;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) pp[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (fnd(--x) != fnd(--y)) {
      g[x].push_back(y);
      g[y].push_back(x);
      x = fnd(x), y = fnd(y);
      if (rk[x] < rk[y]) swap(x, y);
      rk[x] += rk[x] == rk[y], pp[y] = x;
    }
  }
  p[0] = -1;
  dfs(0);
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    vector<int> w;
    while (x != y) {
      if (d[x] > d[y])
        v[i].push_back(x), a[x] ^= 1, x = p[x];
      else
        w.push_back(y), a[y] ^= 1, y = p[y];
    }
    v[i].push_back(x);
    reverse(w.begin(), w.end());
    v[i].insert(v[i].end(), w.begin(), w.end());
  }
  if (!count(a, a + n, 1)) {
    cout << "YES" << '\n';
    for (int i = 0; i < q; i++) {
      cout << v[i].size() << '\n';
      cout << (v[i][0] + 1);
      for (int j = 1; j < v[i].size(); j++) cout << " " << (v[i][j] + 1);
      cout << '\n';
    }
  } else {
    cout << "NO" << '\n';
    pair<int, int> x = dfs2(0);
    int ret = x.first + x.second;
    cout << ret << '\n';
  }
  return 0;
}
