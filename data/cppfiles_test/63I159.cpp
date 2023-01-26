#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> cnt[21];
unordered_map<int, int> pre[21];
int sum[1 << 20];
bool bad[1 << 20];
int dp[1 << 20];
inline int lowbit(int x) { return x & -x; }
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int t = 0;
    for (int j = 0, len = str.size(); j < len; j++) {
      t += (str[j] == '(' ? 1 : -1);
      cnt[i][t]++;
      if (pre[i].find(t) == pre[i].end()) pre[i][t] = cnt[i][t + 1];
    }
    sum[1 << i] = t;
  }
  for (int i = 1; i < (1 << n); i++) {
    sum[i] = sum[i ^ lowbit(i)] + sum[lowbit(i)];
    if (sum[i] < 0) bad[i] = 1;
    bool ok = false;
    for (int j = 0; j < n; j++)
      if ((i >> j) & 1) {
        int k = (1 << j);
        if (bad[i ^ k])
          dp[i] = max(dp[i], dp[i ^ k]);
        else {
          int d = -sum[i ^ k] - 1;
          if (cnt[j][d])
            dp[i] = max(dp[i], dp[i ^ k] + pre[j][d]);
          else {
            dp[i] = max(dp[i], dp[i ^ k] + cnt[j][d + 1]);
            ok = true;
          }
        }
      }
    if (!ok) bad[i] = 1;
  }
  cout << dp[(1 << n) - 1] << '\n';
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
