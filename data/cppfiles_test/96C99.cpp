#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
struct node {
  long long int sum = 0;
  node(long long int a) : sum(a) {}
};
class pointseg {
 private:
  int n;
  vector<node> t;
  vector<long long int> a;
  void upd(int v, int tl, int tr, int pos, node val) {
    if (tl == tr) {
      t[v] = val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(2 * v, tl, tm, pos, val);
    else
      upd(2 * v + 1, tm + 1, tr, pos, val);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
  }
  node query(int v, int l, int r, int tl, int tr) {
    if (l > r) return node(0);
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(query(2 * v, l, min(r, tm), tl, tm),
                 query(2 * v + 1, max(l, tm + 1), r, tm + 1, tr));
  }
  void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
  }

 public:
  node merge(node a, node b) { return node(a.sum + b.sum); }
  void upd(int pos, node val) { upd(1, 1, n, pos, val); }
  node query(int l, int r) { return query(1, l, r, 1, n); }
  void build() { build(1, 1, n); }
  pointseg(int _n, vector<long long int> _a = {}) {
    n = _n;
    t.assign(4 * n, node(0));
    a = _a;
  }
  pointseg() {}
} s;
long long int eval(long long int x) { return x * (x + 1) / 2; }
set<int> pos;
void change(int x) {
  auto it = pos.upper_bound(x);
  auto it2 = it;
  it2--;
  if (it != pos.end()) s.upd(*it, eval(*it - *it2));
  it = pos.lower_bound(x);
  it2 = it;
  it2--;
  s.upd(*it, eval(*it - *it2));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<long long int> a(n + 2);
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = -(long long int)(1e18);
  int last = 0;
  pos.insert(0);
  s = pointseg(n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i + 1]) {
      pos.insert(i);
      s.upd(i, eval(i - last));
      last = i;
    }
  }
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 2) {
      long long int ans = s.query(l, r).sum;
      if (ans == 0) {
        cout << eval(r - l + 1) << '\n';
        continue;
      }
      int k = *pos.lower_bound(l);
      ans -= s.query(k, k).sum;
      ans += eval(k - l + 1);
      if (a[r] <= a[r + 1]) {
        auto it = pos.lower_bound(r);
        it--;
        k = *it;
        ans += eval(r - k);
      }
      cout << ans << '\n';
    } else {
      int x = l;
      int y = r;
      a[x] = y;
      pos.erase(x);
      s.upd(x, 0);
      if (x > 1) {
        s.upd(x - 1, 0);
        pos.erase(x - 1);
      }
      if (a[x] > a[x + 1]) pos.insert(x);
      if (x > 1 && a[x - 1] > a[x]) pos.insert(x - 1);
      change(x);
      if (x > 1) change(x - 1);
    }
  }
}
