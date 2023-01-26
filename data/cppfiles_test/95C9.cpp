#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 5e5 + 5;
int t, n, m;
char col[N];
vector<int> a[N], k[5][N];
pair<vector<int>, int> p[N];
bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
  for (int i = 1; i <= m; ++i) return a.first[i] > b.first[i];
}
void traitren(int c) {
  for (int i = 2; i <= n; ++i) k[c][i][1] = min(k[c][i - 1][1], k[c][i][1]);
  for (int i = 2; i <= m; ++i) k[c][1][i] = min(k[c][1][i - 1], k[c][1][i]);
  for (int i = 2; i <= n; ++i)
    for (int j = 2; j <= m; ++j)
      k[c][i][j] = min({k[c][i - 1][j], k[c][i][j - 1], k[c][i][j]});
}
void phaitren(int c) {
  for (int i = 2; i <= n; ++i) k[c][i][m] = max(k[c][i - 1][m], k[c][i][m]);
  for (int i = m - 1; i >= 1; --i) k[c][1][i] = max(k[c][1][i + 1], k[c][1][i]);
  for (int i = 2; i <= n; ++i)
    for (int j = m - 1; j >= 1; --j)
      k[c][i][j] = max({k[c][i - 1][j], k[c][i][j + 1], k[c][i][j]});
}
void traiduoi(int c) {
  for (int i = n - 1; i >= 1; --i) k[c][i][1] = max(k[c][i + 1][1], k[c][i][1]);
  for (int i = 2; i <= m; ++i) k[c][n][i] = max(k[c][n][i - 1], k[c][n][i]);
  for (int i = n - 1; i >= 1; --i)
    for (int j = 2; j <= m; ++j)
      k[c][i][j] = max({k[c][i + 1][j], k[c][i][j - 1], k[c][i][j]});
}
void phaiduoi(int c) {
  for (int i = n - 1; i >= 1; --i) k[c][i][m] = min(k[c][i + 1][m], k[c][i][m]);
  for (int i = m - 1; i >= 1; --i) k[c][n][i] = min(k[c][n][i + 1], k[c][n][i]);
  for (int i = n - 1; i >= 1; --i)
    for (int j = m - 1; j >= 1; --j)
      k[c][i][j] = min({k[c][i + 1][j], k[c][i][j + 1], k[c][i][j]});
}
bool check(int i, int j) {
  return (k[1][i][j] > k[3][i + 1][j] && k[2][i][j + 1] < k[4][i + 1][j + 1]);
}
void solve() {
  for (int j = 1; j <= m - 1; ++j) {
    for (int i = 1; i <= n - 1; ++i)
      if (check(i, j)) {
        cout << "YES" << '\n';
        for (int c = 1; c <= i; ++c) col[p[c].second] = 'R';
        for (int c = i + 1; c <= n; ++c) col[p[c].second] = 'B';
        for (int c = 1; c <= n; ++c) cout << col[c];
        cout << ' ' << j << '\n';
        return;
      }
  }
  cout << "NO" << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      a[i].clear();
      a[i].push_back(0);
      for (int c = 1; c <= 4; ++c) {
        k[c][i].clear();
        k[c][i].push_back(0);
      }
      for (int j = 1; j <= m; ++j) {
        int x;
        cin >> x;
        a[i].push_back(x);
      }
      p[i] = {a[i], i};
    }
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        for (int c = 1; c <= 4; ++c) k[c][i].push_back(a[p[i].second][j]);
    traitren(1);
    phaitren(2);
    traiduoi(3);
    phaiduoi(4);
    solve();
  }
}
