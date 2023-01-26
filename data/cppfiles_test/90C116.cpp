#include <bits/stdc++.h>
using namespace std;
constexpr size_t MAXN = 0;
inline void Solve() {
  long long x, y;
  cin >> x >> y;
  long long ans = 0;
  if (x == y) ans = x;
  if (x > y) ans = x + y;
  if (x < y) ans = (y / x * x + y) / 2;
  cout << ans << '\n';
}
signed main(void) {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) Solve();
}
