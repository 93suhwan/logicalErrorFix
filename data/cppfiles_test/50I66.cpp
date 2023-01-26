#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
using namespace std;
const long long inf = 1e9 + 228;
const long long infll = 1e18;
const long long mod = 1e9 + 7;
const long double eps = 1e-9;
const long long mod2 = 998244353;
const long double PI = atan2l(0, -1);
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
struct node {
  node *l = nullptr, *r = nullptr;
  long long x = 0;
  long long cnt = 0;
  bool zero = false;
  long long tl, tr;
  node(long long tl, long long tr) : tl(tl), tr(tr) {}
  void extend() {
    if (!l) {
      l = new node(tl, (tl + tr) / 2);
      r = new node((tl + tr) / 2 + 1, tr);
    }
  }
  void push() {
    extend();
    if (zero) {
      x = 0;
      l->zero = true;
      r->zero = true;
      l->cnt = 0;
      r->cnt = 0;
      zero = false;
    }
    if (cnt) {
      cnt %= mod2;
      cnt += mod2;
      cnt %= mod2;
      x += cnt * (tr - tl + 1);
      x %= mod2;
      if (x < 0) x += mod2;
      l->cnt += cnt;
      r->cnt += cnt;
      cnt = 0;
    }
  }
  void add(long long ql, long long qr, long long k) {
    if (ql <= tl && tr <= qr) {
      cnt += k;
      push();
    } else if (tl > qr || ql > tr) {
      return;
    } else {
      extend();
      l->add(ql, qr, k);
      r->add(ql, qr, k);
      x = l->x + r->x;
      x %= mod2;
      x += mod2;
      x %= mod2;
    }
  }
  long long get(long long ql, long long qr) {
    push();
    if (ql <= tl && tr <= qr) {
      return x;
    } else if (tl > qr || ql > tr) {
      return 0;
    } else {
      extend();
      long long ans = l->get(ql, qr) + r->get(ql, qr);
      ans %= mod2;
      ans += mod2;
      ans %= mod2;
      return ans;
    }
  }
  void make_zero(long long ql, long long qr) {
    push();
    if (ql <= tl && tr <= qr) {
      zero = true;
      push();
    } else if (tl > qr || ql > tr) {
      return;
    } else {
      extend();
      l->make_zero(ql, qr);
      r->make_zero(ql, qr);
      x = l->x + r->x;
      x %= mod2;
      x += mod2;
      x %= mod2;
    }
  }
};
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long &i : a) cin >> i;
  node *t = new node(0, 1e9 + 228);
  t->add(1, a[0], 1);
  for (long long i = 1; i < n; i++) {
    long long sum = t->x;
    t->add(1, a[i], -sum);
    t->make_zero(a[i] + 1, 1e9);
  }
  if (n % 2 == 0) {
    long long ans = t->x;
    ans = -ans;
    ans %= mod2;
    ans += mod2;
    ans %= mod2;
    cout << ans << '\n';
  } else {
    cout << t->x << '\n';
  }
}
signed main() {
  fast_io();
  srand(time(NULL));
  long long q = 1;
  while (q--) solve();
}
