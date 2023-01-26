#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<long long int, long long int> > ans;
  for (int i = 0; i <= n - 1; i++) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (auto &i : a) cin >> i;
    ;
    int mx = INT_MIN;
    for (int j = 0; j <= k - 1; j++) {
      int req = j + a[i] + 1;
      if (req > mx) {
        mx = req;
      }
    }
    ans.push_back({mx, mx + k});
  }
  sort(ans.begin(), ans.end());
  long long int diff = INT_MAX;
  int s = ans.size();
  vector<long long int> dp(s, 0);
  for (int i = s - 2; i >= 0; i--) {
    dp[i] = max(dp[i + 1], ans[i + 1].first - ans[i].second + 1);
  }
  for (int i = 0; i <= s - 1; i++) {
    diff = min(diff, ans[i].first + dp[i]);
  }
  cout << diff << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
