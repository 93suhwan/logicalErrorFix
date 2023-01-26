#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 2002;
int T, n, K, a[N], dp[N][N], near[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> n >> K;
    for (int i = (n); i >= (1); --i) cin >> a[i];
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (n); ++j) dp[i][j] = -1;
    for (int i = (1); i <= (n); ++i) {
      if (a[n] == i)
        dp[n][i] = 1, near[n][i] = n;
      else if (i == 1)
        dp[n][i] = 0, near[n][i] = -1;
      else {
        dp[n][i] = near[n][i] = -1;
      }
      dp[n + 1][i] = -1;
    }
    for (int i = (n - 1); i >= (1); --i) {
      for (int j = (1); j <= (n); ++j) {
        if (a[i] == j)
          near[i][j] = i;
        else
          near[i][j] = near[i + 1][j];
        if (near[i][j] != -1) {
          if (j == 1)
            dp[i][j] = 1;
          else
            dp[i][j] = 1 + dp[near[i][j] + 1][j - 1];
        }
        dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]);
      }
    }
    int ans = -1;
    for (int i = (n); i >= (1); --i)
      if (dp[1][i] >= K) {
        ans = n - i;
        break;
      }
    cout << ans << '\n';
  }
  return 0;
}
