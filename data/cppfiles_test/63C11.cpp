#include <bits/stdc++.h>
using namespace std;
const int MXB = 400000 + 10;
const int mn = 1000000000;
signed main() {
  int n;
  cin >> n;
  vector<vector<vector<int>>> poss(n, vector<vector<int>>(MXB * 2));
  int ans = -mn;
  vector<int> bas(n);
  vector<int> dp((1 << (n + 1)), -mn);
  for (int i = 0; i < n; i++) {
    int ba = 0;
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(') {
        ba++;
      } else if (s[j] == ')') {
        ba--;
      }
      poss[i][MXB + ba].push_back(j);
    }
    bas[i] = ba;
  }
  dp[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (dp[i] != -mn) {
      for (int j = 0; j < n; j++) {
        if (!((i >> j) & 1)) {
          int tmp = 0;
          for (int ii = 0; ii < n; ii++) {
            if ((i >> ii) & 1) {
              tmp -= bas[ii];
            }
          }
          if (tmp <= 0) {
            if (poss[j][MXB + tmp - 1].size()) {
              int l = -1;
              int r = poss[j][MXB + tmp].size();
              int el = poss[j][MXB + tmp - 1][0];
              while (l + 1 != r) {
                int mid = (l + r) / 2;
                if (poss[j][MXB + tmp][mid] < el) {
                  l = mid;
                } else {
                  r = mid;
                }
              }
              ans = max(ans, dp[i] + l + 1);
            } else {
              dp[i + (1 << j)] =
                  max((long long)dp[i + (1 << j)],
                      (long long)(dp[i] + poss[j][MXB + tmp].size()));
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
}
