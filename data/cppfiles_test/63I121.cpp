#include <bits/stdc++.h>
using namespace std;
int n, dp[2][1048576], cnt[1048576];
string s[23];
int mp[23][800003];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int qaq = 0;
    for (int j = 0; j < s[i].size(); j++)
      if (s[i][j] == '(')
        qaq++;
      else
        qaq--;
    cnt[1 << i] = qaq;
  }
  for (int i = 2; i < 1048576; i++) cnt[i] = cnt[i & -i] + cnt[i - (i & -i)];
  for (int i = 0; i < n; i++) {
    int minn = 0, qaq = 0, CNT = 0;
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '(')
        qaq++;
      else
        qaq--;
      if (qaq < minn) CNT = 0;
      minn = min(minn, qaq);
      if (qaq == minn) CNT++;
      mp[i][-minn] = CNT;
    }
  }
  for (int i = 0; i < 1048576; i++) dp[0][i] = -19260817, dp[1][i] = -19260817;
  dp[1][0] = 0;
  for (int i = 1; i < (1 << n); i++) {
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) {
        dp[0][i] = max(dp[0][i], dp[0][i ^ (1 << j)]);
        dp[cnt[i] >= 0][i] = max(
            dp[cnt[i] >= 0][i], dp[1][i ^ (1 << j)] + mp[j][cnt[i ^ (1 << j)]]);
      }
  }
  cout << max(dp[0][(1 << n) - 1], dp[1][(1 << n) - 1]);
}
