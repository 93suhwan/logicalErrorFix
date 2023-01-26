#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const double PI = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int INFS = 1000000001;
const long long LLINF = 9223372036854775807;
const long long M = 1000000007;
const double EPS = 1e-8;
struct node {
  int l, r;
  pair<int, int> mn = {1000000, -1}, d = {1000000, -1};
};
vector<node> st;
void build(int v, int l, int r) {
  st[v].l = l;
  st[v].r = r;
  if (l == r) return;
  int mid = (l + r) / 2;
  build(2 * v + 1, l, mid);
  build(2 * v + 2, mid + 1, r);
}
void push(int v) {
  st[v].mn = min(st[v].mn, st[v].d);
  if (st[v].l != st[v].r) {
    st[2 * v + 1].d = min(st[2 * v + 1].d, st[v].d);
    st[2 * v + 2].d = min(st[2 * v + 2].d, st[v].d);
  }
  st[v].d = {1000000, -1};
}
pair<int, int> get(int v, int l, int r) {
  push(v);
  if (l > st[v].r || r < st[v].l) return {1000000, -1};
  if (l <= st[v].l && r >= st[v].r) return st[v].mn;
  return min(get(2 * v + 1, l, r), get(2 * v + 2, l, r));
}
void upd(int v, int l, int r, int val, int idx) {
  push(v);
  if (l > st[v].r || r < st[v].l) return;
  if (l <= st[v].l && r >= st[v].r) {
    st[v].d = {val, idx};
    push(v);
    return;
  }
  upd(2 * v + 1, l, r, val, idx);
  upd(2 * v + 2, l, r, val, idx);
  st[v].mn = min(st[2 * v + 1].mn, st[2 * v + 2].mn);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, int> > > segs(n);
  int t, l, r;
  map<int, int> id = {};
  for (int i = 0; i < q; i++) {
    cin >> t >> l >> r;
    --t;
    segs[t].push_back({l, r});
    id[l] = 0;
    id[r] = 0;
  }
  int m = 0;
  for (auto x : id) id[x.first] = m++;
  st.resize(4 * m);
  build(0, 0, m - 1);
  vector<int> dp(n), pr(n);
  dp[0] = n - 1;
  pr[0] = 0;
  for (auto seg : segs[0]) upd(0, id[seg.first], id[seg.second], dp[0], 0);
  pair<int, int> got;
  for (int i = 1; i < n; i++) {
    dp[i] = n - 1;
    pr[i] = i;
    for (auto seg : segs[i]) {
      got = get(0, id[seg.first], id[seg.second]);
      if (got.first - 1 < dp[i]) {
        dp[i] = got.first - 1;
        pr[i] = got.second;
      }
    }
    for (auto seg : segs[i]) upd(0, id[seg.first], id[seg.second], dp[i], i);
  }
  pair<int, int> mn = {dp[0], 0};
  for (int i = 1; i < n; i++) {
    if (dp[i] < mn.first) {
      mn.first = dp[i];
      mn.second = i;
    }
  }
  vector<int> ans = {};
  vector<bool> used(n, false);
  int cr = mn.second;
  while (cr != pr[cr]) {
    used[cr] = true;
    cr = pr[cr];
  }
  used[cr] = true;
  for (int i = 0; i < n; i++) {
    if (!used[i]) ans.push_back(i + 1);
  }
  if (ans.size() != mn.first) return -1;
  cout << ans.size() << "\n";
  for (auto x : ans) cout << x << ' ';
  cout << "\n";
  return 0;
}
