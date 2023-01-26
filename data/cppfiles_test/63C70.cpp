#include <bits/stdc++.h>
using namespace std;
auto fio = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));
int32_t main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vector<vector<int>> pfx(n), cnt(n);
  vector<int> all(n);
  for (int i = 0; i < n; i++) {
    int sz = s[i].size();
    int SH = sz + 2;
    cnt[i].resize(2 * sz + 4);
    pfx[i].resize(2 * sz + 4, -1);
    int bal = 0;
    for (int j = 0; j < sz; j++) {
      bal += s[i][j] == '(' ? +1 : -1;
      if (pfx[i][bal + SH] == -1) {
        pfx[i][bal + SH] = cnt[i][bal + 1 + SH];
      }
      cnt[i][bal + SH]++;
    }
    all[i] = bal;
  }
  auto smax = [](int& a, int b) { return a = max(a, b); };
  int ans = 0;
  vector<int> dp(1 << n, -1);
  dp[0] = 0;
  for (int msk = 0; msk < 1 << n; msk++) {
    if (dp[msk] == -1) continue;
    int bal = 0;
    for (int i = 0; i < n; i++)
      if (msk >> i & 1) bal += all[i];
    if (bal < 0) continue;
    for (int i = 0; i < n; i++) {
      int sz = s[i].size();
      int SH = sz + 2;
      if (~msk >> i & 1) {
        if (bal > sz)
          smax(dp[msk | 1 << i], dp[msk]);
        else {
          if (pfx[i][-bal - 1 + SH] != -1) {
            smax(ans, dp[msk] + pfx[i][-bal - 1 + SH]);
          } else {
            smax(dp[msk | 1 << i], dp[msk] + cnt[i][-bal + SH]);
          }
        }
      }
    }
    smax(ans, dp[msk]);
  }
  cout << ans << endl;
}
