#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 8, inf = 1e9, mod = 998244353;
const long long mod2 = (long long)mod * mod;
int n;
int a[N];
struct Node {
  Node *l, *r;
  bool laz;
  long long la2, val;
  Node() : l(NULL), r(NULL), laz(false), la2(0), val(0) {}
  void down() {
    if (laz) {
      l->laz ^= 1;
      r->laz ^= 1;
      l->val = -l->val;
      r->val = -r->val;
      laz = false;
    }
    if (la2) {
      l->la2 += la2;
      r->la2 += la2;
      l->val += la2;
      r->val += la2;
      la2 = 0;
    }
  }
} * root(new Node());
void upd(Node *u, int l, int r, int a, int b, long long v) {
  if (b < l || r < a) return;
  if (a <= l && r <= b) {
    if (~v) {
      u->val += v * (r - l + 1) % mod;
      u->la2 += v;
    } else {
      u->val = -u->val;
      u->laz ^= 1;
    }
    return;
  }
  if (!u->l) u->l = new Node();
  if (!u->r) u->r = new Node();
  u->down();
  int m = (l + r) >> 1;
  upd(u->l, l, m, a, b, v);
  upd(u->r, m + 1, r, a, b, v);
  u->val = u->l->val + u->r->val;
}
long long get(Node *u, int l, int r, int a, int b) {
  if (a <= l && r <= b) return u->val;
  if (b < l || r < a) return 0;
  if (!u->l) u->l = new Node();
  if (!u->r) u->r = new Node();
  u->down();
  int m = (l + r) >> 1;
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
    upd(root, 1, inf, 1, inf, sum[i - 1]);
    sum[i] = (a[i] * sum[i - 1] - get(root, 1, inf, 1, a[i]) + mod2) % mod;
  }
  cout << sum[n] << '\n';
}
