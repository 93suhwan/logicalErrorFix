#include <bits/stdc++.h>
using namespace std;
int n, m, q, d[2][2] = {{-1, 0}, {0, -1}};
bool c[2021][2021];
long long f[2021][2021][2], ans;
long long solve(int x, int y) {
  long long pre[2] = {0, 0}, suf[2] = {0, 0};
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));
  bool t = 0;
  while (!q.empty()) {
    int tx = q.front().first + d[t][0], ty = q.front().second + d[t][1];
    q.pop();
    t ^= 1;
    if (tx > 0 && ty > 0 && !c[tx][ty]) ++pre[0], q.push(make_pair(tx, ty));
  }
  t = 1;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    int tx = q.front().first + d[t][0], ty = q.front().second + d[t][1];
    q.pop();
    t ^= 1;
    if (tx > 0 && ty > 0 && !c[tx][ty]) ++pre[1], q.push(make_pair(tx, ty));
  }
  t = 0;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    int tx = q.front().first - d[t][0], ty = q.front().second - d[t][1];
    q.pop();
    t ^= 1;
    if (tx <= n && ty <= m && !c[tx][ty]) ++suf[0], q.push(make_pair(tx, ty));
  }
  t = 1;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    int tx = q.front().first - d[t][0], ty = q.front().second - d[t][1];
    q.pop();
    t ^= 1;
    if (tx <= n && ty <= m && !c[tx][ty]) ++suf[1], q.push(make_pair(tx, ty));
  }
  return pre[0] * suf[1] + pre[1] * suf[0] + pre[0] + pre[1] + suf[0] + suf[1] +
         1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (i > 1) f[i][j][1] += f[i - 1][j][0];
      if (j > 1) f[i][j][0] += f[i][j - 1][1];
      ans += f[i][j][1] + f[i][j][0] + 1;
      ++f[i][j][1];
      ++f[i][j][0];
    }
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (c[x][y])
      ans += solve(x, y);
    else
      ans -= solve(x, y);
    c[x][y] ^= 1;
    cout << ans << '\n';
  }
  return 0;
}
