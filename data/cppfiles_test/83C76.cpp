#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, mod = 1e9 + 7;
int t, p[N][N], dp[N];
int main() {
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string second;
    cin >> second;
    second = '$' + second + '$';
    for (int i = n; i >= 1; i--) {
      for (int j = n; j >= 1; j--) {
        if (j == i)
          p[i][j] = n - i + 1;
        else if (second[j] == second[i])
          p[i][j] = 1 + p[i + 1][j + 1];
        else
          p[i][j] = 0;
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = n - i + 1;
      for (int j = 1; j < i; j++) {
        if (second[i + p[i][j]] > second[j + p[i][j]])
          dp[i] = max(dp[i], dp[j] + n - i + 1 - p[i][j]);
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
}
