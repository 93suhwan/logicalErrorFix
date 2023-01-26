#include <bits/stdc++.h>
using namespace std;
template <class M>
M myabs(M x) {
  return x < 0 ? -x : x;
}
template <class M1, class M2>
bool minimize(M1 &x, const M2 &y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <class M1, class M2>
bool maximize(M1 &x, const M2 &y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
const int INF = (int)1e9 + 7;
const long long INFLL = (long long)1e18 + 7LL;
const double PI = 4 * atan(1.00);
int row, col, c, cycle;
int f[2020 * 2020], cnt[2020][2020];
int vis[2020 * 2020], ____next[2020 * 2020];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
bool canGo(int x, int y) { return 1 <= x && x <= row && 1 <= y && y <= col; }
vector<int> nodes;
void dfsOne(int u) {
  vis[u] = c;
  int v = ____next[u];
  if (v == 0) return;
  if (vis[v] == c) {
    cycle = v;
    nodes.push_back(u);
    return;
  }
  if (vis[v] > 0) return;
  dfsOne(v);
  if (cycle > 0) nodes.push_back(u);
  if (cycle == u) cycle = 0;
}
void dfsTwo(int u) {
  int v = ____next[u];
  if (v == 0 || f[u] > 0) {
    f[u] = 1;
    return;
  }
  dfsTwo(v);
  f[u] = f[v] + 1;
}
void solve() {
  cin >> row >> col;
  c = 0;
  for (int i = (1), _b = (row); i <= _b; i++)
    for (int j = (1), _b = (col); j <= _b; j++) cnt[i][j] = ++c;
  for (int i = (1), _b = (row); i <= _b; i++)
    for (int j = (1), _b = (col); j <= _b; j++) {
      char c;
      cin >> c;
      int dir;
      if (c == 'L') dir = 2;
      if (c == 'R') dir = 3;
      if (c == 'U') dir = 0;
      if (c == 'D') dir = 1;
      int x = i + dx[dir];
      int y = j + dy[dir];
      if (canGo(x, y))
        ____next[cnt[i][j]] = cnt[x][y];
      else
        ____next[cnt[i][j]] = 0;
    }
  for (int i = (0), _b = (row + 1); i <= _b; i++)
    for (int j = (0), _b = (col + 1); j <= _b; j++)
      vis[cnt[i][j]] = f[cnt[i][j]] = 0;
  c = 0;
  for (int i = (1), _b = (row); i <= _b; i++)
    for (int j = (1), _b = (col); j <= _b; j++)
      if (vis[cnt[i][j]] == 0) {
        c++;
        cycle = 0;
        nodes.clear();
        dfsOne(cnt[i][j]);
        for (auto u : nodes) f[u] = (int)nodes.size();
      }
  for (int i = (1), _b = (row); i <= _b; i++)
    for (int j = (1), _b = (col); j <= _b; j++)
      if (f[cnt[i][j]] == 0) dfsTwo(cnt[i][j]);
  int x, y, mx = -1;
  for (int i = (1), _b = (row); i <= _b; i++)
    for (int j = (1), _b = (col); j <= _b; j++)
      if (maximize(mx, f[cnt[i][j]])) x = i, y = j;
  cout << x << " " << y << " " << f[cnt[x][y]] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
