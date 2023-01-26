#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const long long INF = 1e15;
int n, m, k;
vector<pair<int, int> > added;
long long dist[N];
int parent[3][N], sz[3][N];
void initDSU() {
  iota(parent[1], parent[1] + N, 0);
  iota(parent[2], parent[2] + N, 0);
  fill(sz[1], sz[1] + N, 1);
  fill(sz[2], sz[2] + N, 1);
}
int findSet(int src, int id) {
  if (src == parent[id][src]) return src;
  return parent[id][src] = findSet(parent[id][src], id);
}
void makeSet(int x, int y, int id) {
  x = findSet(x, id);
  y = findSet(y, id);
  if (sz[id][x] > sz[id][y]) swap(x, y);
  parent[id][x] = y;
  sz[id][y] += sz[id][x];
}
bool canMakeSet(int x, int y, int id) {
  x = findSet(x, id);
  y = findSet(y, id);
  if (x == y) return false;
  return true;
}
bool check(int x, int y) {
  if (y >= x - 1) return false;
  return true;
}
void solve() {
  initDSU();
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    makeSet(v, u, 1);
  }
  for (int i = 1; i <= k; ++i) {
    int u, v;
    cin >> u >> v;
    makeSet(v, u, 2);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n && check(n, m) && check(n, k); ++j) {
      if (canMakeSet(i, j, 1) && canMakeSet(i, j, 2)) {
        added.emplace_back(i, j), ++m, ++k;
        makeSet(i, j, 1);
        makeSet(i, j, 2);
      }
    }
  }
  cout << added.size() << '\n';
  for (pair<int, int> x : added) cout << x.first << ' ' << x.second << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
