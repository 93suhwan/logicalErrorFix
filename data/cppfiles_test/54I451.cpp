#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
long long int binpow(long long int a, long long int b) {
  long long int r = 1;
  while (b) {
    if (b & 1) r = (r % MOD * a % MOD) % MOD;
    a = (a % MOD * a % MOD) % MOD;
    b /= 2;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1, testcases = 1;
  cin >> t;
  while (t >= testcases) {
    long long int n, k;
    cin >> n >> k;
    long long int ans = 0;
    if (n % 2) {
      ans = (binpow(2, n - 1) + 1) % MOD;
      ans = binpow(ans, k);
    } else {
      long long int dp[k + 1];
      dp[0] = 1;
      dp[1] = binpow(2, n - 1);
      long long int c = (binpow(2, n - 1) - 1 + MOD) % MOD;
      for (long long int i = 2; i <= k; i++) {
        long long int p = (n % MOD * (i - 1) % MOD) % MOD;
        long long int o = binpow(2, p);
        dp[i] = (o % MOD + (c % MOD * dp[i - 1] % MOD) % MOD) % MOD;
      }
      ans = dp[k];
    }
    cout << ans << "\n";
    testcases++;
  }
  cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms"
       << "\n";
  return 0;
}
