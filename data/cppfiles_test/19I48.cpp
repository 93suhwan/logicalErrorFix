#include <bits/stdc++.h>
using namespace std;
int t, n, a[10005];
const int inf = 1e9;
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; c > '9' || c < '0'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (x << 1) + (x << 3) + (c ^ 48);
  x *= f;
}
template <typename T>
void print(T x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  read(t);
  while (t--) {
    read(n);
    for (int i = 1; i <= n; i++) {
      read(a[i]);
    }
    vector<vector<int> > dp(n + 2, vector<int>(2005, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= a[i]; j++) {
        dp[i][0] = min(dp[i][0], dp[i - 1][j] - j + a[i]);
      }
      for (int o = 1; o < a[i]; o++) {
        dp[i][o] = dp[i - 1][o + a[i]];
      }
      for (int o = a[i]; o <= 2000 - a[i]; o++) {
        dp[i][o] = min(max(dp[i - 1][o - a[i]], o), dp[i - 1][o + a[i]]);
      }
      for (int o = 2001 - a[i]; o <= 2000; o++) {
        dp[i][o] = dp[i - 1][o - a[i]];
      }
    }
    int ans = 1e9;
    for (register int i = 0; i <= 2002; i++) {
      ans = min(ans, dp[n][i]);
    }
    print(ans);
    puts("");
  }
  return 0;
}
