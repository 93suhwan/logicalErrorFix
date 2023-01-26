#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;
void solve() {
  int64_t n;
  cin >> n;
  vector<string> s(n);
  for (int64_t i = 0; i < n; i++) cin >> s[i];
  vector<vector<int64_t>> mp(n), mp_cnt(n);
  vector<int64_t> str_bal(n);
  for (int64_t i = 0; i < n; i++) {
    mp[i].resize(s[i].size());
    mp_cnt[i].resize(s[i].size());
    int64_t bal = 0, Min = 1;
    for (int64_t j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '(')
        bal++;
      else
        bal--;
      Min = min(Min, bal);
      mp[i][j] = Min;
      if (j > 0 && mp[i][j - 1] == Min) {
        if (bal == Min)
          mp_cnt[i][j] = mp_cnt[i][j - 1] + 1;
        else
          mp_cnt[i][j] = mp_cnt[i][j - 1];
      } else
        mp_cnt[i][j] = 1;
    }
    str_bal[i] = bal;
  }
  int64_t msk = 1 << n;
  vector<int64_t> dp(msk, -1), msk_bal(msk);
  dp[0] = 0;
  int64_t ans = 0;
  for (int64_t i = 1; i < msk; i++) {
    for (int64_t j = 0; j < n; j++) {
      int64_t to = i ^ (1 << j);
      if (to == i || dp[to] == -1) continue;
      msk_bal[i] = msk_bal[to] + str_bal[j];
      int64_t l = 0, r = s[j].size();
      while (l < r) {
        int64_t mid = (l + r) / 2;
        if (mp[j][mid] >= -msk_bal[to])
          l = mid + 1;
        else
          r = mid;
      }
      if (l == s[j].size()) {
        if (mp[j].back() == -msk_bal[to])
          dp[i] = dp[to] + mp_cnt[j].back();
        else
          dp[i] = dp[to];
      } else
        ans = max(ans, dp[to] + (l > 0 ? mp_cnt[j][l - 1] : 0));
    }
  }
  ans = max(ans, dp.back());
  cout << ans << "\n";
  return;
}
signed main() {
  int64_t t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
