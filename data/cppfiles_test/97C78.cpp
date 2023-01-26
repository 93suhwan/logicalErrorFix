#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
int _;
int n, m;
char s[510][510];
int a[510][510];
int ans[510][510];
int xx[] = {1, 0, -1, 0};
int yy[] = {0, 1, 0, -1};
vector<pair<int, int> > adj[510][510];
bool check(int x, int y) { return (x >= 1 && x <= n && y >= 1 && y <= m); }
void dfs(int x, int y) {
  for (auto P : adj[x][y]) {
    int p = P.first, q = P.second;
    if (ans[p][q] == 0) {
      ans[p][q] = 5 - ans[x][y];
      dfs(p, q);
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
      a[i][j] = (s[i][j] == 'X');
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!a[i][j]) continue;
      vector<pair<int, int> > vec;
      vec.clear();
      for (int d = 0; d < 4; d++) {
        int xnow = i + xx[d];
        int ynow = j + yy[d];
        if (check(xnow, ynow) && a[xnow][ynow] == 0) {
          vec.push_back({xnow, ynow});
        }
      }
      if (vec.size() & 1) {
        cout << "NO"
             << "\n";
        return;
      }
      for (auto A : vec) {
        int x = A.first, y = A.second;
        for (auto B : vec) {
          int p = B.first, q = B.second;
          if (vec.size() == 4 && (x == p || y == q)) {
            continue;
          }
          if (x != p || y != q) {
            adj[x][y].push_back({p, q});
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        continue;
      }
      if (ans[i][j] == 0) {
        ans[i][j] = 1;
        dfs(i, j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!a[i][j]) continue;
      for (int d = 0; d < 4; d++) {
        int xnow = i + xx[d];
        int ynow = j + yy[d];
        if (check(xnow, ynow) && a[xnow][ynow] == 0) {
          ans[i][j] += ans[xnow][ynow];
        }
      }
    }
  }
  cout << "YES"
       << "\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
