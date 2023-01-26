#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> bal(n);
  vector<int> mn(n);
  vector<unordered_map<int, int>> get(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    int sum = 0;
    int mnn = 0;
    for (int j = 0; j < s[i].size(); ++j) {
      if (s[i][j] == '(') {
        ++sum;
      } else {
        --sum;
      }
      mnn = min(mnn, sum);
      if (mnn >= sum) {
        get[i][sum] += 1;
      }
    }
    bal[i] = sum;
    mn[i] = mnn;
  }
  vector<vector<int>> v(n, vector<int>(1 << n));
  vector<int> sum(1 << n);
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int j = 0; j < n; ++j) {
      if ((mask >> j) & 1) {
        sum[mask] = sum[mask ^ (1 << j)] + bal[j];
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      int sz = sum[mask];
      if ((mask >> i) & 1) {
        sz -= bal[i];
        continue;
      }
      v[i][mask] = get[i][-sz];
    }
  }
  vector<vector<int>> dp(1 << n, vector<int>(2, -1e9));
  dp[0][0] = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int j = 0; j < n; ++j) {
      if ((mask >> j) & 1) {
        if (sum[mask ^ (1 << j)] + mn[j] >= 0) {
          dp[mask][0] =
              max(dp[mask][0], dp[mask ^ (1 << j)][0] + v[j][mask ^ (1 << j)]);
        } else {
          dp[mask][1] =
              max(dp[mask][1], dp[mask ^ (1 << j)][0] + v[j][mask ^ (1 << j)]);
        }
        dp[mask][1] = max(dp[mask][1], dp[mask ^ (1 << j)][1]);
      }
    }
  }
  cout << *max_element((dp[(1 << n) - 1]).begin(), (dp[(1 << n) - 1]).end());
}
