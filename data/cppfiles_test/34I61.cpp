#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  long long n;
  cin >> n;
  vector<long long> a;
  set<long long> st;
  for (long long i = 0; i < n; ++i) {
    long long o;
    cin >> o;
    if (st.count(o)) continue;
    a.push_back(o);
    st.insert(o);
  }
  n = a.size();
  long long mx = 8191;
  bool dp[n + 1][mx + 1];
  for (long long j = 0; j < n + 1; ++j) {
    for (long long i = 0; i < mx + 1; ++i) {
      dp[j][i] = false;
    }
  }
  dp[0][0] = true;
  long long last[mx + 1];
  for (long long m = 0; m < mx + 1; ++m) {
    last[m] = inf;
  }
  last[0] = -inf;
  for (long long k = 1; k < n + 1; ++k) {
    for (long long i = 0; i < mx + 1; ++i) {
      long long need = i ^ a[k - 1];
      if (last[need] < a[k - 1]) {
        dp[k][i] = true;
      }
    }
    for (long long j = 0; j < mx + 1; ++j) {
      if (dp[k][j]) last[j] = min(last[j], a[k - 1]);
    }
  }
  set<long long> ans;
  for (long long k1 = 0; k1 <= n; ++k1) {
    for (long long l = 0; l < mx + 1; ++l) {
      if (dp[k1][l]) ans.insert(l);
    }
  }
  cout << ans.size() << "\n";
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << "\n";
}
