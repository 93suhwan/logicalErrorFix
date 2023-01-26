#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void debug(int x = 0) { cout << "--ok(" << x << ")" << endl; }
const int N = 1e3 + 5;
long long f[N][N][2];
int g[N][N];
long long ans = 0, tot;
void work(int l, int r, int k) {
  if (l < 1 || r < 1) return;
  if (g[l][r] == 0) return;
  long long now = f[l][r][k];
  if (k == 0) {
    f[l][r][k] = f[l][r + 1][1] + 1;
    ans = ans + f[l][r][k] - now;
    work(l - 1, r, 1);
  } else {
    f[l][r][k] = f[l + 1][r][0] + 1;
    ans = ans + f[l][r][k] - now;
    work(l, r - 1, 0);
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      f[i][j][0] = 1 + f[i][j + 1][1];
      f[i][j][1] = 1 + f[i + 1][j][0];
      ans = ans + f[i][j][0] + f[i][j][1] - 1;
      g[i][j] = 1;
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    g[l][r] = !g[l][r];
    if (g[l][r]) {
      f[l][r][0] = 1 + f[l][r + 1][1];
      f[l][r][1] = 1 + f[l + 1][r][0];
      ans = ans + f[l][r][0] + f[l][r][1] - 1;
    } else {
      ans = ans - (f[l][r][0] + f[l][r][1] - 1);
      f[l][r][0] = f[l][r][1] = 0;
    }
    work(l, r - 1, 0);
    work(l - 1, r, 1);
    cout << ans << endl;
  }
  return 0;
}
