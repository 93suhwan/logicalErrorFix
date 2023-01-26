#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 2 * N, mod = 1e9 + 7;
int n, m;
int p[N * N], b[N * N];
int g[N][N], st[N][N];
vector<pair<int, int> > ts[N * N];
int num[N * N];
struct node {
  pair<int, int> L, R;
} d[N * N];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      st[i][j] = 0;
      cin >> g[i][j];
      p[((i - 1) * m + j)] = g[i][j];
    }
  }
  sort(p + 1, p + n * m + 1);
  for (int i = 1; i <= n * m; i++) b[i] = p[i];
  int cnt = unique(b + 1, b + n * m + 1) - b - 1;
  for (int i = 1; i <= n * m; i++)
    p[i] = lower_bound(b + 1, b + cnt + 1, p[i]) - b, d[i] = {{0, 0}, {0, 0}};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      g[i][j] = lower_bound(b + 1, b + cnt + 1, g[i][j]) - b;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int val = p[((i - 1) * m + j)];
      if (d[val].L.first == 0) d[val].L = {i, j};
      d[val].R = {i, j};
    }
  for (int i = 1; i <= cnt; i++) {
    ts[i].clear();
    num[i] = 0;
    if (d[i].L.first == d[i].R.first) {
      for (int j = d[i].R.second; j >= d[i].L.second; j--) {
        ts[i].push_back({d[i].L.first, j});
      }
    } else {
      for (int k = d[i].L.first; k <= d[i].R.first; k++) {
        if (k == d[i].L.first) {
          for (int j = m; j >= d[i].L.second; j--) ts[i].push_back({k, j});
        } else if (k == d[i].R.first) {
          for (int j = d[i].R.second; j >= 1; j--) ts[i].push_back({k, j});
        } else {
          for (int j = m; j >= 1; j--) ts[i].push_back({k, j});
        }
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int val = g[i][j];
      auto& [first, second] = ts[val][num[val]++];
      for (int k = 1; k <= second; k++) res += st[first][k];
      st[first][second] = 1;
    }
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cout.precision(2), cout.setf(ios::fixed);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
