#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int inf = 2e9;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
const long long C = 1e6;
struct segtree {
  long long seg[maxn * 4], tag[maxn * 4];
  void init() {
    memset(seg, 0, sizeof(seg));
    memset(tag, 0, sizeof(tag));
  }
  void push(long long now, long long l, long long r) {
    if (tag[now] == 0) return;
    tag[now * 2] = tag[now * 2 + 1] = seg[now * 2] = seg[now * 2 + 1] =
        tag[now];
    tag[now] = 0;
  }
  void modify(long long now, long long l, long long r, long long ql,
              long long qr, long long v) {
    if (l >= ql && r <= qr) {
      tag[now] = seg[now] = v;
      return;
    }
    push(now, l, r);
    long long m = (l + r) >> 1;
    if (ql <= m) modify(now * 2, l, m, ql, qr, v);
    if (qr >= m + 1) modify(now * 2 + 1, m + 1, r, ql, qr, v);
  }
  long long query(long long now, long long l, long long r, long long ql,
                  long long qr) {
    if (l >= ql && r <= qr) return seg[now];
    push(now, l, r);
    long long m = (l + r) >> 1;
    if (qr <= m) return query(now * 2, l, m, ql, qr);
    if (ql > m) return query(now * 2 + 1, m + 1, r, ql, qr);
    return max(query(now * 2, l, m, ql, qr),
               query(now * 2 + 1, m + 1, r, ql, qr));
  }
} tree;
long long dp[maxn], prevv[maxn];
vector<pair<long long, long long> > v[maxn];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> values;
  for (long long i = 1; i <= m; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    v[x].push_back({y, z});
    values.push_back(y);
    values.push_back(z);
  }
  sort((values).begin(), (values).end());
  values.resize(unique((values).begin(), (values).end()) - values.begin());
  long long N = ((long long)(values).size());
  for (long long i = 1; i <= n; i++) {
    for (pair<long long, long long> &j : v[i]) {
      j.first = lower_bound((values).begin(), (values).end(), j.first) -
                values.begin() + 1;
      j.second = lower_bound((values).begin(), (values).end(), j.second) -
                 values.begin() + 1;
    }
  }
  tree.init();
  pair<long long, long long> maxx = {-1, -1};
  for (long long i = 1; i <= n; i++) {
    long long mx = 0;
    for (pair<long long, long long> j : v[i])
      mx = max(mx, tree.query(1, 1, N, j.first, j.second));
    prevv[i] = mx % C;
    dp[i] = (mx / C + 1) * C + i;
    for (pair<long long, long long> j : v[i])
      tree.modify(1, 1, N, j.first, j.second, dp[i]);
    maxx = max(maxx, {dp[i], i});
  }
  vector<long long> used(n), ans;
  long long ttmp = maxx.second;
  while (ttmp) {
    used[ttmp - 1] = 1;
    ttmp = prevv[ttmp];
  }
  for (long long i = 0; i < n; i++) {
    if (!used[i]) ans.push_back(i + 1);
  }
  cout << ((long long)(ans).size()) << '\n';
  for (long long i : ans) cout << i << ' ';
  cout << '\n';
}
