#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int maxnum = 2e5 + 1;
vector<vector<long long int>> dp;
void solve() {
  long long int l, r;
  cin >> l >> r;
  int n = r - l + 1;
  int mincnt = INT_MAX;
  long long int ans = 0;
  for (int i = 0; i < 32; i++) ans = max(ans, dp[r][i] - dp[l - 1][i]);
  cout << r - l + 1 - ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  dp = vector<vector<long long int>>(maxnum, vector<long long int>(32));
  for (int i = 1; i < maxnum; i++) {
    for (int j = 0; j < 32; j++) {
      dp[i][j] = dp[i - 1][j];
      if ((i & (1 << j))) dp[i][j]++;
    }
  }
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
