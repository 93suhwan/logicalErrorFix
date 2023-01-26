#include <bits/stdc++.h>
using namespace std;
double log(double x, double base) { return log(x) / log(base); }
string operator*(const string& a, int b) {
  string res = "";
  for (int i = 1; i <= b; i++) res += a;
  return res;
}
const long double eps = 1e-7;
const long long N = 5e6;
long long n, mod;
long long dp[N], prefx[N];
long long sieve[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> mod;
  dp[1] = 1;
  prefx[1] = 1;
  for (long long i = 1, j = 2; j <= n; j++) {
    sieve[i * j] += dp[1];
    if ((i + 1) * j <= n) sieve[(i + 1) * j] -= dp[1];
  }
  for (long long i = 2; i <= n; i++) {
    sieve[i] = (sieve[i] + sieve[i - 1] % mod) % mod;
    dp[i] = (prefx[i - 1] + sieve[i]) % mod;
    prefx[i] = (prefx[i - 1] + dp[i]) % mod;
    for (long long j = 2; i * j <= n; j++) {
      sieve[i * j] = (sieve[i * j] + dp[i] % mod + mod * mod) % mod;
      if ((i + 1) * j <= n) sieve[(i + 1) * j] -= dp[i];
    }
  }
  cout << (dp[n] + mod * mod) % mod << "\n";
}
