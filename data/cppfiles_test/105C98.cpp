#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e3 + 1;
int a[N], nxt[N], prv[N], lst[N];
int16_t dp[N][N];
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i], --a[i];
    }
    memset(lst, -1, n * sizeof *lst);
    n = unique(a, a + n) - a;
    memset(prv, -1, n * sizeof *prv);
    memset(nxt, 127, n * sizeof *nxt);
    for (int i = 0; i < n; ++i) {
      if (lst[a[i]] != -1) {
        prv[i] = lst[a[i]];
        nxt[lst[a[i]]] = i;
      }
      lst[a[i]] = i;
    }
    for (int i = n - 1; i > -1; --i)
      for (int j = i + 1; j < n; ++j) {
        auto t = dp[i + 1][j];
        for (int z = nxt[i]; z <= j; z = nxt[z]) {
          t = max(t, int16_t(dp[i + 1][z - 1] + dp[z][j] + 1));
        }
        dp[i][j] = t;
      }
    cout << n - dp[0][n - 1] - 1 << '\n';
  }
  return 0;
}
