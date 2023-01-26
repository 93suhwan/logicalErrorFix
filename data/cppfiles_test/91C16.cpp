#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
using namespace std;
const int mod = 998244353;
int a[100100];
int32_t main() {
  int qwer;
  cin >> qwer;
  unordered_map<int, int> dp, dp1;
  for (int _ = 0; _ < qwer; ++_) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    long long ans = 0;
    dp.clear(), dp1.clear();
    for (int i = n; i > 0; --i) {
      dp[a[i]] = 1;
      for (pair<int, int> d : dp1) {
        int x = d.first, s = d.second;
        int k = (a[i] + x - 1) / x;
        int nx = a[i] / k;
        ans += 1LL * i * s * (k - 1);
        dp[nx] += s;
      }
      ans %= mod;
      swap(dp1, dp);
      dp.clear();
    }
    cout << ans << "\n";
  }
  return 0;
}
