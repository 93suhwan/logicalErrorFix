#include <bits/stdc++.h>
using namespace std;
int dp[3000][3000];
int a[30001];
vector<int> could[30001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= int(n); i++) cin >> a[i];
    for (int i = 1; i <= int(n); i++) could[i].clear();
    for (int i = 1; i <= int(n); i++) {
      for (int j = i; j <= n; j++) {
        if (a[j] == i) {
          could[i].push_back(j - i);
        }
      }
    }
    for (int i = 0; i < int(n + 1); i++)
      for (int j = 0; j < int(n + 1); j++) dp[i][j] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        int cur = dp[i][j];
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
        int val = 0;
        if (a[i + 1] == i - j + 1) val = 1;
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + val);
      }
    }
    int ans = -1;
    for (int i = 0; i <= n; i++)
      if (dp[n][i] >= k) {
        ans = i;
        break;
      }
    cout << ans << '\n';
  }
  return 0;
}
