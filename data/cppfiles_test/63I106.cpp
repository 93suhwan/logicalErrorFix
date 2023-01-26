#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
unordered_map<int, int> cnt[20];
unordered_map<int, int> pre[20];
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
      if (!pre[i][t]) pre[i][t] = cnt[i][t + 1];
    }
    sum[1 << i] = t;
  }
  for (int i = 1; i < (1 << n); i++) {
    sum[i] = sum[i ^ lowbit(i)] + sum[lowbit(i)];
    for (int j = 0; j < n; j++)
      if ((i >> j) & 1) {
        int k = (1 << j);
        if (bad[i ^ k]) continue;
        int d = -sum[i ^ k];
        if (cnt[j][d - 1]) {
          if (dp[i] < dp[i ^ k] + pre[j][d - 1]) {
            dp[i] = dp[i ^ k] + pre[j][d - 1];
            bad[i] = 1;
          }
        } else {
          if (dp[i] < dp[i ^ k] + cnt[j][d]) {
            dp[i] = dp[i ^ k] + cnt[j][d];
            bad[i] = 0;
          }
        }
      }
  }
  cout << *max_element(dp, dp + (1 << n)) << '\n';
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
