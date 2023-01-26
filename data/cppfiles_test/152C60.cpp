#include <bits/stdc++.h>
using namespace std;
vector<int> a[2];
vector<int> dp[2];
vector<int> trace[2];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    a[0].resize(n + 1), a[1].resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[0][i];
      a[1][i] = -a[0][i];
    }
    dp[0].resize(n + 1), dp[1].resize(n + 1);
    trace[0].resize(n + 1), trace[1].resize(n + 1);
    a[0][0] = a[1][0] = -n - 1;
    dp[0][0] = dp[1][0] = -n - 1;
    for (int i = 1; i <= n; ++i) {
      dp[0][i] = dp[1][i] = n + 1;
      for (int j = 0; j < 2; ++j) {
        if (dp[j][i - 1] > n) continue;
        for (int k = 0; k < 2; ++k) {
          if (dp[j][i - 1] < a[k][i] && a[j][i - 1] < dp[k][i]) {
            dp[k][i] = a[j][i - 1];
            trace[k][i] = j;
          }
          if (a[j][i - 1] < a[k][i] && dp[j][i - 1] < dp[k][i]) {
            dp[k][i] = dp[j][i - 1];
            trace[k][i] = j;
          }
        }
      }
    }
    if (dp[0][n] > n && dp[1][n] > n)
      cout << "NO\n";
    else {
      cout << "YES\n";
      int p = trace[0][n] > n;
      for (int i = n; i > 0; --i) {
        a[0][i] = a[p][i];
        p = trace[p][i];
      }
      for (int i = 1; i <= n; ++i) cout << a[0][i] << " \n"[i == n];
    }
  }
  return 0;
}
