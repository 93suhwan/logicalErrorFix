#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nxt_gr[n][n];
    fill(nxt_gr[0], nxt_gr[n], n);
    for (int i = n - 1; i >= 0; i--) {
      int z[n];
      fill(z, z + n, 0);
      for (int j = i + 1, l = i, r = i; j < n; j++) {
        if (j + z[j - l + i] <= r) {
          z[j] = z[j - l + i];
        } else {
          l = j;
          if (j >= r) {
            r = j;
          }
          while (r < n && s[r - l + i] == s[r]) {
            r++;
          }
          z[j] = r - l;
        }
        if (j + z[j] < n && s[j + z[j]] > s[i + z[j]]) {
          nxt_gr[i][j] = z[j];
        }
      }
    }
    int dp[n][n];
    fill(dp[0], dp[n], 1);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (nxt_gr[i][j] < n) {
          dp[i][n - 1 - i] = max(dp[i][n - 1 - i], dp[j][nxt_gr[i][j]] + 1);
        }
      }
      for (int j = n - 2 - i; j >= 0; j--) {
        dp[i][j] = dp[i][j + 1] + 1;
      }
    }
    cout << *max_element(dp[0], dp[n]) << endl;
  }
  return 0;
}
