#include <bits/stdc++.h>
using namespace std;
const int N = 32;
int timer, cc1, cc;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int dp[1000005], vis[1000005], a[1000005];
int dfs(int cur, int k, int n) {
  int z, l;
  if (dp[cur] != -1) return dp[cur];
  if (vis[cur] > 0) {
    cc++;
    return -1;
  } else {
    vis[cur]++;
    if (a[cur] == 0)
      dp[cur] = 0;
    else {
      z = cur - k;
      z += n;
      z %= n;
      l = dfs(z, k, n);
      dp[cur] = l + 1;
    }
    cc1 = max(cc1, dp[cur]);
    return dp[cur];
  }
}
int main() {
  boost();
  int i, t, q, l, r, ans, mid, c = 0, j, z, tc, n, k;
  int h, m, u, mm, w, x, y, l1, r1, d = 0, mask, v, mx;
  long double f, f1;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cc = 0;
    cc1 = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      dp[i] = -1;
      vis[i] = 0;
    }
    for (i = 0; i < n; i++) {
      if (!vis[i]) {
        dp[i] = dfs(i, k, n);
        if (cc > 0) break;
      }
    }
    if (cc > 0) cc1 = -1;
    cout << cc1 << '\n';
  }
  return 0;
}
