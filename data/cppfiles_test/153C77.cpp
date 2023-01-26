#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long double pi = 3.141592653589793238;
void pls() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long n;
long long a[1 << 23], dp[1 << 23];
void solve() {
  {
    cin >> n;
    int16_t **freq = new int16_t *[1 << n];
    for (long long i = 0; i < (1 << n); ++i) freq[i] = new int16_t[26];
    for (long long i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (long long c = 0; c < 26; ++c) freq[1 << i][c] = 0;
      for (char ch : s) freq[1 << i][ch - 'a']++;
    }
    for (long long m = 1; m < (1 << n); ++m) {
      a[m] = 1;
      long long bits = __builtin_popcountll(m);
      if (bits > 1) {
        long long b = __builtin_ctzll(m);
        long long old_m = m - (1 << b);
        for (long long i = 0; i < 26; ++i) {
          freq[m][i] = min(freq[old_m][i], freq[1 << b][i]);
          a[m] = (a[m] * (freq[m][i] + 1)) % mod;
        }
      } else {
        for (long long i = 0; i < 26; ++i)
          a[m] = (a[m] * (freq[m][i] + 1)) % mod;
      }
      if (bits % 2 == 0) a[m] = (mod - a[m]) % mod;
    }
    for (long long i = 0; i < (1 << n); ++i) dp[i] = a[i];
    for (long long i = 0; i < n; ++i)
      for (long long m = 0; m < (1 << n); ++m)
        if (m & (1 << i)) dp[m] += dp[m ^ (1 << i)], dp[m] %= mod;
    long long ans = 0;
    for (long long m = 1; m < (1 << n); ++m) {
      long long k = 0, sum = 0;
      for (long long i = 0; i < n; ++i)
        if ((m >> i) & 1) {
          k++, sum += i + 1;
        }
      long long cur = dp[m] * k * sum;
      ans ^= cur;
    }
    cout << ans << '\n';
  }
}
int32_t main() {
  pls();
  solve();
  return 0;
}
