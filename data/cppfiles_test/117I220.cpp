#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1},
          dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
const int mod = (int)2020;
const ll linf = 1e18;
const int inf = (int)1e9 + 25;
int n, m;
vector<vector<char>> a;
vector<vector<bool>> vis;
bool inside(int u, int v) { return min(u, v) >= 1 && u <= n && v <= m; }
bool canForce(int u, int v, int x, int y) {
  char dirToForce;
  if (u != x)
    dirToForce = (u < x ? 'd' : 'u');
  else
    dirToForce = (v < y ? 'r' : 'l');
  int numValidDir = 0;
  for (int i = (0); i < (4); ++i) {
    int nx = u + dx[i], ny = v + dy[i];
    if (!inside(nx, ny) || a[nx][ny] == '#') continue;
    ++numValidDir;
  }
  return numValidDir <= 2;
}
void solve() {
  a.clear();
  vis.clear();
  cin >> n >> m;
  a.resize(n + 1);
  for (int i = (1); i <= (n); ++i) a[i].resize(m + 1);
  vis.resize(n + 1);
  for (int i = (1); i <= (n); ++i) vis[i].assign(m + 1, false);
  int lx, ly;
  queue<ii> q;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      cin >> a[i][j];
      if (a[i][j] == 'L') {
        lx = i;
        ly = j;
        q.push(ii(lx, ly));
        vis[lx][ly] = true;
      }
    }
  while (q.size()) {
    int cx = q.front().first, cy = q.front().second;
    q.pop();
    for (int i = (0); i < (4); ++i) {
      int u = cx + dx[i], v = cy + dy[i];
      if (!inside(u, v) || a[u][v] == '#' || a[u][v] == '+' || vis[u][v])
        continue;
      vis[u][v] = true;
      if (canForce(u, v, cx, cy)) {
        a[u][v] = '+';
        q.push(ii(u, v));
      }
    }
  }
  for (int i = (1); i <= (n); ++i) {
    for (int j = (1); j <= (m); ++j) cout << a[i][j];
    cout << endl;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
