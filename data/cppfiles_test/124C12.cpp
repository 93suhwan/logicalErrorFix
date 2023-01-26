#include <bits/stdc++.h>
using namespace std;
const int N = 2005, D = 2001, mod = 1e9 + 7;
int T, n, ans, pre[N][N + N], suf[N][N + N];
char s[N], t[N];
inline bool check(char id, int c) { return (id == '?' || id == c + 48); }
inline void solve() {
  scanf("%d%s%s", &n, s + 1, t + 1), ans = 0;
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j < N * 2; ++j) pre[i][j] = suf[i][j] = 0;
  pre[0][D] = suf[n + 1][D] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = -i; j <= i; ++j)
      if (pre[i][j + D])
        for (int x = 0; x < 2; ++x)
          for (int y = 0; y < 2; ++y)
            if (check(s[i + 1], x ^ (i & 1)) && check(t[i + 1], y ^ (i & 1)))
              (pre[i + 1][j + D + x - y] += pre[i][j + D]) %= mod;
  for (int i = n + 1; i > 1; --i)
    for (int j = i - n - 1; j <= n - i + 1; ++j)
      if (suf[i][j + D])
        for (int x = 0; x < 2; ++x)
          for (int y = 0; y < 2; ++y)
            if (check(s[i - 1], x ^ (i & 1)) && check(t[i - 1], y ^ (i & 1)))
              (suf[i - 1][j + D + x - y] += suf[i][j + D]) %= mod;
  for (int i = 1; i <= n; ++i)
    for (int j = -i; j <= i; ++j)
      (ans += (long long)pre[i][j + D] * suf[i + 1][D - j] % mod * abs(j) %
              mod) %= mod;
  printf("%d\n", ans);
}
int main() {
  for (scanf("%d", &T); T--;) solve();
}
