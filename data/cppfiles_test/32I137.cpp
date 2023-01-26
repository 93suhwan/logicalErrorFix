#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n + 1);
  for (long long i = 1; i <= n; ++i) {
    cin >> v[n - i + 1];
  }
  long long k = sqrt(2 * n) + 12;
  vector<vector<int32_t>> dp(k, vector<int32_t>(n + 1));
  for (long long i = 1; i <= n; ++i) {
    dp[i][1] = true;
  }
  long long ans = 1;
  vector<long long> pf(n + 1);
  for (long long i = 1; i <= n; ++i) {
    pf[i] = pf[i - 1] + v[i];
  }
  for (long long j = 2; j < k; ++j) {
    set<pair<long long, long long>> st;
    for (long long i = j - 1; i <= n; ++i) {
      long long sum = pf[i] - pf[i - (j - 1)];
      if (dp[j - 1][i]) {
        while (!st.empty() && st.begin()->first <= sum) {
          st.erase(st.begin());
        }
        st.insert(make_pair(sum, i));
      }
      if (i + j <= n) {
        i += j;
        sum = pf[i] - pf[i - j];
        auto it = st.lower_bound(make_pair(sum, 2 * n));
        if (it != st.end()) {
          dp[j][i] = max(dp[j - 1][it->second], dp[j][i]);
          if (dp[j][i]) ans = j;
        }
        i -= j;
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
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
