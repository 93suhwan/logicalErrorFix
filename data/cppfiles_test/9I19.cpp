#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const long long mod = 998244353;
int mp[maxn][maxn];
int vis[maxn][maxn];
int n, m;
int work(int x, int y) {
  if (vis[x][y] == 1) return y;
  if (mp[x][y] == 2 && x == n) return y;
  if (mp[x][y] == 1) {
    mp[x][y] == 2;
    if (vis[x + 1][y] == 1) vis[x][y] = 1;
    return work(x, y + 1);
  }
  if (mp[x][y] == 3) {
    mp[x][y] == 2;
    if (vis[x + 1][y] == 1) vis[x][y] = 1;
    return work(x, y - 1);
  }
  if (mp[x][y] == 2) {
    return work(x + 1, y);
  }
}
int main() {
  int k, y;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = n; i > 0; i--) {
      if (mp[i][j] != 2) break;
      vis[i][j] = 1;
    }
    vis[n + 1][j] = 1;
  }
  while (k--) {
    cin >> y;
    cout << work(1, y) << " ";
  }
  return 0;
}
