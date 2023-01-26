#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n + 1);
  for (long long i = 1; i <= n; ++i) {
    cin >> v[n - i + 1];
  }
  for (long long i = 1; i <= n; ++i) {
    v[i] *= -1;
  }
  long long k = sqrt(4 * n) + 12;
  vector<vector<long long>> dp(n + 1, vector<long long>(k));
  for (long long i = 1; i <= n; ++i) {
    dp[i][1] = 1;
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
      while (!st.empty() && prev(st.end())->first >= sum) {
        st.erase(prev(st.end()));
      }
      st.insert(make_pair(sum, i));
      if (i + j <= n) {
        i += j;
        sum = pf[i] - pf[i - j];
        auto it = st.upper_bound(make_pair(sum, -1));
        if (it != st.begin()) {
          --it;
          dp[i][j] = max(dp[it->second][j - 1], dp[i][j]);
        }
        i -= j;
      }
      if (dp[i][j]) {
        ans = j;
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
