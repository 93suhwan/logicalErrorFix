#include <bits/stdc++.h>
using namespace std;
int a[100001];
int dp[100001];
int dp2[100001];
int pre[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++) {
    int n;
    cin >> n;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    dp[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
      dp[i] = max(a[i], dp[i + 1]);
    }
    int ans = 1;
    for (int k = 2; k <= ceil(sqrt(2 * n)); k++) {
      for (int i = n; i >= 1; i--) {
        if (k % 2 == 0) {
          dp2[i] = dp2[i + 1];
          if (i + k <= n && pre[i + k - 1] - pre[i - 1] < dp[i + k]) {
            dp2[i] = max(dp2[i], pre[i + k - 1] - pre[i - 1]);
          }
          if (i == 1 && dp2[i] != 0) {
            ans = k;
          }
        } else {
          dp[i] = dp[i + 1];
          if (i + k <= n && pre[i + k - 1] - pre[i - 1] < dp2[i + k]) {
            dp[i] = max(dp[i], pre[i + k - 1] - pre[i - 1]);
          }
          if (i == 1 && dp[i] != 0) {
            ans = k;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
