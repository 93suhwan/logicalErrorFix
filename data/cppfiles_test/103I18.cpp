#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
vector<int> g[4000009], g1[4000009];
int v[4000009];
int c[4000009];
int f;
int d;
void dfs(int x, int p) {
  if (v[x]) {
    f = 1;
    return;
  }
  v[x] = d;
  c[d]++;
  for (auto& y : g[x]) {
    if (y != p) {
      dfs(y, x);
      if (f) return;
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n * m; i++)
    g[i].clear(), v[i] = 0, g1[i].clear(), c[i] = 0;
  vector<string> s(n);
  for (auto& i : s) cin >> i;
  vector<int> in(n * m, 0), in1(n * m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'L' && j > 0) {
        in[i * m + j - 1]++;
        g[i * m + j].push_back(i * m + j - 1);
        in1[i * m + j]++;
        g1[i * m + j - 1].push_back(i * m + j);
      }
      if (s[i][j] == 'R' && j != m - 1) {
        in[i * m + j + 1]++;
        g[i * m + j].push_back(i * m + j + 1);
        in1[i * m + j]++;
        g1[i * m + j + 1].push_back(i * m + j);
      }
      if (s[i][j] == 'U' && i > 0) {
        in[(i - 1) * m + j]++;
        g[i * m + j].push_back((i - 1) * m + j);
        in1[i * m + j]++;
        g1[(i - 1) * m + j].push_back(i * m + j);
      }
      if (s[i][j] == 'D' && i != n - 1) {
        in[(i + 1) * m + j]++;
        g[i * m + j].push_back((i + 1) * m + j);
        in1[i * m + j]++;
        g1[(i + 1) * m + j].push_back(i * m + j);
      }
    }
  }
  queue<pair<int, int>> q;
  for (int i = 0; i < n * m; i++) {
    if (in[i] == 0) q.push({i, 1});
  }
  int x = -1, w = 0;
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    x = now.first;
    w = now.second;
    for (auto& y : g[x]) {
      in[y]--;
      if (in[y] == 0) q.push({y, w + 1});
    }
  }
  d = 0;
  for (int i = 0; i < n * m; i++) {
    if (in[i] && !v[i]) {
      f = 0;
      d++;
      dfs(i, -1);
    }
  }
  int ans = 1, sx = 0, sy = 0;
  for (int i = 0; i < n * m; i++) {
    if (v[i]) {
      in1[i] = 0;
      q.push({i, c[v[i]]});
      if (v[i] > ans) {
        ans = v[i];
        sx = i / m;
        sy = i % m;
      }
    } else if (in1[i] == 0)
      q.push({i, 1});
  }
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    x = now.first;
    w = now.second;
    if (w > ans) {
      ans = w;
      sx = x / m;
      sy = x % m;
    }
    for (auto& y : g1[x]) {
      if (in1[y] == 0) continue;
      in1[y]--;
      if (in1[y] == 0) q.push({y, w + 1});
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
