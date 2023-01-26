#include <bits/stdc++.h>
using namespace std;
template <int maxn>
struct lazy {
  pair<int, int> tree[maxn * 4 + 5], pend[maxn * 4 + 5];
  lazy() {
    for (int i = 0; i < maxn * 4 + 3; ++i)
      tree[i] = {1000000000, 1000000000}, pend[i] = {1000000000, 1000000000};
  }
  void propagate(int cur, int ss, int se) {
    if (pend[cur].first != 1000000000) {
      tree[cur] = min(tree[cur], pend[cur]);
      if (ss != se) {
        pend[cur * 2 + 1] = min(pend[cur * 2 + 1], pend[cur]);
        pend[cur * 2 + 2] = min(pend[cur * 2 + 2], pend[cur]);
      }
      pend[cur].first = 1000000000;
    }
  }
  void addUtil(int cur, int ss, int se, int l, int r, pair<int, int> val) {
    propagate(cur, ss, se);
    if (ss > se || ss > r || se < l) return;
    if (ss >= l && se <= r) {
      pend[cur] = val;
      propagate(cur, ss, se);
      return;
    }
    addUtil(cur * 2 + 1, ss, (ss + se) / 2, l, r, val);
    addUtil(cur * 2 + 2, (ss + se) / 2 + 1, se, l, r, val);
    tree[cur] = min(tree[cur * 2 + 1], tree[cur * 2 + 2]);
  }
  void add(int l, int r, pair<int, int> val) {
    addUtil(0, 0, maxn - 1, l, r, val);
  }
  pair<int, int> getUtil(int ss, int se, int l, int r, int cur) {
    propagate(cur, ss, se);
    if (ss > se || ss > r || se < l) return {1000000000, 1000000000};
    if (ss >= l && se <= r) {
      return tree[cur];
    }
    return min(getUtil(ss, (ss + se) / 2, l, r, cur * 2 + 1),
               getUtil((ss + se) / 2 + 1, se, l, r, cur * 2 + 2));
  }
  pair<int, int> get(int l, int r) { return getUtil(0, maxn - 1, l, r, 0); }
};
lazy<600005> dps;
int dp[300005];
vector<pair<int, int>> seg[300005];
int back[300005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int j, l, r;
    cin >> j >> l >> r;
    --j;
    seg[j].push_back({l, r});
  }
  for (int i = 0; i < n; ++i) sort(seg[i].begin(), seg[i].end());
  vector<int> all;
  for (int i = 0; i < n; ++i) {
    for (auto j : seg[i]) all.push_back(j.first), all.push_back(j.second);
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  map<int, int> indx;
  int k = 0;
  for (auto i : all) {
    indx[i] = k++;
  }
  for (int i = 0; i < n; ++i) {
    for (auto& j : seg[i]) {
      j.first = indx[j.first];
      j.second = indx[j.second];
    }
  }
  dp[n - 1] = 0;
  back[n - 1] = -1;
  for (auto j : seg[n - 1]) {
    auto [l, r] = j;
    dps.add(l, r, {n - 1, n - 1});
  }
  for (int i = n - 2; i >= 0; --i) {
    int& res = dp[i];
    res = n - i - 1;
    back[i] = -1;
    for (auto j : seg[i]) {
      auto [l, r] = j;
      if (res > dps.get(l, r).first - (i + 1)) {
        back[i] = dps.get(l, r).second;
      }
      res = min(res, dps.get(l, r).first - (i + 1));
    }
    for (auto j : seg[i]) {
      auto [l, r] = j;
      dps.add(l, r, {res + i, i});
    }
  }
  int ans = 1000000000;
  for (int i = 0; i < n; ++i) ans = min(ans, dp[i] + i);
  assert(ans != 1000000000);
  cout << ans << endl;
  for (int i = 0; i < n; ++i) {
    if (ans == dp[i] + i) {
      int cur = i;
      vector<int> all;
      while (back[cur] != -1) {
        all.push_back(cur);
        cur = back[cur];
      }
      all.push_back(cur);
      for (int j = 0; j < i; ++j) cout << j + 1 << ' ';
      for (int j = 0; j + 1 < all.size(); ++j) {
        for (int k = all[j] + 1; k < all[j + 1]; ++k) {
          cout << k + 1 << ' ';
        }
      }
      if (!all.empty())
        for (int j = all.back() + 1; j < n; ++j) cout << j + 1 << ' ';
      cout << endl;
      return 0;
    }
  }
  assert(0);
}
