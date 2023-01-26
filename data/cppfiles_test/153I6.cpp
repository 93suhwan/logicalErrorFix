#include <bits/stdc++.h>
using namespace std;
string S[23];
int t[(1 << 23)], dp[(1 << 23)];
void Print(int n, string s) {
  cout << s << '\n';
  for (int mask = 0; mask < (1 << n); ++mask) {
    printf("mask = %d dp = %d\n", mask, dp[mask]);
  }
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  m = (1 << n);
  for (int mask = m - 1; mask != 0; --mask) {
    dp[mask] = 1;
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    for (int mask = m - 1; mask != -1; --mask) {
      t[mask] = INT_MAX;
    }
    for (int i = 0; i < n; ++i) {
      int imask = (1 << i), x = 1;
      for (char d : S[i]) {
        x += (d == c);
      }
      for (int mask = m - 1; mask != 0; --mask) {
        if ((mask & imask) != 0) {
          t[mask] = min(t[(mask ^ imask)], x);
        }
      }
    }
    for (int mask = m - 1; mask != 0; --mask) {
      dp[mask] = (1ll * dp[mask] * t[mask]) % 998244353;
    }
  }
  for (int mask = m - 1; mask != -1; --mask) {
    t[mask] = 0;
  }
  for (int i = 0; i < n; ++i) {
    int imask = (1 << i);
    for (int mask = m - 1; mask != 0; --mask) {
      if ((mask & imask) != 0) {
        t[mask] = t[(mask ^ imask)] + (i + 1);
      }
    }
  }
  for (int x = 0, y = m - 1; x < y; ++x, --y) {
    swap(dp[x], dp[y]);
  }
  for (int i = 0; i < n; ++i) {
    int imask = (1 << i);
    for (int mask = m - 1; mask != 0; --mask) {
      if ((mask & imask) != 0) {
        dp[mask] = (dp[mask] - dp[(mask ^ imask)]) % 998244353;
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
  s = (s + 998244353) % 998244353;
  for (int i = 0; i < n; ++i) {
    int imask = (1 << i);
    for (int mask = m - 1; mask != 0; --mask) {
      if ((mask & imask) != 0) {
        dp[mask] = (dp[mask] + dp[(mask ^ imask)]) % 998244353;
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
