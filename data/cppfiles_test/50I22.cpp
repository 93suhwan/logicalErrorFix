#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const long long infll = (long long)1e18 + 228;
const int inf = 1e9 + 228;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const int MAXA = 1e9;
struct Node {
  pair<int, int> add = make_pair(1, 0);
  int val = 0;
  Node *l, *r;
};
void apply(pair<int, int> &a, pair<int, int> b) {
  a = make_pair((long long)a.first * (long long)b.first % mod,
                ((long long)a.second * (long long)b.first + b.second) % mod);
}
void push(Node *v, int vl, int vr) {
  v->val = ((long long)v->val * (long long)v->add.first +
            (long long)v->add.second * (long long)(vr - vl + 1)) %
           mod;
  if (v->l != nullptr) {
    apply(v->l->add, v->add);
  }
  if (v->r != nullptr) {
    apply(v->r->add, v->add);
  }
  v->add = make_pair(1, 0);
}
void upd(Node *v, int vl, int vr, int ql, int qr, pair<int, int> val) {
  if (ql <= vl && vr <= qr) {
    apply(v->add, val);
    push(v, vl, vr);
  } else if (vl > qr || ql > vr) {
    return;
  } else {
    int vm = (vl + vr) / 2;
    if (v->l == nullptr) {
      v->l = new Node();
    }
    if (v->r == nullptr) {
      v->r = new Node();
    }
    upd(v->l, vl, vm, ql, qr, val);
    upd(v->r, vm + 1, vr, ql, qr, val);
    v->val = (v->l->val + v->r->val) % mod;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  Node *v = new Node();
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (i == 0) {
      upd(v, 1, MAXA, 1, x, make_pair(1, 1));
    } else {
      int sm = v->val;
      upd(v, 1, MAXA, 1, x, make_pair(-1, sm));
      upd(v, 1, MAXA, x + 1, MAXA, make_pair(0, 0));
    }
  }
  cout << v->val << '\n';
}
