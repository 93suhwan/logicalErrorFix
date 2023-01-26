#include <bits/stdc++.h>
using namespace std;
void main2() {
  string s, t;
  cin >> s;
  cin >> t;
  long long int n = s.length(), m = t.length();
  vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
  dp[0][0] = true;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= min(m, n); j++) {
      if (s[i - 1] == t[j - 1]) {
        if (j == 1)
          dp[i][j] = true;
        else if (dp[i - 1][j - 1] == true)
          dp[i][j] = true;
      }
    }
  }
  if (m <= n) {
    for (long long int i = 1; i <= n; i++) {
      if (dp[i][m] == true) {
        cout << "YES\n";
        return;
      }
    }
  }
  long long int temp = m - 1;
  for (long long int i = 0; i < n; i++) {
    temp = m - 1;
    for (long long int j = i; j < n; j++) {
      if (t[temp] != s[j]) break;
      if (temp == 0) {
        cout << "YES\n";
        return;
      }
      if (j + 1 < n && dp[j + 2][temp] == true) {
        cout << "YES\n";
        return;
      }
      temp--;
    }
  }
  cout << "NO\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    main2();
  }
  return 0;
}
