#include <bits/stdc++.h>
using namespace std;
int mlt(int x, int y) { return 1ll * x * y % long long(998244353); }
int binpow(int x, int y) {
  if (y == 0) return 1;
  int s = binpow(x, y >> 1);
  s = mlt(s, s);
  if (y & 1) s = mlt(s, x);
  return s;
}
int fact[100500 + 100500];
int C(int n, int k) {
  return mlt(fact[n],
             binpow(mlt(fact[n - k], fact[k]), long long(998244353) - 2));
}
struct node {
  node *l, *r;
  int kol, id;
  node() : l(nullptr), r(nullptr) {}
  node(int _kol) : l(nullptr), r(nullptr), kol(_kol), id(-1) {}
};
int glob;
void maker_left(node &v, int s) {
  if (v.l == nullptr) {
    v.l = new node((v.kol + 1) / 2);
    if (v.l->kol == 1) v.l->id = s + 1;
  }
}
void maker_right(node &v, int s) {
  int sk = (v.kol + 1) / 2;
  if (v.l != nullptr) sk = v.l->kol;
  if (v.r == nullptr) {
    v.r = new node(v.kol / 2);
    if (v.r->kol == 1) v.r->id = s + sk + 1;
  }
}
int who(node v, int ps, int s) {
  if (v.kol == 1) return v.id;
  int sk = (v.kol + 1) / 2;
  if (v.l != nullptr) sk = v.l->kol;
  if (sk >= ps) {
    maker_left(v, s);
    return who(*v.l, ps, s);
  } else {
    maker_right(v, s);
    return who(*v.r, ps - sk, s + sk);
  }
}
void del(node v, int ps, int s) {
  if (v.kol == 1) {
    glob = v.id;
    return;
  }
  int sk = (v.kol + 1) / 2;
  if (v.l != nullptr) sk = v.l->kol;
  if (sk >= ps) {
    maker_left(v, s);
    del(*v.l, ps, s);
    v.l->kol--;
  } else {
    maker_right(v, s);
    del(*v.r, ps - sk, s + sk);
    v.r->kol--;
  }
}
void add(node &v, int ps, int id, int s) {
  if (v.kol == 1) {
    int idr = v.id;
    v = *(new node(2));
    v.l = new node(1);
    v.l->id = id;
    v.r = new node(1);
    v.r->id = idr;
    return;
  }
  int sk = (v.kol + 1) / 2;
  if (v.l != nullptr) sk = v.l->kol;
  if (sk >= ps) {
    maker_left(v, s);
    add(*v.l, ps, id, s);
    v.kol++;
  } else {
    maker_right(v, s);
    add(*v.r, ps - sk, id, s + sk);
    v.kol++;
  }
}
node *root;
int main() {
  ios_base::sync_with_stdio(0);
  istream::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  for (int i = 1; i < 100500 + 100500; i++) fact[i] = mlt(fact[i - 1], i);
  int q;
  cin >> q;
  for (; q; q--) {
    int n, m;
    cin >> n >> m;
    int c = 0;
    set<int> se;
    se.clear();
    root = new node(n);
    for (; m; m--) {
      int x, y;
      cin >> y >> x;
      int id = who(*root, x, 0);
      se.insert(id);
      del(*root, y, 0);
      add(*root, x, glob, 0);
    }
    c = int(se.size());
    cout << C(n + n - 1 - c, n) << endl;
  }
}
