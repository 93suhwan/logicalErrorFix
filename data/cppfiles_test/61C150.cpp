#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[110][2];
int prv[110][2];
int solve(int i, int last) {
  if (i == n) return 0;
  if (dp[i][last] >= 0) return dp[i][last];
  if (s[i] == '?') {
    int a = (last == 0) + solve(i + 1, 0);
    int b = (last == 1) + solve(i + 1, 1);
    dp[i][last] = min(a, b);
    if (a > b) {
      prv[i][last] = 1;
    } else {
      prv[i][last] = 0;
    }
  } else {
    if (s[i] - 'A' == last) {
      dp[i][last] = (i > 0) + solve(i + 1, s[i] - 'A');
    } else {
      dp[i][last] = solve(i + 1, s[i] - 'A');
    }
  }
  return dp[i][last];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
      if (s[i] == 'R') s[i] = 'A';
    for (int i = 0; i < n; i++) {
      dp[i][0] = dp[i][1] = -1;
    }
    int res = solve(0, 0);
    int cur = 0;
    int last = 0;
    while (cur < n) {
      if (s[cur] == '?') {
        s[cur] = 'A' + prv[cur][last];
        last = prv[cur][last];
      } else {
        last = s[cur] - 'A';
      }
      cur++;
    }
    for (int i = 0; i < n; i++)
      if (s[i] == 'A') s[i] = 'R';
    cout << s << endl;
  }
  return 0;
}
