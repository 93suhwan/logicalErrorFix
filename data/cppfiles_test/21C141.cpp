#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  int n;
  cin >> n;
  vector<long long> x(n), s(n);
  vector<long long> dp(n), prefixSums(n + 1, 0);
  int y;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y >> s[i];
    int j = (int)(lower_bound(x.begin(), x.begin() + i, y) - x.begin());
    dp[i] = (x[i] - y) + prefixSums[i] - prefixSums[j];
    dp[i] %= mod;
    prefixSums[i + 1] = prefixSums[i] + dp[i];
    prefixSums[i + 1] %= mod;
  }
  long long ans = x[n - 1] + 1;
  for (int i = 0; i < n; ++i)
    if (s[i]) ans += dp[i];
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << "\n";
}
