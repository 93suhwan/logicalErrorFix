#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int mod = 1e9 + 7;
char s[N], t[N];
int dp[N][N << 2], ds[N][N << 2];
int n, T;
int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int mul(int x, int y) { return 1ll * x * y % mod; }
int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
bool pan(char c, char c1) { return (c == '?') || (c == c1); }
char get(char c) {
  if (c == '?')
    return c;
  else
    return 1 - (c - '0') + '0';
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (int i = 1; i <= n; i++)
      if (i & 1) s[i] = get(s[i]), t[i] = get(t[i]);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n + n; j++) dp[i][j] = ds[i][j] = 0;
    ds[0][n] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = n - i + 1; j <= n + i - 1; j++) {
        if (pan(s[i], '0') && pan(t[i], '0'))
          ds[i][j] = add(ds[i - 1][j], ds[i][j]),
          dp[i][j] =
              add(dp[i][j], add(dp[i - 1][j], mul(ds[i - 1][j], abs(n - j))));
        if (pan(s[i], '1') && pan(t[i], '1'))
          ds[i][j] = add(ds[i - 1][j], ds[i][j]),
          dp[i][j] =
              add(dp[i][j], add(dp[i - 1][j], mul(ds[i - 1][j], abs(n - j))));
        if (pan(s[i], '0') && pan(t[i], '1'))
          ds[i][j - 1] = add(ds[i][j - 1], ds[i - 1][j]),
                    dp[i][j - 1] =
                        add(dp[i][j - 1],
                            add(dp[i - 1][j], mul(ds[i - 1][j], abs(n - j))));
        if (pan(s[i], '1') && pan(t[i], '0'))
          ds[i][j + 1] = add(ds[i][j + 1], ds[i - 1][j]),
                    dp[i][j + 1] =
                        add(dp[i][j + 1],
                            add(dp[i - 1][j], mul(ds[i - 1][j], abs(n - j))));
      }
    }
    printf("%d\n", dp[n][n]);
  }
}
