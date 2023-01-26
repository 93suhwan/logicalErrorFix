#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 2005;
pair<int, int> moves[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  int lab = -1;
  vector<int> deg(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.') {
        for (auto [dx, dy] : moves) {
          int x = i + dx;
          int y = j + dy;
          if (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '#')
            deg[i * m + j]++;
        }
      } else if (s[i][j] == 'L')
        lab = i * m + j;
    }
  }
  deg[lab] = -1;
  queue<int> q;
  q.push(lab);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int x = u / m, y = u % m;
    if (u != lab) s[x][y] = '+';
    for (auto [dx, dy] : moves) {
      int nx = x + dx;
      int ny = y + dy;
      if (0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] != '#' &&
          deg[nx * m + ny] != -1) {
        deg[nx * m + ny]--;
        if (deg[nx * m + ny] <= 1) {
          deg[nx * m + ny] = -1;
          q.push(nx * m + ny);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) cout << s[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
