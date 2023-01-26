#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;
void TestCase() {
  int n, k, ans = mod;
  cin >> n >> k;
  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + (a[i] == j + 1));
    }
  }
  for (int i = 0; i <= n; i++) {
    if (dp[n][i] >= k) ans = min(ans, n - i);
  }
  ans == mod ? cout << -1 : cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    TestCase();
    cout << "\n";
  }
  return 0;
}
