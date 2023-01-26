#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("03")
#pragma optimize("g", on)
using namespace std;
long long power(long long a, long long b) {
  if (!b) return 1;
  long long temp = power(a, b / 2);
  temp = (temp * temp);
  if (b % 2) return (a * temp) % 1000000007;
  return temp % 1000000007;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long comb(long long n, long long r) {
  if (r < 0 || r > n) return 0;
  if ((n - r) < r) r = n - r;
  long long a = 1;
  for (long long i = n; i > n - r; --i) {
    a = a * i;
  }
  for (long long i = 1; i < r + 1; ++i) {
    a = a / i;
  }
  return a;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  long long dp[200001];
  dp[0] = 1;
  for (long long i = 1; i < 200001; i++) {
    dp[i] = (dp[i - 1] * i) % 1000000007;
  }
  long long factor = power(2, 1000000007 - 2) % 1000000007;
  while (t--) {
    long long n;
    cin >> n;
    cout << (dp[2 * n] * factor) % 1000000007 << "\n";
  }
  return 0;
}
