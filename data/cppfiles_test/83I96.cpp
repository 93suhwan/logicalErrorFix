#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000 + 7;
int T;
int n;
string s[MAX_N];
int ord[MAX_N], tOrd[MAX_N];
int dp[MAX_N];
int p[MAX_N][MAX_N];
void kmp(int k) {
  int i = 0, j;
  for (j = 1; j < s[k].length(); ++j) {
    while (s[k][i] != s[k][j] && i > 0) {
      i = p[k][i - 1];
    }
    if (s[k][i] == s[k][j]) {
      p[k][j] = ++i;
    } else {
      p[k][j] = 0;
    }
  }
}
bool cmp(int a, int b) { return s[a] < s[b]; }
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s[0];
    ord[0] = 0;
    for (int i = 1; i < n; ++i) {
      s[i] = s[0];
      s[i].erase(0, i);
      ord[i] = i;
      dp[i] = 0;
      for (int j = 0; j < n - i; ++j) {
        p[i][j] = 0;
      }
    }
    sort(ord, ord + n, cmp);
    for (int i = 0; i < n; ++i) {
      tOrd[ord[i]] = i;
      kmp(i);
    }
    dp[0] = n;
    int ans = dp[0];
    for (int i = 1; i < n; ++i) {
      dp[i] = n - i;
      for (int j = 0; j < tOrd[i]; ++j) {
        if (ord[j] < i) {
          dp[i] = max(dp[i], dp[ord[j]] + n - i - p[ord[j]][i - ord[j]]);
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
