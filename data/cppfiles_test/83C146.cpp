#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ios_base;
using std::max;
using std::min;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
short kmp[10050][10050];
int dp[10050];
inline bool compare(int i, int j, const string& s) {
  if (kmp[i][j] == s.size() - i)
    return false;
  else
    return s[i + kmp[i][j]] > s[j + kmp[i][j]];
}
inline int cal(int i, int j, const string& s) {
  if (compare(i, j, s))
    return dp[j] + s.size() - i - kmp[i][j];
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  for (; t > 0; t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++) kmp[i][j] = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (i == j)
          kmp[i][j] = n - i;
        else {
          if (s[i] != s[j])
            kmp[i][j] = 0;
          else
            kmp[i][j] = kmp[i + 1][j + 1] + 1;
        }
      }
    }
    int ans = n;
    dp[0] = n;
    for (int i = 1; i < n; i++) {
      dp[i] = n - i;
      for (int j = 0; j < i; j++) {
        dp[i] = max(dp[i], cal(i, j, s));
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
  }
  return 0;
}
