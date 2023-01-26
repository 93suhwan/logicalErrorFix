#include <bits/stdc++.h>
using namespace std;
constexpr size_t MAXN = 2e5 + 5, MAXM = MAXN << 1;
int cnt[MAXN];
inline void Solve() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cnt[i] = 0;
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    if (x > y) {
      if (cnt[y] == 0) ans++;
      cnt[y]++;
    } else {
      if (cnt[x] == 0) ans++;
      cnt[x]++;
    }
  }
  int q;
  cin >> q;
  for (int i = 1, opt, x, y; i <= q; i++) {
    cin >> opt;
    if (opt == 3)
      cout << n - ans << '\n';
    else {
      cin >> x >> y;
      if (opt == 1) {
        if (x > y) {
          if (cnt[y] == 0) ans++;
          cnt[y]++;
        } else {
          if (cnt[x] == 0) ans++;
          cnt[x]++;
        }
      }
      if (opt == 2) {
        if (x > y) {
          if (cnt[y] == 1) ans--;
          cnt[y]--;
        } else {
          if (cnt[x] == 1) ans--;
          cnt[x]--;
        }
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Solve();
}
