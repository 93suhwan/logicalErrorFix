#include <bits/stdc++.h>
const int mod = 998244353;
const int maxn = 2e5 + 5;
const long long int INF = 2e5 + 5;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<char> > str(3, vector<char>(n + 1));
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> str[i][j];
      }
    }
    vector<vector<bool> > dp(4, vector<bool>(n + 4));
    dp[1][1] = true;
    if (str[2][1] == '0') dp[2][1] = true;
    for (int i = 2; i <= n; i++) {
      if (str[1][i] == '0') {
        dp[1][i] = (dp[1][i - 1] || dp[2][i - 1] || str[2][i] == '0');
      }
      if (str[2][i] == '0') {
        dp[2][i] = (dp[2][i - 1] || dp[1][i - 1] || str[1][i] == '0');
      }
    }
    if (dp[2][n])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
