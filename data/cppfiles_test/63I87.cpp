#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
inline long long llread() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
long long n;
char s[25][400010], l[25], rest[25];
vector<long long> v[25][400010];
long long dp[(1 << 20) + 10][2], g[(1 << 20) + 10];
signed main() {
  n = llread();
  for (long long i = (1); i <= (n); i++) scanf("%s", s[i] + 1);
  for (long long i = (1); i <= (n); i++) l[i] = strlen(s[i] + 1);
  for (long long i = (1); i <= (n); i++) {
    long long top = 0;
    for (long long j = (1); j <= (l[i]); j++) {
      if (s[i][j] == ')')
        top++;
      else
        top--;
      if (top >= 0) v[i][top].push_back(j);
    }
    rest[i] = top;
  }
  for (long long i = (1); i <= ((1 << n) - 1); i++) dp[i][0] = dp[i][1] = -1e18;
  dp[0][0] = dp[0][1] = g[0] = 0;
  for (long long mask = (1); mask <= ((1 << n) - 1); mask++) {
    for (long long i = (1); i <= (n); i++) {
      if (mask & (1 << (i - 1))) {
        long long S = mask ^ (1 << (i - 1));
        if (g[S] >= 0) {
          long long x;
          if (v[i][g[S] + 1].size() == 0)
            x = l[i] + 1;
          else
            x = v[i][g[S] + 1][0];
          long long y = lower_bound(v[i][g[S]].begin(), v[i][g[S]].end(), x) -
                        v[i][g[S]].begin();
          if (x == l[i] + 1) {
            if ((dp[mask][1]) < (dp[S][1] + y)) {
              (dp[mask][1]) = (dp[S][1] + y);
            };
          }
          if ((dp[mask][0]) < (dp[S][1] + y)) {
            (dp[mask][0]) = (dp[S][1] + y);
          };
        }
        if ((dp[mask][0]) < (dp[S][0])) {
          (dp[mask][0]) = (dp[S][0]);
        };
        g[mask] = g[S] - rest[i];
      }
    }
  }
  printf("%lld\n", max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]));
  return 0;
}
