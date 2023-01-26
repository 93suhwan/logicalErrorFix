#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int n, m;
long long dp[N][N];
int a[N];
vector<int> pos[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    memset(dp[i], 0, sizeof(long long) * (n + 1));
    pos[i].clear();
  }
  for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]].push_back(i);
  for (int len = 2; len <= n; len++) {
    for (int l = 1, r = l + len - 1; r <= n; l++, r = l + len - 1) {
      dp[l][r] = max(dp[l][r], max(dp[l + 1][r], dp[l][r - 1]));
      if (a[l] == a[r]) dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 1);
      for (int pl : pos[a[l]]) {
        int pr = pl + 1;
        if (pl > l && pr < r) dp[l][r] = max(dp[l][r], dp[l][pl] + dp[pr][r]);
      }
    }
  }
  cout << n - 1 - dp[1][n] << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ttt = 1;
  cin >> ttt;
  for (int i = 1; i <= ttt; i++) solve();
  return 0;
}
