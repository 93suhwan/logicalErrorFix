#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int ans[1005][1005];
vector<int> cs[1005];
bool vis[1005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  int mx = 0;
  for (int i = 1; i < n; i++) {
    if (((i - 1) / (k - 1)) % 2)
      ans[i][i + 1] = 2;
    else
      ans[i][i + 1] = 1;
    mx = max(ans[i][i + 1], mx);
    for (int j = i + 2; j <= n; j++) {
      int c = ((j - 1) / (k - 1)) % 2;
      if (c)
        c = 1;
      else
        c = 2;
      if (i % k == 0 && c == ans[i - 1][i]) {
        c = 3;
        mx = 3;
      }
      ans[i][j] = c;
    }
  }
  cout << mx << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) cout << ans[i][j] << ' ';
  }
  return 0;
}
