#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    long long q;
    cin >> q;
    long long dp[q][3];
    for (long long j = 0; j < q; j++) {
      cin >> dp[j][0];
      if (dp[j][0] == 1) {
        cin >> dp[j][1];
        dp[j][2] = -1;
      } else {
        cin >> dp[j][1] >> dp[j][2];
      }
    }
    vector<long long> v(5 * 1e5 + 5);
    vector<long long> ans;
    for (long long i = 0; i < 5 * 1e5 + 5; i++) {
      v[i] = i;
    }
    for (long long i = q - 1; i >= 0; i--) {
      if (dp[i][0] == 1) {
        ans.push_back(v[dp[i][1]]);
      } else {
        v[dp[i][1]] = v[dp[i][2]];
      }
    }
    reverse(ans.begin(), ans.end());
    for (long long i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
  }
  return 0;
}
