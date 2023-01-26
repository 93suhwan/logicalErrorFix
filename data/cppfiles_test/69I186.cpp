#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
long long factorial(long long n) {
  if (n == 0) return 1;
  return (n % 1000000007 * factorial(n - 1) % 1000000007) % 1000000007;
}
long long power(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2) {
      x = (x * y) % 1000000007;
    }
    y = (y * y) % 1000000007;
    b /= 2;
  }
  return x % 1000000007;
}
long long modular_inverse(long long n) { return power(n, 1000000007 - 2); }
long long ncr(long long n, long long k) {
  long long b =
      (factorial(k) % 1000000007 * factorial(n - k) % 1000000007) % 1000000007;
  return (factorial(n) % 1000000007 * modular_inverse(b) % 1000000007);
}
long long is_prime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long solve(string str, string v) {
  long long a = str.size(), b = v.size();
  vector<vector<long long>> dp(a + 1, vector<long long>(b + 1, 0));
  long long ans = 0;
  for (long long i = 1; i <= a; i++) {
    for (long long j = 1; j <= b; j++) {
      if (str[i - 1] == v[j - 1]) {
        if (dp[i - 1][j - 1] == j - 1) dp[i][j] = 1 + dp[i - 1][j - 1];
      } else
        dp[i][j] = dp[i - 1][j];
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, m, i, j, k, x;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    long long ans = INT_MAX;
    for (i = 0; i <= 50; i++) {
      k = pow(2, i);
      string v = to_string(k);
      long long a = str.size(), b = v.size();
      long long match = solve(str, v);
      ans = min(ans, a - match + b - match);
    }
    cout << ans << endl;
  }
  return 0;
}
