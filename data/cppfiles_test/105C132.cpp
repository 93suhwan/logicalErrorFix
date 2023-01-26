#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e3;
uint16_t a[N], lst[N], nxt[N], cnxt[19], dp[N][N];
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i], --a[i];
    }
    memset(lst, 0, n * sizeof *lst);
    for (int i = 0; i < n; ++i) {
      ++lst[a[i]];
    }
    int w = -1, r = 0, purged = 0;
    while (r < n) {
      if (w >= 0 && a[w] == a[r]) {
        if (--lst[a[r++]] == 1) {
          --w;
          ++purged;
        }
      } else if (lst[a[r]] == 1) {
        ++r;
        ++purged;
      } else {
        a[++w] = a[r++];
      }
    }
    memset(lst, -1, n * sizeof *lst);
    n = w + 1;
    memset(nxt, 127, n * sizeof *nxt);
    for (int i = 0; i < n; ++i) {
      if (lst[a[i]] != (uint16_t)-1) {
        nxt[lst[a[i]]] = i;
      }
      lst[a[i]] = i;
    }
    for (int i = n - 1; i > -1; --i) {
      {
        auto* cnxte = cnxt;
        for (int z = nxt[i]; z < n; z = nxt[z]) {
          *cnxte++ = z;
        }
        cnxte = cnxt;
      }
      int cs = sizeof cnxt / sizeof *cnxt;
      for (int j = i + 1; j < n; ++j) {
        if (a[j] == a[i]) {
          --cs;
        }
        int t = dp[i + 1][j] - 1;
        const auto* z = cnxt;
        switch (cs) {
          [[likely]] case 0 : t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
          [[fallthrough]];
          case 1:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 2:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 3:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 4:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 5:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 6:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 7:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 8:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 9:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 10:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 11:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 12:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 13:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 14:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 15:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 16:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 17:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          case 18:
            t = max(t, dp[i + 1][*z - 1] + dp[*z][j]), ++z;
            [[fallthrough]];
          default:;
        }
        dp[i][j] = t + 1;
      }
    }
    cout << (n ? n - dp[0][n - 1] : 0) - 1 + purged << '\n';
  }
}
