#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, 1000000007 - 2ll); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long dp[k + 1];
    dp[0] = 1ll;
    long long ans = 0ll;
    for (int i = 0; i < k; i++) {
      if (n % 2) {
        dp[i + 1] = (dp[i] * power(2ll, n - 1ll)) % 1000000007;
        dp[i + 1] = (dp[i + 1] + 1) % 1000000007;
      } else {
        dp[i + 1] =
            (dp[i] * ((power(2ll, n - 1ll) - 1 + 1000000007) % 1000000007)) %
            1000000007;
        ans = (ans + power(power(2ll, k - i - 1), n)) % 1000000007;
      }
    }
    ans = (ans + dp[k]) % 1000000007;
    cout << ans << "\n";
  }
  return 0;
}
