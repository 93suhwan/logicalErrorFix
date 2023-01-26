#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
  int n;
  cin >> n;
  int x[200000];
  int y[200000];
  int s[200000];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> s[i];
  }
  int a[200000];
  int pre_sum[200001];
  pre_sum[0] = 0;
  for (int i = 0; i < n; i++) {
    pre_sum[i + 1] = (pre_sum[i] + x[i] - y[i]) % MOD;
    int l = upper_bound(x, x + i, y[i]) - x;
    a[i] = (MOD - pre_sum[l - 1] + pre_sum[i + 1]) % MOD;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 1) {
      ans = (ans + a[i]) % MOD;
    }
  }
  ans = (ans + x[n - 1] + 1) % MOD;
  cout << ans << '\n';
  return 0;
}
