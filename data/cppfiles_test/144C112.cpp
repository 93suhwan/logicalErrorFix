#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, now, ans1[200010], ans2[200010], da, cnt, vis[200010];
int main() {
  int T, i, j, l, t;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    u = n - n / m * m;
    if (u == 0) u = m;
    da = (n - 1) / m + 1;
    v = u * da;
    now = 1;
    for (i = 1; i <= k; i++) {
      for (j = 1; j <= n; j++) vis[j] = 0;
      cnt = 0;
      for (j = 1; j <= v; j++) {
        if (j % da == 1) cout << da << " ";
        t = ((i - 1) * v + j) % n;
        if (t == 0) t = n;
        cout << t << " ";
        vis[t] = 1;
        if (j % da == 0) cout << endl;
      }
      for (j = 1; j <= n; j++) {
        if (vis[j] == 0) {
          if (cnt % (da - 1) == 0) cout << da - 1 << " ";
          cnt++;
          cout << j << " ";
          if (cnt % (da - 1) == 0) cout << endl;
        }
      }
    }
  }
}
