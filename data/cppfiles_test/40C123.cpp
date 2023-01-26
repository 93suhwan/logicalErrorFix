#include <bits/stdc++.h>
using namespace std;
vector<int> g[300500];
int id[300500];
int find_comp(int a) {
  if (id[a] == a) return a;
  return id[a] = find_comp(id[a]);
}
bool unite(int a, int b) {
  a = find_comp(a);
  b = find_comp(b);
  if (a == b) return false;
  id[a] = b;
  return true;
}
int p[300500];
int d[300500];
int odd[300500];
int res;
int go(int v, int par = 0) {
  int cnt = 0;
  for (int to : g[v])
    if (to != par) {
      cnt += go(to, v);
    }
  if (cnt % 2 == 0) {
    res += cnt / 2;
    return odd[v];
  }
  if (odd[v]) {
    res += cnt / 2;
    return 1;
  } else {
    res += (cnt + 1) / 2;
    return 0;
  }
}
void dfs(int v, int par, int dep = 0) {
  p[v] = par;
  d[v] = dep++;
  for (int to : g[v])
    if (to != par) {
      dfs(to, v, dep);
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = (1); i <= (n); ++i) id[i] = i;
  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (unite(a, b)) {
      g[a].push_back(b);
      g[b].push_back(a);
    }
  }
  int nq;
  cin >> nq;
  vector<pair<int, int> > q(nq);
  for (int i = (0); i < (nq); ++i) {
    cin >> q[i].first >> q[i].second;
  }
  dfs(1, 0);
  for (auto pp : q) {
    int a = pp.first, b = pp.second;
    if (d[a] < d[b]) swap(a, b);
    while (d[a] > d[b]) {
      odd[a] ^= 1;
      a = p[a];
    }
    while (a != b) {
      odd[a] ^= 1;
      odd[b] ^= 1;
      a = p[a];
      b = p[b];
    }
  }
  bool ok = true;
  for (int i = (1); i <= (n); ++i)
    if (odd[i]) ok = false;
  if (ok) {
    cout << "YES\n";
    vector<int> path;
    vector<int> tmp;
    for (auto pp : q) {
      path.clear();
      int a = pp.first, b = pp.second;
      bool sw = false;
      if (d[a] < d[b]) swap(a, b), sw = true;
      while (d[a] > d[b]) {
        path.push_back(a);
        a = p[a];
      }
      while (a != b) {
        path.push_back(a);
        tmp.push_back(b);
        a = p[a];
        b = p[b];
      }
      path.push_back(a);
      while (tmp.size()) {
        path.push_back(tmp.back());
        tmp.pop_back();
      }
      if (sw) reverse(path.begin(), path.end());
      cout << path.size() << "\n";
      cout << path[0];
      for (int i = (1); i < (path.size()); ++i) cout << " " << path[i];
      cout << "\n";
    }
  } else {
    res = 0;
    go(1);
    cout << "NO\n" << res << endl;
  }
}
