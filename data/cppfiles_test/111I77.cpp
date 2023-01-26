#include <bits/stdc++.h>
using namespace std;
#pragma optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
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
pair<int, int> lr[2005];
int dp[2005][2005], pdp[2005][2005];
int psm[2005][2005], ppsm[2005][2005];
long long fact[2005], ifact[2005];
int ans;
inline int qsm(int s, int up, int down, int i) {
  int d = up - min(up, i - 1);
  up -= d;
  s += d;
  d = up - down;
  int e = s + d;
  if (s > e) return 0;
  long long res = ppsm[s + up][min(s, lr[i].second)] - ppsm[s + up][e + 1];
  if (res < 0) {
    res += 998244353;
  }
  return res;
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
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &b[i]);
    lr[i].first = max(0, -k + b[i]);
    lr[i].second = k + b[i];
  }
  for (int i = 2; i < n + 1; i++) {
    mnto(lr[i].second, lr[i - 1].second + 1);
    mxto(lr[i].first, lr[i - 1].first);
  }
  for (int i = 1; i < n + 1; i++) {
    printf("%d: %d %d\n", i, lr[i].first, lr[i].second);
  }
  pdp[0][0] = 1;
  ppsm[0][0] = 1;
  for (int i = 1; i < n + 1; i++) {
    memset(dp, 0, sizeof dp);
    memset(psm, 0, sizeof psm);
    for (int j = lr[i].first; j < lr[i].second + 1; j++) {
      for (int l = 0; l < i + 1; l++) {
        dp[j][l] = 0;
        dp[j][l] = dp[j][l] + (long long)pdp[j][l] * (j + l) % 998244353;
        if (dp[j][l] >= 998244353) {
          dp[j][l] -= 998244353;
        }
        if (l > 0) {
          dp[j][l] = dp[j][l] + pdp[j][l - 1];
          if (dp[j][l] >= 998244353) {
            dp[j][l] -= 998244353;
          }
        }
        int lm = max(-b[i - 1], -k), rm = min(j - b[i - 1], k + 1) - 1;
        dp[j][l] = dp[j][l] + qsm(lm, l + j - lm - 1, l + j - rm - 1, i) *
                                  ifact[l] % 998244353;
        if (dp[j][l] >= 998244353) {
          dp[j][l] -= 998244353;
        }
        psm[j + l][j] = dp[j][l] * fact[l] % 998244353;
      }
    }
    for (int j = lr[i].second; j >= lr[i].first; j--) {
      for (int l = 1; l < i + 1; l++) {
        psm[j + l][j] = psm[j + l][j] + psm[j + l][j + 1];
        if (psm[j + l][j] >= 998244353) {
          psm[j + l][j] -= 998244353;
        }
      }
    }
    swap(dp, pdp);
    swap(psm, ppsm);
  }
  swap(dp, pdp);
  for (int j = lr[n].first; j < lr[n].second + 1; j++) {
    for (int l = 0; l < n + 1; l++) {
      ans = ans + dp[j][l] * perm(n - j, l) % 998244353;
      if (ans >= 998244353) {
        ans -= 998244353;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
