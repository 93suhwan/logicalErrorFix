#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<char> Exp(n);
    for (int i = 0; i < n; ++i) {
      cin >> Exp[i];
    }
    vector<vector<char>> dp(n, vector<char>(n, '.'));
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (Exp[i] == '1') {
        for (int j = 0; j < n; j++) {
          if (i == j)
            dp[i][j] = 'X';
          else {
            dp[i][j] = '=';
            dp[j][i] = '=';
          }
        }
      }
      dp[i][i] = 'X';
    }
    for (int i = 0; i < n; i++) {
      if (Exp[i] != '1') {
        bool change = false;
        for (int j = 0; j < n; j++) {
          if (dp[i][j] == '.' || dp[i][j] == '+') {
            dp[i][j] = '+';
            dp[j][i] = '-';
            change = true;
            break;
          }
        }
        if (change == false) {
          flag = false;
        }
      }
    }
    if (flag == false)
      cout << "NO" << '\n';
    else {
      cout << "YES" << '\n';
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << dp[i][j];
        }
        cout << '\n';
      }
    }
  }
  return 0;
}
