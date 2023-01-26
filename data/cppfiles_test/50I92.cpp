#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, lg = 30, mod = 998244353;
const int maxseg = 4 * maxn * lg;
int child[maxseg][2], seg[maxseg], lazy[maxseg], rv[maxseg];
int newint = 2;
int n = 1e9;
void shift(int id, int l, int r);
void f(int id) {
  if (!child[id][0]) child[id][0] = newint++;
  if (!child[id][1]) child[id][1] = newint++;
}
void changelz(int id, int l, int r, int lq, int rq, int x) {
  if (lq >= r || rq <= l) return;
  if (lq <= l && rq >= r) {
    seg[id] = (seg[id] + 1LL * (r - l) * x) % mod;
    if (rv[id]) {
      lazy[id] = (lazy[id] - x + mod) % mod;
    } else {
      lazy[id] = (lazy[id] + x) % mod;
    }
    return;
  }
  f(id);
  shift(id, l, r);
  int mid = (l + r) / 2;
  changelz(child[id][0], l, mid, lq, rq, x);
  changelz(child[id][1], mid, r, lq, rq, x);
  seg[id] = (seg[child[id][0]] + seg[child[id][1]]) % mod;
}
void changerv(int id, int l, int r, int lq, int rq) {
  if (lq >= r || rq <= l) return;
  if (lq <= l && rq >= r) {
    seg[id] = (-seg[id] + mod) % mod;
    rv[id] ^= 1;
    return;
  }
  f(id);
  shift(id, l, r);
  int mid = (l + r) / 2;
  changerv(child[id][0], l, mid, lq, rq);
  changerv(child[id][1], mid, r, lq, rq);
  seg[id] = (seg[child[id][0]] + seg[child[id][1]]) % mod;
}
void shift(int id, int l, int r) {
  int mid = (l + r) / 2;
  changelz(child[id][0], l, mid, 1, n + 1, lazy[id]);
  changelz(child[id][1], mid, r, 1, n + 1, lazy[id]);
  if (!rv[id]) return;
  changerv(child[id][0], l, mid, 1, n + 1);
  changerv(child[id][1], mid, r, 1, n + 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int m;
  cin >> m;
  int last = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    int tmp = seg[1];
    if (!i) tmp = 1;
    if (i) changerv(1, 1, n + 1, 1, min(last, x) + 1);
    changelz(1, 1, n + 1, 1, x + 1, tmp);
    last = x;
  }
  cout << seg[1];
  return 0;
}
