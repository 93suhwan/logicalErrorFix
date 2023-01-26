#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
const int N = 3e5 + 7;
int n, m;
int mnrr[57], mxrr[57];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> mnrr[i] >> mxrr[i];
  vector<long long> ans(m + 1, 0);
  for (int g = 1; g <= m; g++) {
    long long limit = m / g;
    vector<long long> dp(limit + 1, 1);
    for (int i = 1; i <= n; i++) {
      long long rngmn = (mnrr[i] + g - 1) / g;
      long long rngmx = mxrr[i] / g;
      if (rngmn > rngmx) {
        dp[limit] = 0;
        break;
      }
      vector<long long> ndp(limit + 1, 0);
      for (int sum = rngmn; sum <= limit; sum++) {
        ndp[sum] = dp[sum - rngmn];
        if (sum > rngmx) {
          ndp[sum] = (ndp[sum] - dp[sum - rngmx - 1]) % MOD;
        }
        ndp[sum] = (ndp[sum - 1] + ndp[sum]) % MOD;
      }
      dp = ndp;
    }
    ans[g] = dp[limit];
  }
  for (int i = m; i >= 1; i--) {
    for (int j = i + i; j <= m; j += i) {
      ans[i] = (ans[i] - ans[j] + MOD) % MOD;
    }
  }
  cout << ans[1] << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
