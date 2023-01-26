#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 2;
int arr[maxn], dp[maxn][maxn], n, k;
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0;
    }
    dp[i][0] = dp[i - 1][0] + (arr[i] == i ? 1 : 0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] =
          max(dp[i - 1][j - 1], dp[i - 1][j] + (arr[i] == (i - j) ? 1 : 0));
    }
  }
  for (int i = 0; i <= n; i++) {
    if (dp[n][i] >= k) {
      cout << i;
      return;
    }
  }
  cout << -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
