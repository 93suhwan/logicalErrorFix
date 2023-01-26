#include <bits/stdc++.h>
using namespace std;
const int mxn = 20, m = 400001;
int n;
int a[mxn], first[1 << mxn], dp[1 << mxn];
vector<int> v[mxn][m << 1];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string second;
    cin >> second;
    for (int j = 0; j < second.size(); j++) {
      a[i] += 2 * (second[j] == '(') - 1, v[i][m + a[i]].push_back(j);
    }
  }
  int ret = 0;
  memset(dp, 0xcf, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i < (1 << n); i++)
    for (int j = 0; j < n; j++)
      if ((i >> j) & 1) {
        first[i] += a[j];
        int x = i ^ (1 << j), y = m - first[x];
        if (v[j][y - 1].empty()) {
          ret = max(ret, dp[i] = max(dp[i], (int)v[j][y].size() + dp[x]));
        } else {
          ret = max(ret, int(lower_bound(v[j][y].begin(), v[j][y].end(),
                                         v[j][y - 1][0]) -
                             v[j][y].begin()) +
                             dp[x]);
        }
      }
  cout << ret << '\n';
  return 0;
}
