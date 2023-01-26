#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
const int MAXN = 1e6 + 1;
int dp[2][MAXN], p[2][MAXN], par[2][MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> p[0][i];
      p[1][i] = -p[0][i];
    }
    p[0][0] = p[1][0] = -1e9;
    dp[0][0] = dp[1][0] = -1e9;
    for (int i = 1; i <= n; i++) {
      dp[0][i] = dp[1][i] = 1e9;
      for (int j = 0; j < 2; j++) {
        if (dp[j][i - 1] == 1e9) continue;
        for (int k = 0; k < 2; k++) {
          if (dp[j][i - 1] < p[k][i] && p[j][i - 1] < dp[k][i]) {
            dp[k][i] = p[j][i - 1];
            par[k][i] = j;
          }
          if (p[j][i - 1] < p[k][i] && dp[j][i - 1] < dp[k][i]) {
            dp[k][i] = dp[j][i - 1];
            par[k][i] = j;
          }
        }
      }
    }
    if (dp[0][n] == 1e9 && dp[1][n] == 1e9)
      cout << "NO" << '\n';
    else {
      int c = dp[0][n] == 1e9;
      vector<int> ans;
      for (int i = n; i >= 1; i--) {
        ans.push_back(p[c][i]);
        c = par[c][i];
      }
      cout << "YES" << '\n';
      reverse(ans.begin(), ans.end());
      for (int x : ans) cout << x << " ";
      cout << '\n';
    }
  }
}
