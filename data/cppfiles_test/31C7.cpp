#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int mx[1 << 19], mn[1 << 19], f[1 << 19];
signed main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < (1 << k); ++i) mx[i] = -inf, mn[i] = f[i] = inf;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    mx[x] = mn[x] = 0;
  }
  for (int d = 0; d < k; ++d)
    for (int i = 0; i < (1 << k); ++i)
      if (i >> d & 1) {
        int l = i ^ (1 << d), r = i;
        int x = f[l], y = f[r];
        f[l] = min({f[l], y, mn[r] - mx[l] + (1 << d)}),
        f[r] = min({f[r], x, mn[l] - mx[r] + (1 << d)});
        int mxl = mx[l], mxr = mx[r], mnl = mn[l], mnr = mn[r];
        mx[l] = max(mx[l], mxr + (1 << d));
        mx[r] = max(mx[r], mxl + (1 << d));
        mn[l] = min(mn[l], mnr + (1 << d));
        mn[r] = min(mn[r], mnl + (1 << d));
      }
  for (int i = 0; i < (1 << k); ++i) cout << f[i] << " ";
}
