#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e3 + 1;
uint16_t a[N], nxt[N], lst[N];
uint16_t dp[N][N];
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(lst, -1, n * sizeof *lst);
    memset(nxt, 127, n * sizeof *nxt);
    for (int i = 0; i < n; ++i) {
      cin >> a[i], --a[i];
      if (lst[a[i]] != (uint16_t)-1) {
        nxt[lst[a[i]]] = i;
      }
      lst[a[i]] = i;
    }
    for (int i = n - 1; i > -1; --i) {
      for (int j = i + 1; j < n; ++j) {
        int t = dp[i + 1][j] - 1;
        for (int z = nxt[i]; z <= j; z = nxt[z]) {
          t = max(t, dp[i + 1][z - 1] + dp[z][j]);
        }
        dp[i][j] = t + 1;
      }
    }
    cout << n - dp[0][n - 1] - 1 << '\n';
  }
  return 0;
}
