#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> mas(n);
  for (int i = 0; i < n; ++i) {
    cin >> mas[i];
  }
  vector<unordered_map<int, int>> dp(2);
  int ans = 0;
  bool cur = 0;
  for (int i = n - 1; i >= 1; i--) {
    dp[cur][mas[i]] += 1;
    for (auto j : dp[cur]) {
      dp[!cur][mas[i - 1] / ((mas[i - 1] - 1) / j.first + 1)] += j.second;
      ans += j.second * ((mas[i - 1] - 1) / j.first) * i;
      ans %= 998244353;
    }
    dp[cur].clear();
    cur = !cur;
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
