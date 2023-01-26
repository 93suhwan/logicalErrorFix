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
struct BIT {
  int n;
  vector<int> val;
  BIT(int n = 0) : n(n), val(n + 1, 0) {}
  void modify(int p, int v) {
    for (; p <= n; p += p & -p) val[p] += v;
  }
  int query(int p) {
    int r = 1;
    for (; p > 0; p -= p & -p) r += val[p];
    return r;
  }
  int query(int l, int r) { return query(r) - query(l - 1); }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, d;
  cin >> n >> d;
  int cnt = 0;
  vector<pair<int, int>> hiker;
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
  vector<int> dp(C, 0);
  dp[0] = cnt;
  vector<int> ad(C, 0), sc(C, -1);
  vector<vector<int>> rm(C + 1, vector<int>());
  for (auto& [s, a] : hiker) {
    s = lisan(s);
    a = lisan(a);
    if (a <= s)
      ++ad[a], rm[s + 1].emplace_back(a);
    else
      sc[a] = max(sc[a], s);
  }
  BIT bit(C);
  for (int i = 1; i < C; ++i) {
    bit.modify(i, ad[i]);
    for (int& j : rm[i]) bit.modify(j, -1);
    if (sc[i] != -1) dp[i] = bit.query(sc[i] + 1, i) + dp[sc[i]] + 1;
    dp[i] = max(dp[i], dp[i - 1] + ad[i]);
  }
  cout << dp[C - 1];
  return 0;
}
