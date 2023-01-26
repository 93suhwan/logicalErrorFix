#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1, 0);
  vector<long long> s(n + 2, 0);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] + a[i];
  }
  int mk = 0;
  for (int i = 1; i <= n; ++i) {
    if (i * (i + 1) / 2 > n) {
      break;
    }
    mk = i;
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(mk + 1, -1));
  dp[n][1] = a[n];
  for (int i = n - 1; i >= 1; --i) {
    if (i < n) {
      dp[i][1] = max(dp[i + 1][1], (long long)a[i]);
    }
    for (int j = 2; j <= mk; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (i + j - 1 <= n) {
        long long x = s[i + j - 1] - s[i - 1];
        if (i + j <= n && dp[i + j][j - 1] > x) {
          dp[i][j] = max(dp[i][j], x);
        }
      }
    }
  }
  for (int i = mk; i >= 1; --i) {
    if (dp[1][i] != -1) {
      cout << i << endl;
      return;
    }
  }
}
int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int kk = 0; kk < t; ++kk) {
    solve();
  }
  return 0;
}
