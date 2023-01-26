#include <bits/stdc++.h>
using namespace std;
const long long MN = 300005;
long long n, m, row, l, r, dp[MN], bck[MN];
vector<pair<long long, long long> > v[MN];
vector<long long> xs;
map<long long, long long> mp;
pair<long long, long long> st[MN * 12], lzy[MN * 12];
pair<long long, long long> push_up(pair<long long, long long> x,
                                   pair<long long, long long> y) {
  if (x.first < y.first)
    return x;
  else
    return y;
}
void push_down(long long l, long long r, long long idx) {
  if (!lzy[idx].second) return;
  st[idx] = min(st[idx], lzy[idx]);
  if (l != r) lzy[idx * 2] = lzy[idx * 2 + 1] = min(lzy[idx * 2], lzy[idx]);
  lzy[idx] = {0, 0};
}
void build(long long l, long long r, long long idx) {
  if (l == r) {
    st[idx] = {-1, 0};
    return;
  }
  long long mid = (l + r) >> 1;
  build(l, mid, idx * 2), build(mid + 1, r, idx * 2 + 1);
  st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}
void upd(long long l, long long r, long long x, long long y,
         pair<long long, long long> val, long long idx) {
  push_down(l, r, idx);
  if (r < x || l > y) return;
  if (r <= y && l >= x) {
    lzy[idx] = val;
    push_down(l, r, idx);
    return;
  }
  long long mid = (l + r) >> 1;
  upd(l, mid, x, y, val, idx * 2), upd(mid + 1, r, x, y, val, idx * 2 + 1);
  st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}
pair<long long, long long> qry(long long l, long long r, long long x,
                               long long y, long long idx) {
  push_down(l, r, idx);
  if (r < x || l > y) return {0x3f3f3f3f, 0x3f3f3f3f};
  if (r <= y && l >= x) return st[idx];
  long long mid = (l + r) >> 1;
  return push_up(qry(l, mid, x, y, idx * 2),
                 qry(mid + 1, r, x, y, idx * 2 + 1));
}
int32_t main() {
  cin.tie(0), cin.sync_with_stdio(0);
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> row >> l >> r;
    xs.push_back(l);
    xs.push_back(r);
    v[row].push_back({l, r});
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (long long i = 0; i < xs.size(); i++) mp[xs[i]] = i + 1;
  v[n + 1].push_back({xs[0], xs.back()});
  build(1, xs.size(), 1);
  for (long long i = 1; i <= n + 1; i++) {
    pair<long long, long long> val = {-1, 0};
    for (pair<long long, long long> p : v[i]) {
      l = mp[p.first], r = mp[p.second];
      pair<long long, long long> tmp = qry(1, xs.size(), l, r, 1);
      val = min(val, tmp);
    }
    dp[i] = val.first + i;
    bck[i] = val.second;
    for (pair<long long, long long> p : v[i]) {
      l = mp[p.first], r = mp[p.second];
      upd(1, xs.size(), l, r, {dp[i] - i - 1, i}, 1);
    }
  }
  printf("%lld\n", dp[n + 1]);
  vector<long long> out;
  long long cur = n + 1;
  while (cur) {
    long long pre = bck[cur];
    for (long long i = pre + 1; i < cur; i++) out.push_back(i);
    cur = pre;
  }
  sort(out.begin(), out.end());
  for (long long p : out) printf("%lld ", p);
  return 0;
}
