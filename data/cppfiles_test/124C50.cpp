#include <bits/stdc++.h>
using namespace std;
int n;
pair<long long, long long> dp[2021][2 * 2021];
string s, t;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s >> t;
    for (int i = (0); i <= (n - 1); i++)
      if (i & 1) {
        if (s[i] != '?') s[i] = '0' + '1' - s[i];
        if (t[i] != '?') t[i] = '0' + '1' - t[i];
      }
    for (int i = (0); i <= (n); i++)
      for (int j = (0); j <= (2 * n); j++) dp[i][j] = {0, 0};
    dp[0][n] = {0, 1};
    for (int i = (0); i <= (n - 1); i++)
      for (int j = (0); j <= (2 * n); j++)
        if (dp[i][j].second) {
          for (int a = (0); a <= (1); a++)
            if (s[i] - '0' == a || s[i] == '?')
              for (int b = (0); b <= (1); b++)
                if (t[i] - '0' == b || t[i] == '?')
                  (dp[i + 1][j + a - b].first +=
                   dp[i][j].first + abs(j + a - b - n) * dp[i][j].second) %=
                      1000000007,
                      (dp[i + 1][j + a - b].second += dp[i][j].second) %=
                      1000000007;
        }
    cout << dp[n][n].first << endl;
  }
  return 0;
}
