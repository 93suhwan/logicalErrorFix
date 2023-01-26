#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void init_code() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
template <class T>
class SegmentTreeCount {
  vector<vector<T>> t;
  long long maxn = 1000000;
  void build(const vector<T> &a, long long v, long long tl, long long tr) {
    if (tl == tr) {
      t[v] = vector<T>(1, a[tl]);
    } else {
      long long tm = (tl + tr) / 2;
      build(a, v * 2 + 1, tl, tm);
      build(a, v * 2 + 2, tm + 1, tr);
      merge(t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v * 2 + 2].begin(),
            t[v * 2 + 2].end(), back_inserter(t[v]));
    }
  }
  long long query(long long v, long long tl, long long tr, long long l,
                  long long r, long long x) const {
    if (l > r) return 0;
    if (l == tl && tr == r) {
      auto pos = lower_bound(t[v].begin(), t[v].end(), x);
      return pos - t[v].begin();
    }
    long long tm = (tl + tr) / 2;
    return query(v * 2 + 1, tl, tm, l, min(r, tm), x) +
           query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r, x);
  }
  inline long long query(long long l, long long r, long long x) const {
    return query(0, 0, maxn - 1, l, r, x);
  }

 public:
  SegmentTreeCount(const vector<T> &v) {
    maxn = v.size();
    t.resize(4 * maxn);
    build(v, 0, 0, maxn - 1);
  }
  inline long long lower(long long l, long long r, long long x) const {
    return query(l, r, x);
  }
  inline long long great_eq(long long l, long long r, long long x) const {
    return r - l + 1 - query(l, r, x);
  }
  inline long long lower_eq(long long l, long long r, long long x) const {
    return query(l, r, x + 1);
  }
  inline long long greater(long long l, long long r, long long x) const {
    return r - l + 1 - query(l, r, x + 1);
  }
  inline long long equal(long long l, long long r, long long x) const {
    return lower_eq(l, r, x) - lower(l, r, x);
  }
  inline long long in_range(long long l, long long r, long long x1,
                            long long x2) const {
    return lower_eq(l, r, x2) - lower(l, r, x1);
  }
};
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  SegmentTreeCount<long long> s(a);
  for (long long i = 1; i < n; i++) {
    ans += min(s.lower(0, i - 1, a[i]), s.greater(0, i - 1, a[i]));
  }
  cout << ans << "\n";
}
signed main() {
  init_code();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
