#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, vis[maxn], val[maxn];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool inside(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    vector<string> a(n);
    int lx = -1, ly = -1;
    for (int i = 0; i < (int)(n); ++i) {
      cin >> a[i];
      for (int j = 0; j < (int)(m); ++j) {
        if (a[i][j] == 'L') lx = i, ly = j;
        vis[i * m + j] = val[i * n + j] = 0;
      }
    }
    queue<int> q;
    q.push(lx * m + ly);
    vis[lx * m + ly] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      int i = u / m, j = u % m, w = 0, can = 0;
      vis[u] = 1;
      for (int d = 0; d < (int)(4); ++d) {
        int x = i + dx[d], y = j + dy[d];
        if (!inside(x, y) || a[x][y] == '#') continue;
        int v = x * m + y;
        w++;
        can += val[v];
      }
      val[u] = (can && w - can <= 1) || (i == lx && j == ly);
      if (!val[u]) continue;
      for (int d = 0; d < (int)(4); ++d) {
        int x = i + dx[d], y = j + dy[d];
        if (!inside(x, y) || a[x][y] == '#') continue;
        int v = x * m + y;
        if (!val[v]) q.push(v);
      }
    }
    for (int i = 0; i < (int)(n); ++i) {
      for (int j = 0; j < (int)(m); ++j) {
        if (a[i][j] == 'L' || !val[i * m + j])
          cout << a[i][j];
        else
          cout << '+';
      }
      cout << '\n';
    }
  }
  return 0;
}
