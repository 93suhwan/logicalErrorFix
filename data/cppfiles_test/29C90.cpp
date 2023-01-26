#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
using namespace std;
long double eps = (long double)1 / 1e6;
long long inf_ll = 1e18 + 1, mod1 = 1e9 + 7, mod2 = 998244353;
long long mersen_mod = 2305843009213693951;
long long sqr(long long a) { return a * a; }
long long qb(long long a) { return a * a * a; }
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long add(long long a, long long b, long long mod) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
long long sub(long long a, long long b, long long mod) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
long long binpow(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod
                    : sqr(binpow(a, b / 2, mod)) % mod)
           : 1;
}
long long binmult(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod
                    : (2 * binmult(a, b / 2, mod)) % mod)
           : 0;
}
const long long N = 3e5 + 5;
int a[N], lim = 3e5;
long long ans[N];
pair<long long, long long> new_st[4 * N];
struct node {
  long long rzm, st, d;
};
node seg_tree[4 * N];
void push(int v) {
  if (seg_tree[v].st && seg_tree[v].d) {
    seg_tree[2 * v].st += seg_tree[v].st;
    seg_tree[2 * v].d += seg_tree[v].d;
    seg_tree[2 * v + 1].st +=
        seg_tree[v].st + seg_tree[2 * v].rzm * seg_tree[v].d;
    seg_tree[2 * v + 1].d += seg_tree[v].d;
    seg_tree[v].st = seg_tree[v].d = 0;
  }
}
void build(int l, int r, int v) {
  seg_tree[v].rzm = r - l + 1;
  if (l == r) return;
  int m = (l + r) / 2;
  build(l, m, 2 * v);
  build(m + 1, r, 2 * v + 1);
}
void update(int l, int r, int tl, int tr, int v, long long start,
            long long dist) {
  if (l == tl && r == tr) {
    seg_tree[v].st += start;
    seg_tree[v].d += dist;
    return;
  }
  push(v);
  int m = (l + r) / 2;
  if (tr <= m)
    update(l, m, tl, tr, 2 * v, start, dist);
  else if (tl > m)
    update(m + 1, r, tl, tr, 2 * v + 1, start, dist);
  else {
    update(l, m, tl, m, 2 * v, start, dist);
    update(m + 1, r, m + 1, tr, 2 * v + 1, start + dist * (m - tl + 1), dist);
  }
}
long long get(int l, int r, int v, int pos) {
  if (l == r) return seg_tree[v].st;
  push(v);
  int m = (l + r) / 2;
  if (pos <= m)
    return get(l, m, 2 * v, pos);
  else
    return get(m + 1, r, 2 * v + 1, pos);
}
void update1(int l, int r, int v, int pos) {
  if (l == r) {
    new_st[v].first += l;
    new_st[v].second++;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m)
    update1(l, m, 2 * v, pos);
  else
    update1(m + 1, r, 2 * v + 1, pos);
  new_st[v].first = new_st[2 * v].first + new_st[2 * v + 1].first;
  new_st[v].second = new_st[2 * v].second + new_st[2 * v + 1].second;
}
pair<long long, long long> get1(int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) return new_st[v];
  int m = (l + r) / 2;
  if (tr <= m)
    return get1(l, m, tl, tr, 2 * v);
  else if (tl > m)
    return get1(m + 1, r, tl, tr, 2 * v + 1);
  else {
    pair<long long, long long> x = get1(l, m, tl, m, 2 * v);
    pair<long long, long long> y = get1(m + 1, r, m + 1, tr, 2 * v + 1);
    return {x.first + y.first, x.second + y.second};
  }
}
int main() {
  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
  int n, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  build(1, lim, 1);
  for (i = 1; i <= n; i++) {
    ans[i] = get1(1, lim, a[i], lim, 1).second * a[i] + get(1, lim, 1, a[i]) +
             get1(1, lim, 1, a[i], 1).first;
    if (a[i] > 1) {
      long long diff = 1;
      for (j = a[i] + 1; j <= lim; j += a[i], diff++) {
        pair<long long, long long> info =
            get1(1, lim, j, min(lim, j + a[i] - 2), 1);
        ans[i] += info.first - info.second * diff * a[i];
        update(1, lim, j, min(lim, j + a[i] - 2), 1, 1, 1);
      }
    }
    update1(1, lim, 1, a[i]);
  }
  for (i = 1; i <= n; i++) ans[i] += ans[i - 1];
  for (i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
