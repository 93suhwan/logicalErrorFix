#include <bits/stdc++.h>
using namespace std;
const int M = 9000;
int n;
vector<int> vi[M];
int dp[M], f[M];
int main() {
  cin >> n;
  for (int i = 1, x; i <= n; ++i) cin >> x, vi[x].push_back(i);
  memset(dp, 0x3f, sizeof(dp));
  memset(f, 0x3f, sizeof(f));
  dp[0] = 0;
  for (int i = 0; i <= 5000; ++i)
    if (((int)vi[i].size())) {
      for (int j = 0; j < 8192; ++j) {
        if (dp[j] < vi[i].back() && dp[j ^ i] > dp[j])
          f[j ^ i] = *lower_bound(vi[i].begin(), vi[i].end(), dp[j]);
      }
      for (int j = 0; j < 8192; ++j) {
        dp[j] = min(dp[j], f[j]), f[j] = 1e9;
      }
    }
  int ans = 0;
  for (int i = 0; i < 8192; ++i)
    if (dp[i] <= n) ++ans;
  cout << ans << endl;
  for (int i = 0; i < 8192; ++i)
    if (dp[i] <= n) cout << i << " ";
  cout << endl;
  return 0;
}
