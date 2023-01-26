#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const long long M = 998244353;
const long long INF = LLONG_MAX;
const long long MOD = 1e9 + 7;
const float pi = 3.1415926535897932384626433832795028841971693993751058209749;
using namespace std;
long long Prime(long long x) {
  bool flag = 1;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      flag = 0;
      break;
    }
  }
  return flag;
}
long long gcd(long long r, long long b) {
  long long x = 1;
  while (b != 0) {
    x = b;
    b = r % b;
    r = x;
  }
  return x;
}
long long po(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x) % MOD;
    y /= 2;
    x = (x * x) % MOD;
  }
  return res;
}
void io() {}
void solve() {
  long long n, mod;
  cin >> n >> mod;
  vector<long long> dp(n + 1, 0);
  vector<long long> pre(n + 1, 0);
  long long pre_sum = 0;
  for (long long i = 1; i <= n; i++) {
    if (i == 1) {
      dp[i] = 1;
      pre_sum = 1;
      pre[i] = 1;
      continue;
    }
    pre[i] += pre[i - 1];
    dp[i] = (pre[i] + pre_sum) % mod;
    dp[i] += (i / 2);
    if (i % 2 == 1) dp[i] += 1;
    dp[i]--;
    dp[i] %= mod;
    for (long long a = 2 * i, p = 2; a <= n; a += i, p += 1) {
      pre[a] += dp[i];
      pre[a] %= mod;
      long long subIdx = a + p;
      if (subIdx <= n) {
        pre[subIdx] -= dp[i];
        if (pre[subIdx] < 0) {
          pre[subIdx] = ((pre[subIdx] % mod) + mod) % mod;
        }
      }
    }
    pre_sum += dp[i];
    pre_sum %= mod;
  }
  cout << dp[n] << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
