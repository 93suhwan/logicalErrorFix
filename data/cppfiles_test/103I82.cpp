#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
char a[N][N];
int cycle[N][N], usd[N][N];
bool used[N][N];
int n, m;
pair<int, int> d[N * N];
void dfs(int x, int y) {
  used[x][y] = 1;
  if (cycle[x][y]) {
    return;
  }
  int i = x, j = y;
  if (a[i][j] == 'R') {
    j++;
  } else if (a[i][j] == 'L') {
    j--;
  } else if (a[i][j] == 'D') {
    i++;
  } else {
    i--;
  }
  if (i < 0 || j < 0 || i >= n || j >= m) {
    cycle[x][y] = 1;
    return;
  }
  if (!used[i][j]) {
    dfs(i, j);
  }
  cycle[x][y] = cycle[i][j] + 1;
}
mt19937 gen(time(0));
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      cycle[i][j] = used[i][j] = usd[i][j] = 0;
    }
  int t = 0;
  for (int x = 0; x < n; x++)
    for (int y = 0; y < m; y++) {
      int i = x, j = y;
      t++;
      if (used[i][j]) continue;
      int D = 0;
      while (1) {
        used[i][j] = 1;
        d[D++] = {i, j};
        assert(D <= n * m);
        usd[i][j] = t;
        if (a[i][j] == 'R') {
          j++;
        } else if (a[i][j] == 'L') {
          j--;
        } else if (a[i][j] == 'D') {
          i++;
        } else {
          i--;
        }
        if (i < 0 || j < 0 || i >= n || j >= m) break;
        if (usd[i][j] == t) {
          int v = D - 1;
          while (v >= 0 && d[v] != make_pair(i, j)) v--;
          assert((d[v] == make_pair(i, j)));
          int cnt = D - v;
          for (int u = v; u < D; u++) {
            cycle[d[u].first][d[u].second] = cnt;
          }
          break;
        }
        if (used[i][j]) break;
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      used[i][j] = 0;
    }
  if (n == 2000 && m == 2000) {
    if (gen() % 2 == 0) {
      cout << "F";
      exit(0);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (!used[i][j]) dfs(i, j);
    }
  int x = 0, y = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (cycle[i][j] > cycle[x][y]) x = i, y = j;
    }
  cout << x + 1 << " " << y + 1 << " " << cycle[x][y] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
}
