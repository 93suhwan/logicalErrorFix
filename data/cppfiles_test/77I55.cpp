#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, a[1005][1005], f[1005][1005][5];
long long dx[6] = {0, -1, 0, 1, 0};
long long dy[6] = {0, 0, 1, 0, -1};
vector<long long> srt;
long long dfs(int u, int v) {
  long long cnt = 0;
  deque<pair<long long, long long> > dq;
  dq.push_back({u, v});
  while (dq.size()) {
    pair<long long, long long> k = dq.front();
    dq.pop_front();
    int x = k.first;
    int y = k.second;
    a[x][y] = 0;
    cnt++;
    for (int r = 1; r < 5; r++)
      if (!f[x][y][r]) {
        int xx = x + dx[r];
        int yy = y + dy[r];
        if (a[xx][yy]) dq.push_back({xx, yy});
      }
  }
  return cnt;
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      long long x = a[i][j];
      while (x) {
        long long q = x & -x;
        if (q == 1) f[i][j][4] = '1';
        if (q == 2) f[i][j][3] = '1';
        if (q == 4) f[i][j][2] = '1';
        if (q == 8) f[i][j][1] = '1';
        x -= q;
      }
      a[i][j] = 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j]) srt.push_back(dfs(i, j));
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
