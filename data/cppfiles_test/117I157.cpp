#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long mod) {
  long long res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
void solve();
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  vector<string> a(n);
  queue<pair<long long, long long>> q;
  vector<vector<long long>> vis(n, vector<long long>(m, 0));
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    for (long long j = 0; j < m; j++) {
      if (a[i][j] == 'L') {
        q.push({i, j});
        vis[i][j] = 1;
      }
    }
  }
  long long dx[4] = {1, -1, 0, 0};
  long long dy[4] = {0, 0, 1, -1};
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    for (long long i = 0; i < 4; i++) {
      long long x = f.first + dx[i];
      long long y = f.second + dy[i];
      if (x < 0 or y < 0 or x >= n or y >= m) continue;
      if (vis[x][y] == 1) continue;
      if (a[x][y] == '#') continue;
      long long cnt = 0;
      for (long long j = 0; j < 4; j++) {
        long long xx = x + dx[j];
        long long yy = y + dy[j];
        if (xx < 0 or yy < 0 or xx >= n or yy >= m) continue;
        if (a[xx][yy] == '#') continue;
        cnt++;
      }
      if (cnt <= 2) {
        vis[x][y] = 1;
        a[x][y] = '+';
        q.push({x, y});
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << a[i] << '\n';
  }
}
