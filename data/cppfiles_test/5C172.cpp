#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1 >> s2;
    int brojac = 0;
    int dp[n][2][2];
    int dp1[n];
    int dp2[n];
    for (int i = 0; i < n; i++) {
      dp1[i] = 0;
      dp2[i] = 0;
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          dp[i][j][k] = 0;
        }
      }
    }
    int ans = 0;
    if (s1[0] == '0' and s2[0] == '1') {
      ans++;
      dp1[0]++;
      dp2[0]++;
    }
    for (int i = 1; i < n; i++) {
      dp2[i] = dp2[i - 1];
      dp[i][0][0] = dp2[i - 1];
      if (s1[i] == '0' and s2[i] == '1') {
        dp1[i] = 1 + dp2[i - 1];
      }
      if (s1[i] == '1' and s2[i - 1] == '1') {
        if (s1[i - 1] == '1') {
          dp[i][1][0] = 1 + max(dp[i - 1][0][0], dp[i - 1][1][0]);
        } else {
          dp[i][1][0] = 1 + dp[i - 1][0][0];
        }
      }
      if (s2[i] == '1' and s1[i - 1] == '1') {
        if (s2[i - 1] == '1') {
          dp[i][0][1] = 1 + max(dp[i - 1][0][0], dp[i - 1][0][1]);
        } else {
          dp[i][0][1] = 1 + dp[i - 1][0][0];
        }
      }
      if (s1[i - 1] == '1' and s2[i - 1] == '1' and s1[i] == '1' and
          s2[i] == '1') {
        dp[i][1][1] = 2 + dp[i - 1][0][0];
      }
      dp2[i] = max(dp2[i], dp1[i]);
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          dp2[i] = max(dp2[i], dp[i][j][k]);
        }
      }
    }
    cout << dp2[n - 1] << endl;
  }
}
