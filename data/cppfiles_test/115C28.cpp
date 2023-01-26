#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10, mod = 998244353;
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int pw[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = pw[i - 1], add(pw[i], pw[i]);
  int n, m, k;
  cin >> n >> m >> k;
  map<int, map<int, int>> a;
  int table[2] = {0};
  map<int, array<int, 2>> rowcnt, colcnt;
  int rownum = 0, colnum = 0;
  int rowban = 0, colban = 0;
  auto upd = [&](int x, int y, int t, int det) {
    int u = x & 1, v = y & 1;
    table[u ^ v ^ t] += det;
    rownum -= (rowcnt[x][0] || rowcnt[x][1]),
        rowban -= (rowcnt[x][0] && rowcnt[x][1]);
    rowcnt[x][v ^ t] += det;
    rownum += (rowcnt[x][0] || rowcnt[x][1]),
        rowban += (rowcnt[x][0] && rowcnt[x][1]);
    colnum -= (colcnt[y][0] || colcnt[y][1]),
        colban -= (colcnt[y][0] && colcnt[y][1]);
    colcnt[y][u ^ t] += det;
    colnum += (colcnt[y][0] || colcnt[y][1]),
        colban += (colcnt[y][0] && colcnt[y][1]);
  };
  while (k--) {
    int x, y, t;
    cin >> x >> y >> t;
    if (a[x][y] != 0) upd(x, y, a[x][y] - 1, -1), a[x][y] = 0;
    if (t >= 0) upd(x, y, t, 1), a[x][y] = t + 1;
    int ans = 0;
    if (rowban == 0) add(ans, pw[n - rownum]);
    if (colban == 0) add(ans, pw[m - colnum]);
    if (table[0] == 0) add(ans, mod - 1);
    if (table[1] == 0) add(ans, mod - 1);
    cout << ans << endl;
  }
}
