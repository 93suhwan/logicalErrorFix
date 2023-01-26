#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long B) { return (unsigned long long)rng() % B; }
void swap(long long& x, long long& y) { (x ^= y), (y ^= x), (x ^= y); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long dp[n + 2][2];
    for (int i = 0; i < n + 2; i++)
      for (int j = 0; j < 2; j++) dp[i][j] = 0;
    long long inp;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      cin >> inp;
      dp[inp + 1][0] =
          (dp[inp][0] + 2 * dp[inp + 1][0] % 998244353) % 998244353;
      dp[inp + 1][1] = (dp[inp + 1][1] * 2) % 998244353;
      if (inp > 0)
        dp[inp - 1][1] =
            (dp[inp - 1][0] + dp[inp - 1][1] * 2 % 998244353) % 998244353;
    }
    long long ans = 0;
    for (int i = 0; i < n + 1; i++) {
      ans = (ans +
             ((i != 0 ? dp[i][0] : 0) + (i != n ? dp[i][1] : 0)) % 998244353) %
            998244353;
    }
    cout << ans << endl;
  }
  return 0;
}
