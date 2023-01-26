#include <bits/stdc++.h>
using namespace std;
const int md = 998244353;
struct lzT {
  long long add;
  int mul;
};
struct Node {
  long long res = 0;
  lzT lz = {0, 1};
  int hi, lo;
  Node *L, *R;
  Node(int _lo, int _hi) : lo(_lo), hi(_hi) { L = R = nullptr; }
  void extend() {
    if (L or R or lo == hi) return;
    int mid = (lo + hi) / 2;
    L = new Node(lo, mid);
    R = new Node(mid + 1, hi);
  }
  lzT combLz(lzT a, lzT b) {
    return {(a.mul * b.add + a.add + md) % md, a.mul * b.mul};
  }
  long long applyLz() {
    return (res * lz.mul + lz.add * (hi - lo + 1) + md) % md;
  }
  void push() {
    res = applyLz();
    if (lo != hi) {
      L->lz = combLz(lz, L->lz);
      R->lz = combLz(lz, R->lz);
    }
    lz = {0, 1};
  }
  void upd(int ql, int qr, lzT val) {
    if (lo > qr or hi < ql) return;
    if (lo >= ql and hi <= qr) {
      lz = combLz(val, lz);
      return;
    }
    extend();
    push();
    L->upd(ql, qr, val);
    R->upd(ql, qr, val);
    res = (L->applyLz() + R->applyLz()) % md;
  }
  long long qry(int ql, int qr) {
    if (lo > qr or hi < ql) return {};
    if (lo >= ql and hi <= qr) return applyLz();
    extend();
    push();
    return (L->qry(ql, qr) + R->qry(ql, qr)) % md;
  }
};
Node* seg = new Node(0, 1e9);
int main() {
  int n;
  cin >> n;
  for (int i = 0, num; i < n; i++) {
    cin >> num;
    if (!i)
      seg->upd(1, num, {1, 1});
    else {
      long long sm = seg->qry(1, 1e9);
      seg->upd(1, num, {sm, -1});
      seg->upd(num + 1, 1e9, {0, 0});
    }
  }
  cout << seg->qry(1, 1e9) << endl;
}
