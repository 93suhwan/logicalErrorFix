#include <bits/stdc++.h>
using namespace std;
void optIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
string s[520];
int n, m;
int dirx[] = {0, 0, -1, -1, -1, 1, 1, 1};
int diry[] = {-1, 1, -1, 0, 1, -1, 0, 1};
int id = 0;
int vis[520][520], ans[520][520];
void dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (s[x][y] == 'X') return;
  if (vis[x][y]) return;
  vis[x][y] = id;
  for (int i = 0; i < 8; ++i) dfs(x + dirx[i], y + diry[i]);
}
bool used[250020];
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  bool ok = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'X') {
        int cnt = 0;
        if (s[i][j + 1] == 'X') cnt++;
        if (s[i][j - 1] == 'X') cnt++;
        if (s[i + 1][j] == 'X') cnt++;
        if (s[i - 1][j] == 'X') cnt++;
        if (cnt % 2 != 0) ok = 0;
        ans[i][j] = 5 * (2 - (cnt / 2));
        continue;
      }
      if (vis[i][j]) continue;
      id++;
      dfs(i, j);
    }
  if (!ok) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  map<int, int> mmap;
  mmap[1] = 1;
  for (int i = 0; i < n; ++i) {
    int lid = vis[i][0];
    mmap[lid] = 5 - mmap[lid];
    int s = mmap[lid];
    queue<int> q;
    q.push(lid);
    used[lid] = 1;
    for (int j = 0; j < m; ++j) {
      if (!vis[i][j]) continue;
      if (lid != vis[i][j]) {
        lid = vis[i][j];
        s = 5 - s;
        if (mmap.find(lid) == mmap.end())
          mmap[lid] = s;
        else if (used[lid])
          s = mmap[lid];
        else {
          mmap[lid] = 5 - mmap[lid];
          s = mmap[lid];
        }
        q.push(lid);
        used[lid] = 1;
      }
      ans[i][j] = s;
    }
    while (q.size()) {
      used[q.front()] = 0;
      q.pop();
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << ans[i][j] << " ";
    cout << "\n";
  }
}
int main() {
  optIO();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
