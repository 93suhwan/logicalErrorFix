#include <bits/stdc++.h>
using namespace std;
const long long INF = 2147483647;
const long long LNF = INF * INF;
const long long MOD = 1000000007;
const long long mod = 998244353;
const long double eps = 1e-12;
const long long MAX = 200010;
long long n, m;
pair<long long, long long> op[MAX];
long long fac[2 * MAX];
long long fpow(long long x, long long p) {
  if (p == 0) return 1;
  if (p % 2) return (x * fpow(x, p - 1)) % mod;
  long long tmp = fpow(x, p / 2);
  return (tmp * tmp) % mod;
}
long long inv(long long x) { return fpow(x, mod - 2); }
struct Treap {
  Treap *l, *r;
  long long pri;
  pair<long long, long long> seg;
  long long tag;
  Treap(long long _L, long long _R)
      : l(nullptr), r(nullptr), pri(rand()), seg(make_pair(_L, _R)), tag(0) {}
};
Treap *treap = nullptr;
long long treap_sz;
void push(Treap *&T) {
  if (T == nullptr) return;
  T->seg.first += T->tag;
  T->seg.second += T->tag;
  if (T->l != nullptr) T->l->tag += T->tag;
  if (T->r != nullptr) T->r->tag += T->tag;
  T->tag = 0;
}
Treap *Merge(Treap *a, Treap *b) {
  if (a == nullptr) return b;
  if (b == nullptr) return a;
  if (a->pri < b->pri) {
    push(a);
    a->r = Merge(a->r, b);
    return a;
  } else {
    push(b);
    b->l = Merge(a, b->l);
    return b;
  }
}
void Split_by_L(Treap *T, Treap *&a, Treap *&b, long long k) {
  if (T == nullptr) {
    a = b = nullptr;
    return;
  }
  push(T);
  if (T->seg.first <= k) {
    a = T;
    Split_by_L(a->r, a->r, b, k);
  } else {
    b = T;
    Split_by_L(b->l, a, b->l, k);
  }
}
Treap *&Last(Treap *&T) {
  if (T == nullptr) return T;
  push(T);
  if (T->r == nullptr) return T;
  return Last(T->r);
}
void Insertion_sort(Treap *&T, long long pos) {
  if (pos == 1) {
    T->tag += 1;
    T = Merge(new Treap(1, 1), T);
    treap_sz += 1;
    return;
  }
  Treap *a, *b, *c;
  Split_by_L(T, a, b, pos - 1);
  Treap *&Node = Last(a);
  if (Node->seg.second > pos - 1) {
    c = new Treap(pos + 1, Node->seg.second + 1);
    treap_sz += 1;
    Node->seg.second = pos;
  } else {
    c = nullptr;
    Node->seg.second = pos;
  }
  if (b != nullptr) b->tag += 1;
  T = Merge(Merge(a, c), b);
}
void debug(Treap *&T) {
  if (T == nullptr) return;
  debug(T->l);
  cerr << "[" << T->seg.first << ", " << T->seg.second << "] ";
  debug(T->r);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fac[0] = 1;
  for (long long i = (1); i <= (2 * MAX - 1); i += (1)) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  long long Q;
  cin >> Q;
  while (Q--) {
    cin >> n >> m;
    for (long long i = (1); i <= (m); i += (1)) {
      cin >> op[i].first >> op[i].second;
    }
    treap = new Treap(1, 1);
    treap_sz = 1;
    for (long long i = (1); i <= (m); i += (1)) {
      Treap *&Node = Last(treap);
      Node->seg.second = op[i].first - 1;
      Insertion_sort(treap, op[i].second);
    }
    long long leq = n - treap_sz;
    long long res =
        (((fac[n + leq] * inv(fac[n])) % mod) * inv(fac[leq])) % mod;
    cout << res << '\n';
  }
  return 0;
}
