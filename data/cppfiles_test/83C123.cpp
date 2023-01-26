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
    int dp[n];
    fill(dp, dp + n, 0);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      int z[n];
      fill(z + i, z + n, 0);
      for (int j = i + 1, l = i, r = i; j < n; j++) {
        if (j + z[j - l + i] < r) {
          z[j] = z[j - l + i];
        } else {
          l = j;
          r = max(r, j);
          while (r < n && s[r - l + i] == s[r]) {
            r++;
          }
          z[j] = r - l;
        }
        if (j + z[j] < n && s[j + z[j]] > s[i + z[j]]) {
          dp[i] = max(dp[i], dp[j] + (n - j - z[j]));
        }
      }
      ans = max(ans, dp[i] + (n - i));
    }
    cout << ans << endl;
  }
  return 0;
}
