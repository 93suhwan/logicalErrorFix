#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e3 + 1;
int a[N], dp[N][N], nxt[N], prv[N], lst[N];
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(lst, -1, n * sizeof *lst);
    memset(prv, -1, n * sizeof *prv);
    memset(nxt, 127, n * sizeof *nxt);
    for (int i = 0; i < n; ++i) {
      cin >> a[i], --a[i];
      if (lst[a[i]] != -1) {
        prv[i] = lst[a[i]];
        nxt[lst[a[i]]] = i;
      }
      lst[a[i]] = i;
    }
    for (int le = 2; le <= n; ++le)
      for (int i = 0; i < n; ++i) {
        int j = i + le - 1;
        dp[i][j] = min(dp[i + 1][j] + 1 - (a[i] == a[i + 1] || a[i] == a[j]),
                       dp[i][j - 1] + 1 - (a[i] == a[j] || a[j - 1] == a[j]));
        if (nxt[i] <= j) {
          dp[i][j] = min(dp[i][j], dp[i + 1][nxt[i] - 1] + dp[nxt[i]][j] + 1);
        }
        if (prv[j] >= i) {
          dp[i][j] = min(dp[i][j], dp[i][prv[j]] + dp[prv[j] + 1][j - 1] + 1);
        }
      }
    cout << dp[0][n - 1] << '\n';
  }
  return 0;
}
