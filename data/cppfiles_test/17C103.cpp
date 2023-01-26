#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0, 0, 0};
class segment {
 public:
  long long n;
  vector<long long> t;
  segment(long long x) {
    n = x;
    t.resize(4 * n, 0);
  }
  long long query(long long v, long long tl, long long tr, long long l,
                  long long r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
      return t[v];
    }
    long long tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  long long query(long long l, long long r) { return query(1, 0, n - 1, l, r); }
  void update(long long v, long long tl, long long tr, long long pos) {
    if (tl == tr) {
      t[v]++;
    } else {
      long long tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v * 2, tl, tm, pos);
      else
        update(v * 2 + 1, tm + 1, tr, pos);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a.push_back(x);
    }
    vector<long long> d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
      a[i] = (lower_bound(d.begin(), d.end(), a[i]) - d.begin()) + 1;
    }
    segment ob(d.size() + 1);
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
      long long sm = ob.query(0, a[i] - 1);
      long long gr = ob.query(a[i] + 1, d.size());
      ans += min(sm, gr);
      ob.update(1, 0, d.size(), a[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
