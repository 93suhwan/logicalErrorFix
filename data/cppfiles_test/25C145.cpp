#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    int dp[s.size() + 1][t.size() + 1];
    for (int i = 0; i < s.size() + 1; i++)
      for (int j = 0; j < t.size() + 1; j++)
        if (i == 0 or j == 0) dp[i][j] = 0;
    string r = "";
    bool ans = false;
    for (int i = s.size() - 1; i >= 0; i--) r += s[i];
    for (int i = 1; i < s.size() + 1; i++) {
      for (int j = 1; j < t.size() + 1; j++) {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = 0;
        if (dp[i][j] == t.size()) {
          ans = true;
          break;
        }
        if (dp[i][j] > 0) {
          if (t.size() - dp[i][j] <= i - 1) {
            if (r.substr((s.size() - i + 1), (t.size() - dp[i][j])) ==
                t.substr(j, (t.size() - dp[i][j]))) {
              ans = true;
              break;
            }
          }
        }
      }
      if (ans) break;
    }
    if (ans)
      cout << "yes" << endl;
    else
      cout << "No" << endl;
  }
}
