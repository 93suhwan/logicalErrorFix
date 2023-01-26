#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t n;
  cin >> n;
  bool f = 1;
  if (n < 0) f = 0, n *= -1;
  int64_t l = 0, r = 1e9, ans;
  while (l <= r) {
    int64_t mid = (l + r) / 2;
    if ((mid * (mid + 1)) / 2 >= n) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  l = 0, r = 1e9;
  int64_t ans2;
  while (l <= r) {
    int64_t mid = (l + r) / 2;
    if ((ans * (ans + 1)) / 2 - (mid * (mid + 1)) / 2 >= n) {
      ans2 = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  ans2++;
  if (ans == ans2) ans2 -= 1, ans2 *= -1;
  if (!f)
    cout << (-ans) << " " << -ans2 << '\n';
  else
    cout << ans2 << " " << ans << '\n';
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
