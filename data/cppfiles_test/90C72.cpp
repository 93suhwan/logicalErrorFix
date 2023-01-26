#include <bits/stdc++.h>
using namespace std;
void dfs(int v, int anc, vector<vector<int>> &edges, vector<bool> &leaf,
         int &sumleaf, int &comps) {
  vector<bool> bruh;
  for (auto i : edges[v]) {
    if (i == anc) continue;
    dfs(i, v, edges, leaf, sumleaf, comps);
    bruh.push_back(leaf[i]);
  }
  int cntleaf = 0, cnt_not_leaf = 0;
  for (auto i : bruh) {
    if (i)
      cntleaf++;
    else
      cnt_not_leaf++;
  }
  if (!cntleaf) {
    if (v == 1) comps++;
    leaf[v] = 1;
    sumleaf++;
    return;
  }
  comps++;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> points(n);
  for (int i = 0; i < n; i++) cin >> points[i];
  sort(points.begin(), points.end());
  vector<pair<long long, long long>> s;
  vector<vector<pair<long long, long long>>> lst;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    auto it = lower_bound(points.begin(), points.end(), l);
    if (it != points.end() && *it <= r) continue;
    s.push_back({l, r});
  }
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  points.push_back(-1e18), points.push_back(1e18);
  sort(points.begin(), points.end());
  for (int i = 1; i < points.size(); i++) {
    lst.push_back(vector<pair<long long, long long>>());
    while (s.size() && s.back().first < points[i])
      lst.back().push_back(s.back()), s.pop_back();
    sort(lst.back().begin(), lst.back().end());
  }
  vector<vector<long long>> dp(n + 2, vector<long long>(2, 1e18));
  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i < n + 2; i++) {
    vector<long long> pref(lst[i - 1].size() + 1), suf(lst[i - 1].size() + 1);
    pref[0] = points[i - 1], suf[0] = points[i];
    for (int j = 1; j < lst[i - 1].size() + 1; j++)
      pref[j] = max(pref[j - 1], lst[i - 1][j - 1].first);
    for (int j = 1; (long long)lst[i - 1].size() - j >= 0; j++)
      suf[j] = min(suf[j - 1], lst[i - 1][lst[i - 1].size() - j].second);
    for (int type1 = 0; type1 <= 1; type1++) {
      for (int type2 = 0; type2 <= 1; type2++) {
        for (int j = 0; j <= lst[i - 1].size(); j++) {
          int pr1 = 1, pr2 = 1;
          if (type1) pr1 = 2;
          if (!type2) pr2 = 2;
          dp[i][type2] = min(
              dp[i][type2],
              dp[i - 1][type1] + (long long)(pref[j] - points[i - 1]) * pr1 +
                  (long long)(points[i] - suf[lst[i - 1].size() - j]) * pr2);
        }
      }
    }
  }
  long long mins = 1e18;
  for (int i = 0; i < 2; i++) mins = min(mins, dp[n + 1][i]);
  cout << mins << endl;
}
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
