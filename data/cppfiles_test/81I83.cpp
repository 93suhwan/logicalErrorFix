#include <bits/stdc++.h>
using namespace std;
template <class I>
bool chmax(I& a, I b) {
  return a < b ? (a = b, true) : false;
}
template <class I>
bool chmin(I& a, I b) {
  return b < a ? (a = b, true) : false;
}
#pragma GCC optimize("Ofast")
struct LISAN : vector<int> {
  void done() {
    sort(begin(), end());
    erase(unique(begin(), end()), end());
  }
  int operator()(int v) { return lower_bound(begin(), end(), v) - begin(); }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, d;
  cin >> n >> d;
  int cnt = 0;
  vector<pair<int, int> > hiker;
  LISAN lisan;
  lisan.emplace_back(d);
  for (int s, a, i = 0; i < n; ++i) {
    cin >> s >> a;
    if (s < d) continue;
    if (a <= d) {
      ++cnt;
      continue;
    }
    hiker.emplace_back(s, a);
    lisan.emplace_back(s);
    lisan.emplace_back(a);
  }
  lisan.done();
  int C = lisan.size();
  ((void)0);
  vector<int> dp(C, 0);
  dp[0] = cnt;
  vector<int> ad(C, 0), sc(C, -1);
  for (auto& [s, a] : hiker) {
    s = lisan(s);
    a = lisan(a);
    ((void)0);
    if (a <= s)
      ++ad[a];
    else
      sc[a] = max(sc[a], s);
  }
  ((void)0);
  ((void)0);
  for (int i = 1; i < C; ++i) ad[i] += ad[i - 1];
  for (int i = 1; i < C; ++i) {
    if (sc[i] != -1)
      dp[i] = ad[i] - ad[sc[i]] + dp[sc[i]] + 1;
    else
      dp[i] = ad[i] - ad[i - 1] + dp[i - 1];
    dp[i] = max(dp[i], dp[i - 1]);
  }
  ((void)0);
  cout << dp[C - 1];
  return 0;
}
