#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool mnto(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool mxto(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
int n, k;
int b[2005];
int dp[105][2005], pdp[105][2005];
int psm[105][2005], ppsm[105][2005];
long long fact[2005], ifact[2005];
int ans;
inline long long qsm(int s, int up, int down, int i) {
  int d = up - min(up, i - 1);
  up -= d;
  s += d;
  d = up - down;
  int e = s + d;
  return (ppsm[s + 52][up] -
          (down - 1 < 0 || abs(e + 1) >= 52 ? 0 : ppsm[e + 52 + 1][down - 1]) +
          998244353) %
         998244353;
}
long long fpow(long long b, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res = res * b % 998244353;
    }
    b = b * b % 998244353;
    p >>= 1;
  }
  return res;
}
inline long long perm(long long n, long long r) {
  if (r < 0 || n < r) return 0;
  return fact[n] * ifact[n - r] % 998244353;
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < 2005; i++) {
    fact[i] = fact[i - 1] * i % 998244353;
  }
  ifact[2005 - 1] = fpow(fact[2005 - 1], 998244353 - 2);
  for (int i = 2005 - 2; i >= 0; i--) {
    ifact[i] = ifact[i + 1] * (i + 1) % 998244353;
  }
  int _t = 1;
  while (_t--) {
    scanf("%d%d", &n, &k);
    ;
    for (int i = 1; i < n + 1; i++) {
      scanf("%d", &b[i]);
      ;
    };
    pdp[52][0] = 1;
    ppsm[52][0] = 1;
    for (int i = 1; i < n + 1; i++) {
      for (int j = max(-b[i], -k); j < k + 1; j++) {
        long long rj = j + b[i];
        assert(rj >= 0);
        for (int l = 0; l < i + 1; l++) {
          dp[j + 52][l] = 0;
          long long pj = rj - b[i - 1];
          if (pj >= -k && pj <= k) {
            dp[j + 52][l] =
                (dp[j + 52][l] + pdp[pj + 52][l] * (rj + l)) % 998244353;
            if (l > 0) {
              dp[j + 52][l] = (dp[j + 52][l] + pdp[pj + 52][l - 1]) % 998244353;
            }
          }
          int lm = max(-b[i - 1], -k), rm = min((int)rj - b[i - 1], k + 1) - 1;
          for (int m = lm; m < rm + 1; m++) {
            pj = m + b[i - 1];
            long long d = rj - pj - 1;
            if (l + d > i - 1) {
              continue;
            }
            dp[j + 52][l] =
                (dp[j + 52][l] + pdp[m + 52][l + d] * fact[l + d] * ifact[l]) %
                998244353;
          };
        }
      }
      for (int j = k; j >= max(-b[i], -k); j--) {
        for (int l = 1; l < i + 1; l++) {
          psm[j + 52][l] =
              (psm[j + 52][l] + psm[j + 52 + 1][l - 1]) % 998244353;
        }
      }
      swap(dp, pdp);
      swap(psm, ppsm);
    }
    swap(dp, pdp);
    for (int j = max(-b[n], -k); j < k + 1; j++) {
      long long rj = j + b[n];
      assert(rj >= 0);
      for (int l = 0; l < n + 1; l++) {
        ans = (ans + dp[j + 52][l] * perm(n - rj, l)) % 998244353;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
