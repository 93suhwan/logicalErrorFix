#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long inf = 8e18;
const int LOG = 20;
long long pw(long long a, long long b, long long M = mod, long long ret = 1) {
  while (b) {
    ret = ret * (b & 1 ? a : 1) % M, a = a * a % M, b >>= 1;
  }
  return ret;
}
long long q, n, s, k;
int main() {
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    long long x = n / k;
    long long r = n - x * k;
    long long cu = 2ll * x * k + r;
    if (s < k) {
      printf("NO\n");
      continue;
    }
    if (s == k) {
      printf("YES\n");
      continue;
    }
    if (n < k) {
      cu = s / (2 * k) * k + min(k, s % (2 * k) + 1);
      if (cu > n) {
        printf("NO\n");
        continue;
      } else {
        printf("YES\n");
        continue;
      }
    }
    if (cu <= s) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
