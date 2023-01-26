#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
const int N = 1005;
int n, m[2], comp[2][N], r[2][N + 1];
vector<int> adj[2][N];
bool visited[2][N];
int root(int x, int tri) {
  if (x == r[tri][x]) return x;
  r[tri][x] = root(r[tri][x], tri);
  return r[tri][x];
}
bool same(int x, int y, int tri) { return root(x, tri) == root(y, tri); }
void unite(int x, int y, int tri) {
  x = root(x, tri);
  y = root(y, tri);
  r[tri][y] = x;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> m[0] >> m[1];
  int x, y;
  for (int tri = 0; tri < 2; tri++)
    for (int i = 1; i <= n; i++) r[tri][i] = i;
  for (int tri = 0; tri < 2; tri++) {
    for (int i = 0; i < m[tri]; i++) {
      cin >> x >> y;
      unite(x, y, tri);
    }
  }
  vector<pair<int, int>> sol;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!same(i, j, 0) && !same(i, j, 1)) {
        unite(i, j, 0);
        unite(i, j, 1);
        sol.push_back({i, j});
      }
  cout << sol.size() << '\n';
  for (auto p : sol) cout << p.first << ' ' << p.second << '\n';
  return 0;
}
