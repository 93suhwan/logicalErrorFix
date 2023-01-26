#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
const long long longinf = 1LL << 60;
const long long mod = 998244353;
const long long N = 5e5 + 10;
long long a[N];
long long dp[N][2];
signed main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  stack<pair<long long, long long>> even, odd;
  long long esum = a[1], osum = 0;
  even.emplace(a[1], 1);
  odd.emplace(a[1], 0);
  for (long long i = 1; i < n; i++) {
    dp[i + 1][0] = osum;
    dp[i + 1][1] = esum;
    long long os = 0;
    while (odd.size() && odd.top().first > a[i + 1]) {
      osum += mod - odd.top().first * odd.top().second % mod;
      if (osum >= mod) osum -= mod;
      os += odd.top().second;
      os %= mod;
      odd.pop();
    }
    osum += a[i + 1] * (os + dp[i + 1][1]) % mod;
    osum %= mod;
    long long es = 0;
    while (even.size() && even.top().first > a[i + 1]) {
      esum += mod - even.top().first * even.top().second % mod;
      if (esum >= mod) esum -= mod;
      es += even.top().second;
      es %= mod;
      even.pop();
    }
    esum += a[i + 1] * (es + dp[i + 1][0]) % mod;
    esum %= mod;
    odd.emplace(a[i + 1], (os + dp[i + 1][1] % mod));
    even.emplace(a[i + 1], (es + dp[i + 1][0]) % mod);
  }
  if (n % 2)
    cout << (esum - osum + mod) % mod << endl;
  else
    cout << (osum - esum + mod) % mod << endl;
  return 0;
}
