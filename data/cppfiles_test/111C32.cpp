#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long mod = 998244353, max_n = 2055, max_k = 55;
long long near[max_n];
long long fact[max_n], ivfc[max_n];
long long dp[2][max_n][max_n], prefix[2][max_n][max_n];
long long modpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) (res *= a) %= mod;
    (a *= a) %= mod;
    b >>= 1;
  }
  return res;
}
long long moddiv(long long a, long long b) {
  return a * modpow(b, mod - 2) % mod;
}
void prep() {
  fact[0] = 1;
  for (long long i = 1; i < max_n; i++) fact[i] = (fact[i - 1] * i) % mod;
  ivfc[max_n - 1] = moddiv(1, fact[max_n - 1]);
  for (long long i = max_n - 2; i >= 0; i--)
    ivfc[i] = (ivfc[i + 1] * (i + 1)) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  prep();
  dp[0][0][0] = prefix[0][0][0] = 1;
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> near[i];
  for (long long i = 0; i < n; i++) {
    long long nxt = (i + 1) & 1, prv = nxt ^ 1;
    for (long long mex = max(0LL, near[i + 1] - k);
         mex <= min(i, near[i + 1] + k); mex++) {
      for (long long big = 0; big <= i + 1; big++) {
        dp[nxt][mex][big] = 0;
      }
    }
    for (long long mex = max(0LL, near[i + 1] - k);
         mex <= min(i + 1, near[i + 1] + k); mex++) {
      for (long long big = 0; big <= i + 1; big++) {
        dp[nxt][mex][big] = prefix[nxt][mex][big + mex] = 0;
        long long prev_mex = mex - 1;
        prev_mex = min(prev_mex, min(i, near[i] + k));
        if (((i == 0) && (prev_mex == 0)) ||
            ((max(0LL, near[i] - k) <= prev_mex) &&
             (prev_mex <= min(i, near[i] + k)))) {
          if (mex + big) {
            dp[nxt][mex][big] =
                (prefix[prv][prev_mex][mex + big - 1] * ivfc[big]) % mod;
          }
        }
      }
    }
    for (long long mex = max(0LL, near[i] - k); mex <= min(i, near[i] + k);
         mex++) {
      for (long long big = 0; big <= i; big++) {
        (dp[nxt][mex][big + 1] += dp[prv][mex][big]) %= mod;
        (dp[nxt][mex][big] += dp[prv][mex][big] * (mex + big)) %= mod;
      }
    }
    for (long long sum = 0; sum <= i + 1; sum++) {
      for (long long mex = max(0LL, near[i + 1] - k);
           mex <= min(sum, min(i + 1, near[i + 1] + k)); mex++) {
        if (mex == max(0LL, near[i + 1] - k))
          prefix[nxt][mex][sum] =
              (dp[nxt][mex][sum - mex] * fact[sum - mex]) % mod;
        else
          prefix[nxt][mex][sum] = (prefix[nxt][mex - 1][sum] +
                                   dp[nxt][mex][sum - mex] * fact[sum - mex]) %
                                  mod;
      }
    }
  }
  long long ans = 0;
  for (long long mex = max(0LL, near[n] - k); mex <= min(n, near[n] + k);
       mex++) {
    for (long long big = 0; big <= n; big++) {
      (ans +=
       dp[n & 1][mex][big] * fact[n - mex] % mod * ivfc[n - mex - big]) %= mod;
    }
  }
  ans %= mod;
  cout << ans << "\n";
}
