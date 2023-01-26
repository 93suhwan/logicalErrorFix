#include <bits/stdc++.h>
using namespace std;
const int N = 10002;
int n, a[N], f[N], dp[N];
int ok(int x) {
  for (int i = 0; i <= x; i++) f[i] = 1;
  for (int i = 1; i <= n; i++) {
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j <= 2000; j++) {
      if (j - a[i] >= 0) dp[j] |= f[j - a[i]];
      if (j + a[i] <= x) dp[j] |= f[j + a[i]];
    }
    swap(dp, f);
  }
  int flag = 0;
  for (int i = (0); i <= (x); ++i) flag |= f[i];
  return flag;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    for (int i = (1); i <= (n); ++i) cin >> a[i];
    int l = 0, r = 2000, ans;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
