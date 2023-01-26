#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], nex[maxn], pos[maxn];
int n, q, sq;
int cal(int x) {
  for (int i = 1; i <= sq; ++i) {
    x = a[x];
  }
  return x;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  sq = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    nex[i] = cal(i);
  }
  while (q--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      swap(pos[a[x]], pos[a[y]]);
      swap(a[x], a[y]);
      nex[x] = cal(x);
      nex[y] = cal(y);
      for (int i = 1; i <= sq; ++i) {
        x = pos[x];
        y = pos[y];
      }
      int nx = cal(x), ny = cal(y);
      for (int i = 1; i <= sq; ++i) {
        nex[x] = nx;
        nex[y] = ny;
        nx = a[nx];
        ny = a[ny];
        x = a[x];
        y = a[y];
      }
    }
    if (op == 2) {
      while (y >= sq) {
        y -= sq;
        x = nex[x];
      }
      while (y--) {
        x = a[x];
      }
      cout << x << '\n';
    }
  }
}
