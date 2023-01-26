#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005][2];
int mt[1005][1005];
int n, m;
int ans = 0;
void solve(int x, int y) {
  if (x > n || y > m) return;
  ans = ans - dp[x][y][0] - dp[x][y][1];
  if (mt[x][y] == 1) {
    dp[x][y][0] = 0;
    dp[x][y][1] = 0;
  } else {
    dp[x][y][0] = dp[x - 1][y][1] + 1;
    dp[x][y][1] = dp[x][y - 1][0] + 1;
  }
  ans += (dp[x][y][0] + dp[x][y][1]);
}
signed main() {
  int q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      solve(i, j);
    }
  }
  ans -= n * m;
  while (q--) {
    int a, b;
    cin >> a >> b;
    mt[a][b] = mt[a][b] ^ 1;
    if (mt[a][b] == 1)
      ans++;
    else
      ans--;
    solve(a, b);
    for (int i = a + 1, j = b + 1; i <= m + 1 && j <= n + 1; i++, j++) {
      solve(i - 1, j);
      solve(i, j - 1);
      solve(i, j);
    }
    cout << ans << endl;
  }
}
