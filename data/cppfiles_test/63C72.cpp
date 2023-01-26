#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> mn(n), tot(n), dp(1 << n, -1e9);
  vector<unordered_map<int, int>> cnt(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int cur = 0;
    for (auto c : s) {
      cur += (c == '(' ? 1 : -1);
      if (cur <= mn[i]) {
        mn[i] = cur;
        cnt[i][cur]++;
      }
      tot[i] = cur;
    }
  }
  dp[0] = 0;
  int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (mask >> i & 1) sum += tot[i];
    }
    for (int i = 0; i < n; i++) {
      if (!(mask >> i & 1)) {
        ans = max(ans, dp[mask] + cnt[i][-sum]);
        if (sum + mn[i] >= 0)
          dp[mask | (1 << i)] =
              max(dp[mask | (1 << i)], dp[mask] + cnt[i][-sum]);
      }
    }
  }
  cout << ans << endl;
}
