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
vector<char> a[1000004];
vector<bool> vis[1000004];
bool inside(int u, int v) { return min(u, v) >= 0 && u < n && v < m; }
bool canForce(int u, int v) {
  int numValidDir = 0;
  for (int i = (0); i < (4); ++i) {
    int nx = u + dx[i], ny = v + dy[i];
    if (!inside(nx, ny) || a[nx][ny] == '#') continue;
    if (a[nx][ny] == '.') {
      if (++numValidDir > 1) return false;
    }
  }
  return true;
}
void solve() {
  cin >> n >> m;
  for (int i = (0); i < (n); ++i) a[i].resize(m + 1);
  for (int i = (0); i < (n); ++i) {
    vis[i].assign(m + 1, false);
    for (int j = (0); j < (m); ++j) cin >> a[i][j];
  }
  int lx, ly;
  queue<ii> q;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
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
      if (canForce(u, v)) {
        a[u][v] = '+';
        q.push(ii(u, v));
        vis[u][v] = true;
      }
    }
  }
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (m); ++j) cout << a[i][j];
    cout << '\n';
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
