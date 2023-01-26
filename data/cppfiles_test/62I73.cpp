#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, m, q;
long long ans;
long long a[maxn][maxn][2], vis[maxn][maxn];
void solve() {
  cin >> n >> m >> q;
  for (int i = n; i; i--)
    for (int j = m; j; j--) {
      a[i][j][0] = a[i][j][1] = 1;
      a[i][j][0] += a[i][j + 1][1];
      a[i][j][1] += a[i + 1][j][0];
      ans += a[i][j][0] + a[i][j][1] - 1;
      vis[i][j] = 1;
    }
  while (q--) {
    int x, y;
    cin >> x >> y;
    vis[x][y] ^= 1;
    if (vis[x][y]) {
      int i, j;
      long long cnt;
      i = x, j = y, cnt = 1;
      while (1) {
        j++;
        if (!vis[i][j]) break;
        cnt++;
        i++;
        if (!vis[i][j]) break;
        cnt++;
      }
      a[x][y][0] = cnt;
      ans += cnt - 1;
      i = x, j = y;
      while (1) {
        i--;
        if (!vis[i][j]) break;
        a[i][j][1] += cnt;
        ans += cnt;
        j--;
        if (!vis[i][j]) break;
        a[i][j][0] += cnt;
        ans += cnt;
      }
      i = x, j = y, cnt = 1;
      while (1) {
        i++;
        if (!vis[i][j]) break;
        cnt++;
        j++;
        if (!vis[i][j]) break;
        cnt++;
      }
      a[x][y][1] = cnt;
      ans += cnt;
      i = x, j = y;
      while (1) {
        j--;
        if (!vis[i][j]) break;
        a[i][j][1] += cnt;
        ans += cnt;
        i--;
        if (!vis[i][j]) break;
        a[i][j][0] += cnt;
        ans += cnt;
      }
    } else {
      int i, j;
      long long cnt;
      i = x, j = y, cnt = a[i][j][0];
      a[i][j][0] = 0;
      ans -= cnt - 1;
      while (1) {
        i--;
        if (!vis[i][j]) break;
        a[i][j][1] -= cnt;
        ans -= cnt;
        j--;
        if (!vis[i][j]) break;
        a[i][j][0] -= cnt;
        ans -= cnt;
      }
      i = x, j = y, cnt = a[i][j][1];
      a[i][j][1] = 0;
      ans -= cnt;
      while (1) {
        j--;
        if (!vis[i][j]) break;
        a[i][j][0] -= cnt;
        ans -= cnt;
        i--;
        if (!vis[i][j]) break;
        a[i][j][1] -= cnt;
        ans -= cnt;
      }
    }
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
