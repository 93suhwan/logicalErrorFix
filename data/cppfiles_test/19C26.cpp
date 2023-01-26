#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
using namespace std;
const int maxn = 1e4 + 5;
int n, a[maxn];
bool check(int x) {
  bitset<2005> dp, tmp;
  for (int i = 0; i <= x; ++i) dp[i] = 1;
  tmp = dp;
  for (int i = 1; i <= n; ++i) {
    dp = (dp << a[i]) | (dp >> a[i]);
    dp &= tmp;
  }
  return dp.any();
}
void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int l = 0, r = 2001;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << "\n";
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int _;
  cin >> _;
  for (int i = 1; i <= _; ++i) test_case();
  return 0;
}
