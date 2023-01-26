#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int dp[1005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) cin >> a[i];
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 511; j++) {
      if (dp[j] < a[i]) dp[a[i] ^ j] = min(dp[a[i] ^ j], a[i]);
    }
  }
  int sum = 0;
  for (int i = 0; i <= 511; i++)
    if (dp[i] <= 511) sum++;
  cout << sum << "\n";
  for (int i = 0; i <= 511; i++)
    if (dp[i] <= 511) cout << i << " ";
  cout << "\n";
  return 0;
}
