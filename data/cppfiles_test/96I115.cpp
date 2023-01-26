#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
struct ty {
  int l, r, ctl, ctr, s;
  bool f;
} t[N];
int in[N >> 2], locate[N >> 2];
inline long long get(int x) { return 1LL * x * (x + 1) / 2; }
inline void init_lzy(int i) {
  locate[t[i].l] = i;
  t[i].s = t[i].f = 1;
  t[i].ctl = t[i].ctr = 1;
}
inline ty push_up(ty &x, ty &y, ty &z) {
  if (in[x.r] <= in[y.l]) {
    long long len = x.ctr + y.ctl;
    z.s = x.s + y.s - get(x.ctr) - get(y.ctl) + get(len);
    z.ctl = x.ctl;
    z.ctr = y.ctr;
    if (x.f) z.ctl += y.ctl;
    if (y.f) z.ctr += x.ctr;
    if (x.f && y.f)
      z.f = 1;
    else
      z.f = 0;
  } else {
    z.s = x.s + y.s;
    z.ctl = x.ctl;
    z.ctr = y.ctr;
    z.f = 0;
  }
  z.l = x.l;
  z.r = y.r;
  return z;
}
void inline build(int i, int l, int r) {
  t[i].l = l;
  t[i].r = r;
  if (l == r) {
    init_lzy(i);
    return;
  }
  int m = (l + r) >> 1;
  build(i << 1, l, m);
  build(i << 1 | 1, m + 1, r);
  push_up(t[i << 1], t[i << 1 | 1], t[i]);
}
void change(int i) {
  while (1) {
    if (i == 1) break;
    if (i & 1)
      push_up(t[i - 1], t[i], t[i >> 1]);
    else
      push_up(t[i], t[i + 1], t[i >> 1]);
    i >>= 1;
  }
}
inline ty search_sum(int i, int l, int r) {
  if (l <= t[i].l && t[i].r <= r) {
    return t[i];
  }
  ty x, y, z;
  if (t[i << 1].r >= l && t[i << 1 | 1].l > r) z = search_sum(i << 1, l, r);
  if (t[i << 1 | 1].l <= r && t[i << 1].r < l)
    z = search_sum(i << 1 | 1, l, r);
  else if (t[i << 1].r >= l && t[i << 1 | 1].l <= r) {
    x = search_sum(i << 1, l, r);
    y = search_sum(i << 1 | 1, l, r);
    z = push_up(x, y, z);
  }
  return z;
}
int main() {
  std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> in[i];
  build(1, 1, n);
  while (q--) {
    int ti, l, r;
    cin >> ti >> l >> r;
    if (ti == 1) {
      in[l] = r;
      change(locate[l]);
    } else {
      cout << search_sum(1, l, r).s << '\n';
    }
  }
  return 0;
}
