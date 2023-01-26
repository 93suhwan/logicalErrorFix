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
int n;
char s[25][400010], l[25], rest[25][400010];
vector<int> v[25][400010];
int dp[(1 << 20) + 10][2], g[(1 << 20) + 10];
signed main() {
  n = read();
  for (int i = (1); i <= (n); i++) cin >> s[i];
  for (int i = (1); i <= (n); i++) {
    l[i] = strlen(s[i]);
    int su = 0;
    for (int j = (1); j <= (l[i]); j++) {
      if (s[i][j - 1] == ')')
        su++;
      else
        su--;
      rest[i][j] = su;
      if (su >= 0) v[i][su].push_back(j);
    }
  }
  int xx = (1 << n) - 1;
  for (int i = (1); i <= (xx); i++) dp[i][0] = dp[i][1] = -1e8;
  dp[0][0] = 0;
  dp[0][1] = 0;
  g[0] = 0;
  for (int mask = (1); mask <= (xx); mask++) {
    for (int i = (1); i <= (n); i++) {
      if (mask & (1 << (i - 1))) {
        int S1 = mask ^ (1 << (i - 1));
        if (g[S1] >= 0) {
          int x;
          if (v[i][g[S1] + 1].size() == 0)
            x = l[i] + 1;
          else
            x = v[i][g[S1] + 1][0];
          int y = lower_bound(v[i][g[S1]].begin(), v[i][g[S1]].end(), x) -
                  v[i][g[S1]].begin();
          if (x == l[i] + 1) {
            dp[mask][1] = max(dp[mask][1], dp[S1][1] + y);
          }
          dp[mask][0] = max(dp[mask][0], dp[S1][1] + y);
          dp[mask][0] = max(dp[mask][0], dp[S1][0]);
        } else {
          dp[mask][0] = max(dp[mask][0], dp[S1][0]);
        }
        g[mask] = g[S1] - rest[i][l[i]];
      }
    }
  }
  printf("%d\n", max(dp[xx][0], dp[xx][1]));
  return 0;
}
