#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int bas = 5e5;
int n, cnt[30][1000000], mnv[30], add[30], sum[1100000], dp[1100000], ans = 0;
string s[30];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    int fim, mn = 1e9, cur = 0;
    for (int j = 0; j < s[i].size(); ++j) {
      cur += (s[i][j] == '(' ? 1 : -1);
      if (cur < mn) mn = cur, fim = j;
    }
    add[i] = cur;
    mnv[i] = mn;
    cur = 0;
    mn = 1e9;
    for (int j = 0; j < s[i].size(); ++j) {
      cur += (s[i][j] == '(' ? 1 : -1);
      if (mn >= cur) ++cnt[i][bas + cur];
      mn = min(mn, cur);
    }
  }
  for (int i = 1; i <= (1 << n) - 1; ++i) {
    int nn = __builtin_ctz(i);
    sum[i] = add[nn] + sum[i ^ (1 << nn)];
  }
  for (int i = 0; i < (1 << n) + 5; ++i) dp[i] = -1;
  dp[0] = 0;
  for (int i = 0; i < 1 << n; ++i)
    if (dp[i] > -1) {
      ans = max(ans, dp[i]);
      int cur = sum[i];
      for (int j = 0; j < n; ++j)
        if ((i & (1 << j)) == 0) {
          if (cur + mnv[j] < 0) {
            ans = max(ans, dp[i] + cnt[j][-cur + bas]);
            continue;
          }
          dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + cnt[j][-cur + bas]);
        }
    }
  cout << ans << endl;
  return 0;
}
