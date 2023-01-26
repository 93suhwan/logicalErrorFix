#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, a[N], b[N], t[N], mi[N << 2], tag[N << 2];
pair<int, int> v[N];
long long ans;
int lb(int x) { return x & (-x); }
void add(int x) {
  while (x <= n) t[x]++, x += lb(x);
}
int ask(int x) {
  int res = 0;
  while (x) res += t[x], x -= lb(x);
  return res;
}
void pushup(int pos) { mi[pos] = min(mi[pos << 1], mi[pos << 1 | 1]); }
void pushdown(int pos) {
  int& tg = tag[pos];
  if (tg)
    mi[pos << 1] += tg, mi[pos << 1 | 1] += tg, tag[pos << 1] += tg,
        tag[pos << 1 | 1] += tg, tg = 0;
}
void upd(int l, int r, int pos, int L, int R, int x) {
  if (L <= l && r <= R) {
    mi[pos] += x;
    tag[pos] += x;
    return;
  }
  int mid = l + r >> 1;
  pushdown(pos);
  if (L <= mid) upd(l, mid, pos << 1, L, R, x);
  if (R > mid) upd(mid + 1, r, pos << 1 | 1, L, R, x);
  pushup(pos);
}
void solve() {
  vector<int> gg;
  scanf("%d%d", &n, &m);
  fill_n(t + 1, n, 0);
  fill_n(mi + 1, n * 4, 0);
  fill_n(tag + 1, n * 4, 0);
  ans = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), gg.push_back(a[i]), v[i] = make_pair(a[i], i);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(b + 1, b + n + 1);
  sort(v + 1, v + n + 1);
  sort(gg.begin(), gg.end());
  gg.erase(unique(gg.begin(), gg.end()), gg.end());
  for (int i = 1, x; i <= n; i++)
    add(x = lower_bound(gg.begin(), gg.end(), a[i]) - gg.begin() + 1),
        ans += i - ask(x);
  int l = 0, long long = 0;
  for (int i = 1; i <= n; i++)
    if (v[i].first > b[1])
      upd(1, n + 1, 1, v[i].second + 1, n + 1, 1);
    else if (v[i].first < b[1])
      upd(1, n + 1, 1, 1, v[i].second, 1), l = long long = i;
    else
      long long = i;
  ans += mi[1];
  for (int i = 2; i <= m; i++) {
    while (long long < n && v[long long + 1].first <= b[i])
      long long ++, upd(1, n + 1, 1, v[long long].second + 1, n + 1, -1);
    while (l < n && v[l + 1].first < b[i])
      l++, upd(1, n + 1, 1, 1, v[l].second, 1);
    ans += mi[1];
  }
  printf("%lld\n", ans);
}
signed main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
