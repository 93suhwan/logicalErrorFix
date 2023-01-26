#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 8, inf = 1e9 + 7, mod = 998244353;
const long long mod2 = (long long)mod * mod;
int n;
int a[N];
struct Node {
  Node *l, *r;
  int len;
  bool laz;
  long long la2, val;
  Node(int len) : l(NULL), r(NULL), len(len), laz(false), la2(0), val(0) {}
  void upd() {
    laz ^= 1;
    la2 = mod - la2;
    val = mod - val;
  }
  void upd(long long v) {
    la2 += v;
    if (la2 >= mod) la2 -= mod;
    (val += v * len) %= mod;
  }
  void down() {
    if (laz) {
      l->upd();
      r->upd();
      laz = false;
    }
    if (la2) {
      l->upd(la2);
      r->upd(la2);
      la2 = 0;
    }
  }
} * root(new Node(inf));
void upd(Node *u, int l, int r, int a, int b, long long v) {
  if (b < l || r < a) return;
  if (a <= l && r <= b) {
    if (~v)
      u->upd(v);
    else
      u->upd();
    return;
  }
  int m = (l + r) >> 1;
  if (!u->l) u->l = new Node(m - l + 1);
  if (!u->r) u->r = new Node(r - l);
  u->down();
  upd(u->l, l, m, a, b, v);
  upd(u->r, m + 1, r, a, b, v);
  u->val = (u->l->val + u->r->val) % mod;
}
long long get(Node *u, int l, int r, int a, int b) {
  if (a <= l && r <= b) return u->val;
  if (b < l || r < a) return 0;
  int m = (l + r) >> 1;
  if (!u->l) u->l = new Node(m - l + 1);
  if (!u->r) u->r = new Node(r - l);
  u->down();
  return get(u->l, l, m, a, b) + get(u->r, m + 1, r, a, b);
}
long long sum[N];
int main() {
  cin.tie(NULL)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  upd(root, 1, inf, 1, a[1], 1);
  sum[1] = root->val % mod;
  for (int i = 2; i <= n; ++i) {
    upd(root, 1, inf, 1, inf, -1);
    upd(root, 1, inf, 1, a[i], sum[i - 1]);
    sum[i] =
        (a[i] * sum[i - 1] - get(root, 1, inf, 1, min(a[i - 1], a[i])) + mod2) %
        mod;
  }
  cout << sum[n] << '\n';
}
