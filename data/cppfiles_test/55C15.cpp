#include <bits/stdc++.h>
using namespace std;
long long fastPow(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long fact(long long n) {
  if (n <= 1) return 1;
  long long dp[n + 1];
  dp[0] = 1;
  dp[1] = 1;
  for (long long i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] * i) % (1000000007);
  }
  return dp[n];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc;
  tc = 1;
  for (long long ii = 0; ii < tc; ii++) {
    long long n;
    cin >> n;
    cout << (6 * (fastPow(4, pow(2, n) - 2, 1000000007))) % 1000000007 << "\n";
  }
}
