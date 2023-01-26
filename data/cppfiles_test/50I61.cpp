#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265359;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long randint(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(rng);
}
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
void print(vector<long long> v) {
  cout << "[";
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i + 1 != v.size()) cout << ", ";
  }
  cout << "]" << endl;
}
void print(pair<long long, long long> p) {
  cout << "{" << p.first << ", " << p.second << "}" << endl;
}
struct Node {
  long long l, r, val;
  pair<long long, long long> lazy;
  Node() {}
  Node(long long a, long long b, long long c, pair<long long, long long> d) {
    l = a;
    r = b;
    val = c;
    lazy = d;
  }
};
const long long MOD = 998244353;
const long long maxn = 1e9 + 10;
template <long long MAXV>
struct ImplicitSegTree {
  Node segtree[64 * MAXV];
  long long index = 0;
  const long long beg = 0;
  const long long en = maxn;
  pair<long long, long long> lazyneutro;
  long long neutro;
  ImplicitSegTree(long long neu) {
    lazyneutro = make_pair(-2, -2);
    neutro = neu;
    segtree[index] = Node(-1, -1, 0, lazyneutro);
    index++;
  }
  pair<long long, long long> lazyop(pair<long long, long long> a,
                                    pair<long long, long long> b) {
    if (a == lazyneutro) return b;
    if (b == lazyneutro) return a;
    return make_pair((a.first * b.first) % MOD,
                     (a.first * b.second + a.second) % MOD);
  }
  long long op(long long a, long long b) { return (a + b) % MOD; }
  void applylazyatnode(long long u, long long l, long long r) {
    if (segtree[u].lazy != lazyneutro) {
      segtree[u].val = ((r - l) * segtree[u].lazy.second) % MOD +
                       (segtree[u].lazy.first * segtree[u].val) % MOD;
      segtree[u].val %= MOD;
    }
    segtree[u].lazy = lazyneutro;
  }
  void createchilds(long long u) {
    if (segtree[u].l == -1) {
      segtree[u].l = index;
      segtree[index] = Node(-1, -1, 0, lazyneutro);
      index++;
    }
    if (segtree[u].r == -1) {
      segtree[u].r = index;
      segtree[index] = Node(-1, -1, 0, lazyneutro);
      index++;
    }
  }
  void pushlazy(long long u, long long l, long long r) {
    if ((r - l) != 1) {
      createchilds(u);
      segtree[segtree[u].l].lazy =
          lazyop(segtree[u].lazy, segtree[segtree[u].l].lazy);
      segtree[segtree[u].r].lazy =
          lazyop(segtree[u].lazy, segtree[segtree[u].r].lazy);
    }
    if (segtree[u].lazy != lazyneutro) applylazyatnode(u, l, r);
  }
  long long query(long long x, long long lx, long long rx, long long l,
                  long long r) {
    pushlazy(x, lx, rx);
    if (l <= lx && rx <= r) {
      return segtree[x].val;
    }
    if (lx >= r || rx <= l) return neutro;
    long long mid = lx + (rx - lx) / 2;
    return op(query(segtree[x].l, lx, mid, l, r),
              query(segtree[x].r, mid, rx, l, r));
  }
  long long query(long long l, long long r) { return query(0, beg, en, l, r); }
  void update(long long x, long long lx, long long rx, long long l, long long r,
              pair<long long, long long> val) {
    pushlazy(x, lx, rx);
    if (lx >= r || rx <= l) return;
    if (lx >= l && rx <= r) {
      segtree[x].lazy = lazyop(val, segtree[x].lazy);
      pushlazy(x, lx, rx);
      return;
    }
    long long mid = lx + (rx - lx) / 2;
    update(segtree[x].l, lx, mid, l, r, val);
    update(segtree[x].r, mid, rx, l, r, val);
    segtree[x].val = op(segtree[segtree[x].l].val, segtree[segtree[x].r].val);
  }
  void update(long long l, long long r, pair<long long, long long> val) {
    update(0, beg, en, l, r, val);
  }
};
ImplicitSegTree<100000> seg(0);
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if (i == 0) {
      seg.update(1, a + 1, make_pair(0, 1));
    } else {
      seg.update(1, a + 1, make_pair(-1, seg.query(0, maxn)));
      seg.update(a + 1, maxn, make_pair(0, 0));
    }
  }
  cout << (seg.query(0, maxn) + MOD) % MOD << '\n';
}
