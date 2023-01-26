#include <bits/stdc++.h>
using namespace std;
string S[23];
int t[(1 << 23)], dpU[(1 << 23)], dpI[(1 << 23)];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  for (int mask = (1 << n) - 1; mask != 0; --mask) {
    dpI[mask] = 1;
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    for (int mask = (1 << n) - 1; mask != -1; --mask) {
      t[mask] = INT_MAX;
    }
    for (int i = 0; i < n; ++i) {
      int imask = (1 << i), x = 1;
      for (char d : S[i]) {
        x += (d == c);
      }
      for (int mask = (1 << n) - 1; mask != 0; --mask) {
        if ((mask & imask) != 0) {
          t[mask] = min(t[(mask ^ imask)], x);
        }
      }
    }
    for (int mask = (1 << n) - 1; mask != 0; --mask) {
      dpI[mask] = (1ll * dpI[mask] * t[mask]) % 998244353;
    }
  }
  for (int mask = (1 << n) - 1; mask != -1; --mask) {
    t[mask] = 0;
  }
  for (int i = 0; i < n; ++i) {
    int imask = (1 << i);
    for (int mask = (1 << n) - 1; mask != 0; --mask) {
      if ((mask & imask) != 0) {
        t[mask] += (i + 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    dpU[(1 << i)] = dpI[(1 << i)];
  }
  for (int mask = 1, m = (1 << n); mask < m; ++mask) {
    if (__builtin_popcount(mask) < 2) {
      continue;
    }
    int imask = (1 << __builtin_ctz(mask));
    int jmask = (1 << __builtin_ctz(mask ^ imask));
    int rmask = mask ^ imask ^ jmask;
    int ans = (0ll + dpU[(imask | rmask)] + dpU[(jmask | rmask)] - dpU[rmask] -
               dpI[(imask | jmask)] + (rmask == 0 ? 0 : dpI[mask])) %
              998244353;
    dpU[mask] = (998244353 + ans) % 998244353;
  }
  long long ans = 0;
  for (int mask = (1 << n) - 1; mask != 0; --mask) {
    long long ansx = 1ll * __builtin_popcount(mask) * t[mask] * dpU[mask];
    ans ^= ansx;
  }
  printf("%lld\n", ans);
  return 0;
}
