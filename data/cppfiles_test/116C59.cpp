#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long mod = 998244353;
int t;
long long h, n;
long long a[500050], dp[500050][2];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
      dp[i][0] = dp[i][1] = 0;
    }
    set<long long> s;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      s.insert(a[i]);
      if (a[i] == 0) {
        dp[0][1] = (dp[0][1] * 2 + 1) % mod;
        dp[2][0] = (dp[2][0] * 2) % mod;
      } else if (a[i] == 1) {
        dp[1][0] = (dp[1][0] * 2 + 1) % mod;
        dp[1][1] = (dp[1][1] * 2 + dp[0][1]) % mod;
        dp[3][0] = (dp[3][0] * 2) % mod;
      } else {
        dp[a[i]][0] = (dp[a[i]][0] * 2 + dp[a[i] - 2][1]) % mod;
        dp[a[i]][1] = (dp[a[i]][1] * 2 + dp[a[i] - 1][1]) % mod;
        dp[a[i] + 2][0] = (dp[a[i] + 2][0] * 2) % mod;
      }
    }
    for (auto i : s) {
      ans = (ans + dp[i][0] + dp[i][1]) % mod;
    }
    printf("%lld\n", ans);
  }
}
