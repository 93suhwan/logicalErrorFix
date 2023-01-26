#include <bits/stdc++.h>
using namespace std;
const long long dim = 500009, mod = 998244353;
struct elem {
  long long x, s;
} stiva[dim];
long long vf = 1;
long long n, a[dim];
long long dp[dim], sum[dim];
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
  sum[1] = a[1] % mod;
  stiva[vf] = {a[vf], vf};
  for (long long i = 1; i <= n; i++) {
    long long x = a[i + 1], s;
    if (i % 2 == 1) {
      dp[i] = sum[vf];
      s = (mod - dp[i]) % mod;
    } else {
      dp[i] = (mod - sum[vf]) % mod;
      s = dp[i];
    }
    while (vf && stiva[vf].x > x) {
      s += stiva[vf--].s;
      s %= mod;
    }
    stiva[++vf] = {x, s};
    sum[vf] = sum[vf - 1] + x * s;
    sum[vf] %= mod;
  }
  cout << dp[n];
}
