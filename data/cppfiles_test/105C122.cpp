#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e3;
uint16_t a[N], nxt[N], lst[N];
uint16_t dp[N][N];
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
    memset(nxt, 127, n * sizeof *nxt);
    for (int i = 0; i < n; ++i) {
      if (lst[a[i]] != (uint16_t)-1) {
        nxt[lst[a[i]]] = i;
      }
      lst[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j > -1; --j) {
        int t = dp[i][j + 1] - 1;
        for (int z = nxt[j]; z <= i; z = nxt[z]) {
          t = max(t, dp[i][z] + dp[z - 1][j + 1]);
        }
        dp[i][j] = t + 1;
      }
    }
    cout << n - dp[n - 1][0] - 1 << '\n';
  }
}
