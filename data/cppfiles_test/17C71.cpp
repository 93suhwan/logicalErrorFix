#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
long long power(long long x, long long y, long long M) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % M;
    y >>= 1;
    x = (x * x) % M;
  }
  return res % M;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y >>= 1;
    x = (x * x);
  }
  return res;
}
const long long mxn = 1e6 + 6, mod = 1e9 + 7, inf = 1e18;
long long t, casee = 1;
template <typename T>
class Segment_Tree {
 private:
  vector<T> arr;
  vector<T> seg_tree;
  long long N;
  long long def;

 public:
  Segment_Tree(vector<T> a, long long deff = 0) {
    N = a.size();
    def = deff;
    arr = a;
    seg_tree.resize(4 * N + 10, 0);
    build();
  }
  long long func(long long a, long long b) { return a + b; }
  void build() { build_it_for_me(0, N - 1, 1); }
  void build_it_for_me(long long lo, long long hi, long long pos) {
    assert(lo <= hi);
    if (lo == hi) {
      seg_tree[pos] = arr[lo];
      return;
    }
    long long mid = (lo + hi) / 2;
    build_it_for_me(lo, mid, 2 * pos);
    build_it_for_me(mid + 1, hi, 2 * pos + 1);
    seg_tree[pos] = func(seg_tree[2 * pos], seg_tree[2 * pos + 1]);
  }
  void update(long long ind, long long val) {
    update_it_for_me(ind, val, 0, N - 1, 1);
  }
  void update_it_for_me(long long ind, long long val, long long lo,
                        long long hi, long long pos) {
    if (lo == hi) {
      seg_tree[pos] = val;
      arr[ind] = val;
      return;
    }
    long long mid = (lo + hi) / 2;
    if (mid >= ind)
      update_it_for_me(ind, val, lo, mid, 2 * pos);
    else
      update_it_for_me(ind, val, mid + 1, hi, 2 * pos + 1);
    seg_tree[pos] = func(seg_tree[2 * pos], seg_tree[2 * pos + 1]);
  }
  T query(long long l, long long r) {
    return query_it_for_me(l, r, 1, 0, N - 1);
  }
  T query_it_for_me(long long l, long long r, long long pos, long long lo,
                    long long hi) {
    if (lo > r || hi < l) return def;
    if (lo >= l && hi <= r) return seg_tree[pos];
    long long mid = (lo + hi) / 2;
    return func(query_it_for_me(l, r, 2 * pos, lo, mid),
                query_it_for_me(l, r, 2 * pos + 1, mid + 1, hi));
  }
};
void test_case() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (long long i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
  map<long long, long long> mapped;
  sort((b).begin(), (b).end());
  long long curr = 0;
  for (long long i = 0; i < n; i++) {
    if (mapped.find(b[i]) == mapped.end()) {
      mapped[b[i]] = curr++;
    }
  }
  for (long long i = 0; i < n; i++) a[i] = mapped[a[i]];
  vector<long long> temp(curr + 10, 0);
  Segment_Tree<long long> bit(temp);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long left = bit.query(0, a[i] - 1);
    long long right = bit.query(a[i] + 1, curr + 5);
    ans += min(left, right);
    bit.update(a[i], bit.query(a[i], a[i]) + 1);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  cin >> t;
  while (t--) {
    test_case();
    casee++;
  }
  return 0;
}
