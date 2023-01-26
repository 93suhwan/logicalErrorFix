#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
const long long p = 998244353;
const long long maxn = 23;
long long cnt[maxn][26];
long long cnt1[26];
long long val[1 << maxn];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (auto h : s) cnt[i][h - 'a']++;
  }
  for (long long mask = 0; mask < (1 << n); ++mask) {
    for (long long j = 0; j < 26; ++j) cnt1[j] = 1e9;
    for (long long j = 0; j < n; ++j) {
      if (mask & (1 << j)) {
        for (long long k = 0; k < 26; ++k) cnt1[k] = min(cnt1[k], cnt[j][k]);
      }
    }
    long long val1 = 1;
    for (auto h : cnt1) {
      val1 *= (h + 1);
      val1 %= p;
    }
    val[mask] = val1;
    if (mask == 0) val[mask] = 0;
    if ((__builtin_popcount(mask)) % 2 == 0) {
      val[mask] = (p - val[mask]) % p;
    }
  }
  val[0] = 0;
  long long res = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long mask = 0; mask < (1 << n); ++mask) {
      if (!(mask & (1 << i))) {
        val[mask + (1 << i)] += (val[mask]);
        val[mask + (1 << i)] %= p;
      }
    }
  }
  for (long long mask = 1; mask < (1 << n); ++mask) {
    long long ans = val[mask];
    ans %= p;
    ans += p;
    ans %= p;
    long long z = 0;
    for (long long j = 0; j < n; ++j) {
      if (mask & (1 << j)) {
        z += (j + 1);
      }
    }
    res ^= ((ans * z * __builtin_popcount(mask)));
  }
  cout << res;
  return 0;
}
