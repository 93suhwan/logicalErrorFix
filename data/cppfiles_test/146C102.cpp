#include <bits/stdc++.h>
using namespace std;
const int k = 230;
const int maxn = 1e5 + 5;
int p[maxn], rp[maxn], pk[maxn], vis[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> p[i], rp[p[i]] = i;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    int x = i;
    for (int j = 1; j <= k; ++j) x = p[x];
    int px = i;
    while (!vis[x]) {
      vis[x] = 1;
      pk[px] = x;
      x = p[x];
      px = p[px];
    }
  }
  while (q--) {
    int op;
    cin >> op;
    int x, y;
    cin >> x >> y;
    if (op == 1) {
      swap(p[x], p[y]);
      swap(rp[p[x]], rp[p[y]]);
      int px = x, py = y;
      for (int j = 1; j <= k; ++j) x = p[x], y = p[y];
      pk[px] = x, pk[py] = y;
      for (int j = 1; j <= k; ++j) {
        x = rp[x], px = rp[px], pk[px] = x;
        y = rp[y], py = rp[py], pk[py] = y;
      }
    } else {
      while (y >= k) {
        y -= k;
        x = pk[x];
      }
      while (y > 0) {
        y -= 1;
        x = p[x];
      }
      cout << x << '\n';
    }
  }
}
