#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, a[1005][1005], b[1005][1005];
long long dx[6] = {0, 1, 0, -1};
long long dy[6] = {-1, 0, 1, 0};
vector<long long> srt;
void dfs(int u, int v) {
  long long cnt = 0;
  deque<pair<long long, long long> > dq;
  dq.push_back({u, v});
  while (dq.size()) {
    pair<long long, long long> k = dq.front();
    dq.pop_front();
    int x = k.first;
    int y = k.second;
    cnt++;
    b[x][y] = 0;
    for (int r = 0; r < 4; r++)
      if (((a[x][y] >> r) & 1) == 0) {
        int xx = x + dx[r];
        int yy = y + dy[r];
        if (b[xx][yy]) dq.push_back({xx, yy});
      }
  }
  srt.push_back(cnt);
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      b[i][j] = 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (b[i][j]) dfs(i, j);
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
