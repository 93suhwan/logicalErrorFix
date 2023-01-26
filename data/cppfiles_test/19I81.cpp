#include <bits/stdc++.h>
using namespace std;
int t, n, a[10005], dp[10005][2005];
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
    memset(dp, 63, sizeof dp);
    read(n);
    for (int i = 1; i <= n; i++) {
      read(a[i]);
    }
    dp[0][0] = 0;
    for (register int i = 1; i <= n; i++) {
      for (register int o = 0; o <= 2002; o++) {
        dp[i][o + a[i]] = min(dp[i][o + a[i]], max(dp[i - 1][o], o + a[i]));
        dp[i][max(o - a[i], 0)] =
            min(dp[i][max(o - a[i], 0)], dp[i - 1][o] + max(a[i] - o, 0));
      }
    }
    int ans = 1e9;
    for (register int i = 0; i <= 2002; i++) {
      ans = min(ans, dp[n][i]);
    }
    print(ans);
  }
  return 0;
}
