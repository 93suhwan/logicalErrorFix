#include <bits/stdc++.h>
using namespace std;
const long long INFLL = 1e18;
const int INF = 1e9 + 1;
struct segment_tree {
  vector<int> t;
  segment_tree(int n) { t.assign(4 * n, INF); }
  void mod(int v, int vl, int vr, int id, int val) {
    if (vr - vl == 1) {
      t[v] = min(t[v], val);
      return;
    }
    int vm = (vl + vr) / 2;
    if (id < vm)
      mod(2 * v + 1, vl, vm, id, val);
    else
      mod(2 * v + 2, vm, vr, id, val);
    t[v] = min(t[v], val);
  }
  int get(int v, int vl, int vr, int l, int r) {
    if (vl >= l && vr <= r) return t[v];
    if (r <= vl || l >= vr) return INF;
    int vm = (vl + vr) / 2;
    return min(get(2 * v + 1, vl, vm, l, r), get(2 * v + 2, vm, vr, l, r));
  }
};
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second - a.first < b.second - b.first;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (auto &c : a) cin >> c;
    sort((a).begin(), (a).end());
    vector<pair<int, int>> seg1(m);
    vector<int> dl;
    for (auto &c : seg1) {
      cin >> c.first >> c.second;
      dl.emplace_back(c.first);
    }
    sort((dl).begin(), (dl).end());
    dl.resize(unique((dl).begin(), (dl).end()) - dl.begin());
    sort((seg1).begin(), (seg1).end(), cmp);
    map<int, int> ma;
    for (int i = 0; i < (int)dl.size(); i++) ma[dl[i]] = i;
    segment_tree tr((int)dl.size());
    vector<pair<int, int>> seg;
    for (auto &c : seg1) {
      int id = lower_bound((a).begin(), (a).end(), c.first) - a.begin();
      if (id < (int)a.size() && a[id] <= c.second) continue;
      if (tr.get(0, 0, dl.size(), ma[c.first], dl.size()) <= c.second) continue;
      tr.mod(0, 0, dl.size(), ma[c.first], c.second);
      seg.emplace_back(c.first, c.second);
    }
    m = seg.size();
    sort((seg).begin(), (seg).end());
    vector<vector<pair<int, int>>> g(n + 1);
    int L = -1, R = m;
    while (R - L > 1) {
      int M = (L + R) / 2;
      if (seg[M].second < a[0])
        L = M;
      else
        R = M;
    }
    for (int i = 0; i <= L; i++) g[0].emplace_back(seg[i]);
    for (int i = 0; i < n; i++) {
      int RIGHT = INF;
      if (i + 1 < n) RIGHT = a[i + 1];
      int id = upper_bound((seg).begin(), (seg).end(),
                           make_pair((int)a[i], (int)a[i])) -
               seg.begin();
      if (id == m) continue;
      int L = id - 1, R = m;
      while (R - L > 1) {
        int M = (L + R) / 2;
        if (seg[M].second < RIGHT)
          L = M;
        else
          R = M;
      }
      for (int j = id; j <= L; j++) g[i + 1].emplace_back(seg[j]);
    }
    vector<vector<long long>> dp(n), pr(n), suff(n);
    for (int i = 0; i < n; i++) {
      dp[i].resize(g[i + 1].size() + 1, INFLL);
      pr[i].resize(g[i + 1].size() + 1, INFLL);
      suff[i].resize(g[i + 1].size() + 1, INFLL);
    }
    for (int j = 0; j <= (int)g[1].size(); j++) {
      long long x = 0;
      if (g[0].size()) x = a[0] - g[0][0].second;
      long long y = 0;
      if (j) y = g[1][j - 1].first - a[0];
      dp[0][j] = 2 * min(x, y) + max(x, y);
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= (int)g[i].size(); j++) {
        if (j > 0) pr[i - 1][j] = pr[i - 1][j - 1];
        pr[i - 1][j] =
            min(pr[i - 1][j],
                dp[i - 1][j] - (j == (int)g[i].size() ? a[i] : g[i][j].second));
      }
      for (int j = (int)g[i].size(); j >= 0; j--) {
        if (j + 1 <= (int)g[i].size()) suff[i - 1][j] = suff[i - 1][j + 1];
        suff[i - 1][j] = min(
            suff[i - 1][j],
            dp[i - 1][j] - 2 * (j == (int)g[i].size() ? a[i] : g[i][j].second));
      }
      int L = (int)g[i].size();
      for (int j = 0; j <= (int)g[i + 1].size(); j++) {
        long long y = 0;
        if (j) y = g[i + 1][j - 1].first - a[i];
        while (L > 0 && a[i] - g[i][L - 1].second <= y) L--;
        if (L > 0) dp[i][j] = min(dp[i][j], 2 * y + a[i] + pr[i - 1][L - 1]);
        dp[i][j] = min(dp[i][j], y + 2 * a[i] + suff[i - 1][L]);
      }
    }
    cout << dp[n - 1].back() << "\n";
  }
  return 0;
}
