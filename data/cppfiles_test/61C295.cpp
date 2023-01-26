#include <bits/stdc++.h>
using namespace std;
const int N = 200;
const int bes = 1e9;
char x[N];
int dp[N][2];
int p[N][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        if (j == 0 && x[i - 1] == 'R') {
          dp[i][j] = bes;
          continue;
        }
        if (j == 1 && x[i - 1] == 'B') {
          dp[i][j] = bes;
          continue;
        }
        if (dp[i - 1][j] + 1 < dp[i - 1][1 - j]) {
          p[i][j] = j;
          dp[i][j] = dp[i - 1][j] + 1;
        } else {
          p[i][j] = 1 - j;
          dp[i][j] = dp[i - 1][1 - j];
        }
      }
    }
    int fl;
    if (dp[n][0] < dp[n][1])
      fl = 0;
    else
      fl = 1;
    int now = n;
    vector<char> ans;
    while (now > 0) {
      if (fl)
        ans.push_back('R');
      else
        ans.push_back('B');
      fl = p[now][fl];
      now--;
    }
    reverse(ans.begin(), ans.end());
    for (char i : ans) cout << i;
    cout << '\n';
  }
}
