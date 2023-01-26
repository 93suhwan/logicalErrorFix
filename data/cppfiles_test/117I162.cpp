#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}
vector<pair<long long, long long>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void solve() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    pair<long long, long long> p;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'L') {
          p = {i, j};
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    queue<pair<long long, long long>> q;
    vector<vector<long long>> vis(n, vector<long long>(m, 0));
    q.push(p);
    while (!q.empty()) {
      auto [v1, v2] = q.front();
      q.pop();
      vis[v1][v2] = 1;
      for (auto [x, y] : dir) {
        int xx = v1 + x, yy = v2 + y;
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] &&
            a[xx][yy] == '.') {
          vis[xx][yy] = 1;
          int cnt = 0;
          for (auto [x1, y1] : dir) {
            long long X = xx + x1, Y = yy + y1;
            if (X >= 0 && X < n && Y >= 0 && Y < m &&
                (a[X][Y] == '.' || a[X][Y] == 'L' || a[X][Y] == '+'))
              cnt++;
          }
          if (cnt <= 2) {
            a[xx][yy] = '+';
            q.push({xx, yy});
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
