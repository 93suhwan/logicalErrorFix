#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long bp(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2) res = (res * a) % 998244353;
    a = (a * a) % 998244353;
    b /= 2;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
const long long inf = 1e18;
struct Node {
  Node *l = 0, *r = 0;
  long long lo, hi, mset = inf, madd = 0, val = inf + inf;
  Node(long long lo, long long hi) : lo(lo), hi(hi) {}
  Node(vector<long long>& v, long long lo, long long hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      long long mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = max(l->val, r->val);
    } else
      val = v[lo];
  }
  long long query(long long L, long long R) {
    if (R <= lo || hi <= L) return -inf;
    if (L <= lo && hi <= R) return val;
    push();
    return max(l->query(L, R), r->query(L, R));
  }
  void set(long long L, long long R, long long x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (val < x) return;
      mset = val = x, madd = 0;
    } else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = max(l->val, r->val);
    }
  }
  void add(long long L, long long R, long long x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (mset != inf)
        mset += x;
      else
        madd += x;
      val += x;
    } else {
      push(), l->add(L, R, x), r->add(L, R, x);
      val = max(l->val, r->val);
    }
  }
  void push() {
    if (!l) {
      long long mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset != inf)
      l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
    else if (madd)
      l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1], b[n + 1];
    for (long long x = 1; x <= n; x++) cin >> a[x];
    for (long long x = 1; x <= n; x++) cin >> b[x];
    vector<long long> ar[n + 1];
    for (long long x = 1; x <= n; x++) {
      ar[x + b[x]].push_back(x);
    }
    ar[n].push_back(n);
    long long e = 1e9 + 1;
    Node seg(0, n + 1);
    long long pa[n + 1];
    long long gu[n + 1];
    memset(pa, -1, sizeof(pa));
    seg.set(n, n + 1, n);
    set<long long> vis;
    for (long long x = 0; x <= n; x++) vis.insert(-x);
    for (long long c = 0; c < 7; c++) {
      queue<long long> aq;
      for (auto i : vis) {
        long long x = -i;
        pair<long long, long long> g = make_pair(inf, -1ll);
        for (auto i : ar[x]) {
          g = min(g, make_pair(seg.query(i, i + 1), i));
        }
        long long f = g.first / e;
        long long p = g.first % e;
        gu[x] = g.second;
        pa[x] = p;
        if (f < 1e8) aq.push(i);
        if (x > 0 && f < 1e8) seg.set(x - a[x], x + 1, ((f + 1) * e) + x);
      }
      while (!aq.empty()) {
        vis.erase(aq.front());
        aq.pop();
      }
    }
    long long f = seg.query(0, 1);
    if ((f / e) > 1e8) {
      cout << -1 << '\n';
      return 0;
    }
    cout << f / e << '\n';
    long long g = f % e;
    vector<long long> as;
    as.push_back(0);
    while (pa[g] != g) {
      as.push_back(gu[g]);
      g = pa[g];
    }
    reverse(as.begin(), as.end());
    for (auto i : as) cout << i << ' ';
    cout << '\n';
  }
}
