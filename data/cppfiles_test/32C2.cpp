#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> v[n - i + 1];
  }
  int k = sqrt(2 * n) + 12;
  vector<vector<int>> dp(k, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    dp[1][i] = true;
  }
  int ans = 1;
  vector<long long> pf(n + 1);
  for (int i = 1; i <= n; ++i) {
    pf[i] = pf[i - 1] + v[i];
  }
  for (int j = 2; j < k; ++j) {
    deque<pair<long long, int>> st;
    for (int i = j - 1; i <= n; ++i) {
      long long sum = pf[i] - pf[i - (j - 1)];
      if (dp[j - 1][i]) {
        while (!st.empty() && st.front().first <= sum) {
          st.pop_front();
        }
        st.push_front(make_pair(sum, i));
      }
      if (i + j <= n) {
        if (!st.empty()) {
          i += j;
          sum = pf[i] - pf[i - j];
          if (st.back().first > sum) {
            dp[j][i] = dp[j - 1][st.back().second];
            if (dp[j][i]) ans = j;
          }
          i -= j;
        }
      } else {
        break;
      }
    }
    if (ans != j) {
      break;
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
