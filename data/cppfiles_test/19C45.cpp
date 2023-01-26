#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
int a[MAXN];
int dp[MAXN][2005];
bool check(int n, int len) {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= len; ++j) {
      if (i == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= len; ++j) {
      if (dp[i - 1][j]) {
        if (j + a[i] <= len) dp[i][j + a[i]] = 1;
        if (j - a[i] >= 0) dp[i][j - a[i]] = 1;
      }
    }
  }
  for (int j = 0; j <= len; ++j)
    if (dp[n][j]) return true;
  return false;
}
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = 0, r = 2000;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (check(n, mid))
        r = mid;
      else
        l = mid + 1;
    }
    cout << r << endl;
  }
  return 0;
}
