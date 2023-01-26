#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e3 + 14;
int t, n, lcp[MAX_N][MAX_N], dp[MAX_N];
string s;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = n - 1; i >= 0; --i)
      for (int j = 0; j < n; ++j)
        lcp[i][j] = (s[i] == s[j]) * (1 + lcp[i + 1][j + 1]);
    for (int i = 0; i < n; ++i) {
      dp[i] = n - i;
      for (int j = 0; j < i; ++j)
        if (s[j + lcp[i][j]] < s[i + lcp[i][j]])
          dp[i] = max(dp[i], dp[j] + n - i - lcp[i][j]);
    }
    cout << *max_element(dp, dp + n) << '\n';
  }
}
