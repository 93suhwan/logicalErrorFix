#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 998244353;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Mx = 2e18;
long long Um(long long a, long long b) {
  if (Mx / a < b) return Mx;
  return a * b;
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = Um(a, ans);
      ans %= mod;
    }
    a = Um(a, a) % mod;
    b >>= 1;
  }
  return ans;
}
const long long sz = 1 << 23;
long long pl(long long a, long long b) {
  long long ans = a + b;
  if (ans >= mod) ans -= mod;
  return ans;
}
int32_t kdp[sz][26];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<vector<int32_t>> k(n, vector<int32_t>(26));
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < s.size(); j++) {
      k[i][s[j] - 'a']++;
    }
  }
  vector<long long> cnt(1 << n);
  for (long long i = 0; i < 26; i++) {
    kdp[0][i] = (1 << 15) - 1;
  }
  for (long long i = 1; i < 1 << n; i++) {
    long long bit;
    for (long long j = 0; j < n; j++) {
      if ((i & (1 << j))) {
        bit = j;
        break;
      }
    }
    for (long long j = 0; j < 26; j++) {
      kdp[i][j] = min(kdp[i ^ (1 << bit)][j], k[bit][j]);
    }
    cnt[i] = 1;
    for (long long j = 0; j < 26; j++) {
      cnt[i] = cnt[i] * ((long long)kdp[i][j] + 1) % mod;
    }
  }
  for (long long i = 0; i < 1 << n; i++) {
    for (long long j = 0; j < 26; j++) {
      kdp[i][j] = 0;
    }
  }
  for (long long i = 0; i < 1 << n; i++) {
    long long z = -1;
    for (long long j = 0; j < n; j++) {
      if (i & (1 << j)) z *= -1;
    }
    kdp[i][0] = z * cnt[i];
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long mask = 0; mask < 1 << n; mask++) {
      if (mask & (1 << (i - 1)))
        kdp[mask][i] = pl(kdp[mask][i - 1], kdp[mask ^ (1 << (i - 1))][i - 1]);
      else
        kdp[mask][i] = kdp[mask][i - 1];
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 1 << n; i++) {
    long long p = 0;
    long long sum = 0;
    for (long long j = 0; j < n; j++) {
      if (i & (1 << j)) {
        ++p;
        sum += j + 1;
      }
    }
    ans ^= kdp[i][n] * p * sum;
  }
  cout << ans;
}
