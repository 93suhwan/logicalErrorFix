#include <bits/stdc++.h>
using namespace std;
int denom = 31607;
int powmod(int a, int b) {
  int res = 1;
  a %= denom;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % denom;
    a = a * a % denom;
  }
  return res;
}
int n;
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = (0); i < (n); i++) {
      cin >> a[i];
      a[i]--;
    }
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    dp[0][1] = a[0] == 0 ? 1 : 0;
    for (int i = (1); i < (n); i++) {
      for (int j = (1); j < (n + 1); j++) {
        dp[i][j] =
            max(dp[i - 1][j], dp[i - 1][j - 1] + (a[i] + 1 == j ? 1 : 0));
      }
    }
    int res = INT_MAX;
    for (int j = (0); j < (n + 1); j++) {
      if (dp[n - 1][j] < k) continue;
      res = min(res, n - j);
    }
    cout << (res > n ? -1 : res) << endl;
  }
  return 0;
}
