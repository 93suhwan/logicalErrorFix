#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long power(long long a, long long b);
const long long N = 505;
long long dp[N][N];
long long n, x;
long long fact[N], invfact[N];
long long nCr(long long n, long long r) {
  if (r > n || n < 0 || r < 0) return 0;
  long long ans = fact[n];
  ans = (ans % 998244353 * invfact[r]) % 998244353;
  ans = (ans % 998244353 * invfact[n - r]) % 998244353;
  return ans;
}
void init(long long n) {
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % 998244353;
  }
  invfact[n] = power(fact[n], 998244353 - 2);
  for (long long i = n - 1; i >= 0; i--) {
    invfact[i] = (i + 1) * (invfact[i + 1]) % 998244353;
  }
}
void add(long long &a, long long b) {
  a = (a % 998244353 + b % 998244353) % 998244353;
}
long long mul(long long a, long long b) {
  return ((a % 998244353) * (b % 998244353)) % 998244353;
}
long long solve(long long alive, long long lower) {
  if (alive == 0) return 1;
  if (alive == 1) return 0;
  if (lower > x) return 0;
  long long &res = dp[alive][lower];
  if (~res) return res;
  res = 0;
  long long range = min(alive - 1, x - lower + 1);
  for (long long i = 0; i <= alive; i++) {
    add(res, mul(nCr(alive, i) * power(range, i),
                 solve(alive - i, lower + alive - 1)));
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tt = 1;
  while (tt--) {
    memset(dp, -1, sizeof dp);
    init(501);
    cin >> n >> x;
    cout << solve(n, 1) << "\n";
  }
  return 0;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2)
      b--, res = (res % 998244353 * a % 998244353) % 998244353;
    else
      b = b / 2, a = (a % 998244353 * a % 998244353) % 998244353;
  }
  return res;
}
