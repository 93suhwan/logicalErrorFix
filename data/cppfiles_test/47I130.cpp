#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, S_INF = 1e7;
void solve() {
  int n, k;
  cin >> n >> k;
  int x;
  vector<int> neg, pos;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x < 0)
      neg.push_back(-1 * x);
    else
      pos.push_back(x);
  }
  sort(neg.rbegin(), neg.rend());
  sort(pos.rbegin(), pos.rend());
  long long int ans = 0LL;
  {
    vector<long long int> dp(pos.size() + 1, 1e10);
    dp[0] = 0;
    for (int i = 0; i < (int)pos.size(); ++i) {
      dp[i + 1] = min(dp[i + 1], dp[i] + (long long int)2 * pos[i]);
      int take_more = k - 1, pp = i + 2;
      while (pp <= (int)pos.size() && take_more) {
        take_more--;
        dp[pp] = min(dp[pp], dp[i] + (long long int)2 * pos[i]);
        pp++;
      }
    }
    ans += dp.back();
  }
  {
    vector<long long int> dp(neg.size() + 1, 1e10);
    dp[0] = 0;
    for (int i = 0; i < (int)neg.size(); ++i) {
      dp[i + 1] = min(dp[i + 1], dp[i] + (long long int)2 * neg[i]);
      int take_more = k - 1, pp = i + 2;
      while (pp <= (int)neg.size() && take_more) {
        take_more--;
        dp[pp] = min(dp[pp], dp[i] + (long long int)2 * neg[i]);
        pp++;
      }
    }
    ans += dp.back();
  }
  if (pos.empty()) pos.push_back(0);
  if (neg.empty()) neg.push_back(0);
  ans -= max(neg[0], pos[0]);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
