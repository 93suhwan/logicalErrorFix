#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, q, x, y;
bool a[N][N];
inline bool chk(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m && !a[x][y];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  long long ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (i == j)
        ans += 4 * i - 3;
      else
        ans += 4 * min(i, j) - 2;
    }
  while (q--) {
    cin >> x >> y;
    long long tmp = 0;
    int i = x, j = y, l = 0, r = 0;
    while (1) {
      --i;
      if (!chk(i, j)) break;
      ++l;
      --j;
      if (!chk(i, j)) break;
      ++l;
    }
    i = x, j = y;
    while (1) {
      ++j;
      if (!chk(i, j)) break;
      ++r;
      ++i;
      if (!chk(i, j)) break;
      ++r;
    }
    tmp += (l + 1) * (r + 1);
    i = x, j = y, l = r = 0;
    while (1) {
      --j;
      if (!chk(i, j)) break;
      ++l;
      --i;
      if (!chk(i, j)) break;
      ++l;
    }
    i = x, j = y;
    while (1) {
      ++i;
      if (!chk(i, j)) break;
      ++r;
      ++j;
      if (!chk(i, j)) break;
      ++r;
    }
    tmp += (l + 1) * (r + 1);
    --tmp;
    a[x][y] ? (ans += tmp) : (ans -= tmp), a[x][y] ^= 1;
    cout << ans << '\n';
  }
}
