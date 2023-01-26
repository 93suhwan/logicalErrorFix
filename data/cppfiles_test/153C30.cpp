#include <bits/stdc++.h>
using namespace std;
int C[23 + 1][26], P[23 + 1][26], t[(1 << 23)], dp[(1 << 23)];
void InitialiseDP(int n, int mask) {
  if (n == -1) {
    if (mask != 0) {
      int ans = 1;
      for (int k = 0; k < 26; ++k) {
        ans = (1ll * ans * (1 + P[0][k])) % 998244353;
      }
      dp[mask] = ans;
    }
    return;
  }
  for (int k = 0; k < 26; ++k) {
    P[n][k] = P[n + 1][k];
  }
  InitialiseDP(n - 1, mask);
  for (int k = 0; k < 26; ++k) {
    P[n][k] = min(P[n + 1][k], C[n][k]);
  }
  InitialiseDP(n - 1, mask | (1 << n));
}
void PreProcess(int n) {
  for (int k = 0; k < 26; ++k) {
    P[n][k] = INT_MAX;
  }
  InitialiseDP(n - 1, 0);
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char c : s) {
      ++C[i][c - 'a'];
    }
  }
  m = (1 << n);
  PreProcess(n);
  for (int x = 0, y = m - 1; x < y; ++x, --y) {
    swap(dp[x], dp[y]);
  }
  for (int i = 0; i < n; ++i) {
    int imask = (1 << i);
    for (int mask = m - 1; mask != 0; --mask) {
      if ((mask & imask) != 0) {
        dp[mask] = (998244353 + dp[mask] - dp[(mask ^ imask)]) % 998244353;
      }
    }
  }
  for (int x = 0, y = m - 1; x < y; ++x, --y) {
    swap(dp[x], dp[y]);
  }
  dp[0] = 0;
  int s = 0;
  for (int mask = m - 1; mask != 0; --mask) {
    s = (s + dp[mask]) % 998244353;
  }
  for (int i = 0; i < n; ++i) {
    int imask = (1 << i);
    for (int mask = m - 1; mask != 0; --mask) {
      if ((mask & imask) != 0) {
        dp[mask] = (dp[mask] + dp[(mask ^ imask)]) % 998244353;
        t[mask] = t[(mask ^ imask)] + (i + 1);
      }
    }
  }
  for (int x = 0, y = m - 1; x < y; ++x, --y) {
    swap(dp[x], dp[y]);
    dp[x] = (998244353 + s - dp[x]) % 998244353;
    dp[y] = (998244353 + s - dp[y]) % 998244353;
  }
  long long ans = 0;
  for (int mask = (1 << n) - 1; mask != 0; --mask) {
    long long ansx = 1ll * __builtin_popcount(mask) * t[mask] * dp[mask];
    ans ^= ansx;
  }
  printf("%lld\n", ans);
  return 0;
}
