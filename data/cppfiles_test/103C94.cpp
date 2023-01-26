#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int f;
int d;
void solve() {
  cin >> n >> m;
  vector<int> g1[n * m], g(n * m);
  vector<int> c(n * m, 0), v(n * m, 0);
  for (int i = 0; i < n * m; i++) g[i] = -1, v[i] = 0, c[i] = 0;
  vector<char> in(n * m, 0), in1(n * m, 0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'L' && j > 0) {
        in[i * m + j - 1]++;
        g[i * m + j] = (i * m + j - 1);
        in1[i * m + j]++;
        g1[i * m + j - 1].push_back(i * m + j);
      }
      if (s[j] == 'R' && j != m - 1) {
        in[i * m + j + 1]++;
        g[i * m + j] = (i * m + j + 1);
        in1[i * m + j]++;
        g1[i * m + j + 1].push_back(i * m + j);
      }
      if (s[j] == 'U' && i > 0) {
        in[(i - 1) * m + j]++;
        g[i * m + j] = ((i - 1) * m + j);
        in1[i * m + j]++;
        g1[(i - 1) * m + j].push_back(i * m + j);
      }
      if (s[j] == 'D' && i != n - 1) {
        in[(i + 1) * m + j]++;
        g[i * m + j] = ((i + 1) * m + j);
        in1[i * m + j]++;
        g1[(i + 1) * m + j].push_back(i * m + j);
      }
    }
  }
  vector<int> dis(n * m, 0);
  queue<int> q;
  for (int i = 0; i < n * m; i++) {
    if (in[i] == 0) q.push(i), dis[i] = 1;
  }
  int x = -1, w = 0;
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    x = now;
    int y = g[x];
    if (y != -1) {
      in[y]--;
      if (in[y] == 0) q.push(y), dis[y] = dis[x] + 1;
    }
  }
  d = 0;
  for (int i = 0; i < n * m; i++) {
    if (in[i] && !v[i]) {
      f = 0;
      d++;
      int x = i;
      v[x] = d;
      c[d]++;
      x = g[x];
      while (x != i) {
        v[x] = d;
        c[d]++;
        x = g[x];
      }
    }
  }
  int ans = 1, sx = 0, sy = 0;
  dis = vector<int>(n * m, 0);
  for (int i = 0; i < n * m; i++) {
    if (v[i]) {
      in1[i] = 0;
      q.push(i), dis[i] = c[v[i]];
      if (c[v[i]] > ans) {
        ans = c[v[i]];
        sx = i / m;
        sy = i % m;
      }
    } else if (in1[i] == 0)
      q.push(i), dis[i] = 1;
  }
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    x = now;
    w = dis[now];
    if (w > ans) {
      ans = w;
      sx = x / m;
      sy = x % m;
    }
    for (auto& y : g1[x]) {
      if (in1[y] == 0) continue;
      in1[y]--;
      if (in1[y] == 0) q.push(y), dis[y] = dis[x] + 1;
    }
  }
  cout << sx + 1 << " " << sy + 1 << " " << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
}
