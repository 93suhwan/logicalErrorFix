#include <bits/stdc++.h>
using namespace std;
const int N = 3001;
int a[N], id[N], dp[N][N];
vector<int> pos[N];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) pos[i].clear();
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      id[i] = pos[a[i]].size();
      pos[a[i]].push_back(i);
    }
    for (int i = n; i > 0; --i) {
      for (int j = i; j <= n; ++j) {
        if (i == j) {
          dp[i][j] = 1;
        } else if (a[i] == a[i + 1]) {
          dp[i][j] = dp[i + 1][j];
          continue;
        } else {
          dp[i][j] = dp[i + 1][j] + 1;
        }
        for (int p = id[i] + 1, k;
             p < pos[a[i]].size() && (k = pos[a[i]][p]) <= j; ++p) {
          dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
        }
      }
    }
    cout << dp[1][n] - 1 << endl;
  }
  return 0;
}
