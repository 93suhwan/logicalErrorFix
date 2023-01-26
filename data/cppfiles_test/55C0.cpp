#include <bits/stdc++.h>
using namespace std;
struct segment_tree {
  int n;
  vector<pair<int, int>> st, lazy;
  segment_tree(int n) : n(n), st(2 * n, {0, -1}), lazy(2 * n) {}
  inline int id(int b, int e) { return (b + e - 1) | (b != e - 1); }
  void prop(int l, int r) {
    int cur = id(l, r);
    st[cur] = max(st[cur], lazy[cur]);
    if (l + 1 != r) {
      int mid = (l + r + 1) >> 1;
      lazy[id(l, mid)] = max(lazy[cur], lazy[id(l, mid)]);
      lazy[id(mid, r)] = max(lazy[id(l, mid)], lazy[cur]);
    }
    lazy[cur] = {0, -1};
  }
  void upd(int li, int ri, pair<int, int> v) { upd(0, n, li, ri, v); }
  void upd(int l, int r, int li, int ri, pair<int, int> v) {
    if (li == ri) return;
    int cur = id(l, r);
    if (lazy[cur].first) prop(l, r);
    if (l >= ri || r <= li) return;
    if (li <= l && r <= ri) {
      lazy[cur] = v;
      prop(l, r);
      return;
    }
    int mid = (l + r + 1) >> 1;
    upd(l, mid, li, ri, v);
    upd(mid, r, li, ri, v);
    st[cur] = max(st[id(l, mid)], st[id(mid, r)]);
  }
  pair<int, int> que(int li, int ri) { return que(0, n, li, ri); }
  pair<int, int> que(int l, int r, int li, int ri) {
    int cur = id(l, r);
    if (lazy[cur].first) prop(l, r);
    if (l >= ri || r <= li) return {0, -1};
    if (li <= l && r <= ri) return st[cur];
    int mid = (l + r + 1) >> 1;
    return max(que(l, mid, li, ri), que(mid, r, li, ri));
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> w;
  vector<vector<pair<int, int>>> e(n);
  for (int i = 0; i < m; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    e[t - 1].push_back({l, r + 1});
    w.push_back(l);
    w.push_back(r + 1);
  }
  sort(w.begin(), w.end());
  w.resize(unique(w.begin(), w.end()) - w.begin());
  int sz = w.size();
  map<int, int> mp;
  for (int i = 0; i < sz; i++) mp[w[i]] = i;
  for (int i = 0; i < n; i++)
    for (auto &j : e[i]) j.first = mp[j.first], j.second = mp[j.second];
  segment_tree st(sz);
  vector<int> p(n, -1);
  for (int i = 0; i < n; i++) {
    pair<int, int> mx = {0, -1};
    for (auto j : e[i]) {
      pair<int, int> t = st.que(j.first, j.second);
      mx = max(mx, t);
    }
    if (mx.first == 0) mx.second = -1;
    p[i] = mx.second;
    for (auto j : e[i]) st.upd(j.first, j.second, {mx.first + 1, i});
  }
  int y = st.que(0, sz).second;
  vector<bool> in(n);
  while (y != -1) {
    in[y] = true;
    y = p[y];
  }
  vector<int> ans;
  for (int i = 0; i < n; i++)
    if (!in[i]) ans.push_back(i);
  cout << ans.size() << "\n";
  for (auto &i : ans) cout << i + 1 << " \n"[&i == &ans.back()];
  return 0;
}
