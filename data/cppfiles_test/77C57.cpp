#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n, m;
const int N = 1e3 + 5;
int ar[N][N], vis[N][N];
template <class T>
inline T isOn(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
void dfs(int x, int y, int& cnt) {
  vis[x][y] = 1;
  ++cnt;
  for (int i = 0; i < 4; i++) {
    if (!isOn(ar[x][y], i)) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (!vis[xx][yy]) dfs(xx, yy, cnt);
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> ar[i][j];
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cnt = 0;
      if (!vis[i][j]) {
        dfs(i, j, cnt);
        ans.push_back(cnt);
      }
    }
  }
  sort(ans.rbegin(), ans.rend());
  for (auto it : ans) {
    cout << it << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
