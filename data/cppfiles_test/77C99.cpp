#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, a[1005][1005], b[1005][1005];
long long dx[] = {0, 1, 0, -1};
long long dy[] = {-1, 0, 1, 0};
vector<long long> srt;
void dfs(int i, int j) {
  queue<pair<long long, long long> > qu;
  qu.push({i, j});
  b[i][j] = 1;
  int o = 1;
  while (qu.size()) {
    auto [x, y] = qu.front();
    qu.pop();
    for (int k = 3; k >= 0; k--) {
      if ((a[x][y] >> k & 1) == 0) {
        int u = x + dx[k];
        int v = y + dy[k];
        if (!b[u][v] and u and v and u <= n and v <= m) {
          qu.push({u, v});
          o++;
          b[u][v] = 1;
        }
      }
    }
  }
  srt.push_back(o);
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!b[i][j]) dfs(i, j);
  sort(srt.begin(), srt.end(), greater<long long>());
  for (long long x : srt) cout << x << ' ';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) solve();
}
