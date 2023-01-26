#include <bits/stdc++.h>
using namespace std;
int dp[4000001];
int s[8000001];
int main() {
  int n, m, i, j;
  cin >> n >> m;
  dp[n] = 1;
  s[n] = 1;
  for (i = n - 1; i >= 1; i--) {
    dp[i] = s[i + 1];
    for (j = 2; i * j <= n; j++)
      dp[i] = (1ll * dp[i] + s[i * j] - s[(i + 1) * j] + m) % m;
    s[i] = (s[i + 1] + dp[i]) % m;
  }
  cout << dp[1];
  return 0;
}
