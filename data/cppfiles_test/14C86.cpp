#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    bool exist0 = false;
    int cont_fix = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) exist0 = true;
      if (a[i] == i) cont_fix++;
      dp[i][0] = exist0;
      dp[i][i] = cont_fix;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < i; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + (a[i] == j));
      }
    }
    int max_ele = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (dp[n - 1][i] >= k) {
        max_ele = n - (i + 1);
        break;
      }
    }
    cout << max_ele << endl;
  }
  return 0;
}
