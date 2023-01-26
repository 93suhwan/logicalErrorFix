#include <bits/stdc++.h>
using namespace std;
struct SegmentTree {
  long long n;
  vector<long long> t;
  void init(long long n) {
    this->n = n;
    t.resize(4 * n, 0);
  }
  void build(vector<long long>& a, long long v, long long tl, long long tr) {
    if (tl == tr) {
      t[v] = a[tl];
    } else {
      long long tm = (tl + tr) / 2;
      build(a, 2 * v, tl, tm);
      build(a, 2 * v + 1, tm + 1, tr);
      t[v] = t[2 * v] + t[2 * v + 1];
    }
  }
  long long sum(long long v, long long tl, long long tr, long long l,
                long long r) {
    if (l > r) {
      return 0;
    }
    if (l == tl && r == tr) {
      return t[v];
    }
    long long tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, min(r, tm)) +
           sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  void update(long long v, long long tl, long long tr, long long pos,
              long long new_val) {
    if (tl == tr) {
      t[v] = new_val;
    } else {
      long long tm = (tl + tr) / 2;
      if (pos <= tm) {
        update(2 * v, tl, tm, pos, new_val);
      } else {
        update(2 * v + 1, tm + 1, tr, pos, new_val);
      }
      t[v] = t[2 * v] + t[2 * v + 1];
    }
  }
};
void TEST_CASE() {
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<long long> nor(n, 0), abnor(n, 0);
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (s[i] == '+') {
        nor[i] = 1;
        abnor[i] = -1;
      } else {
        nor[i] = -1;
        abnor[i] = 1;
      }
    } else {
      if (s[i] == '+') {
        nor[i] = -1;
        abnor[i] = 1;
      } else {
        nor[i] = 1;
        abnor[i] = -1;
      }
    }
  }
  SegmentTree f1, f2;
  f1.init(n);
  f2.init(n);
  f1.build(nor, 1, 0, n - 1);
  f2.build(abnor, 1, 0, n - 1);
  for (long long i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    if (l % 2 == 0) {
      long long tot = f1.sum(1, 0, n - 1, l, r);
      if (tot == 0) {
        cout << 0 << "\n";
      } else if ((r - l + 1) % 2) {
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    } else {
      long long tot = f2.sum(1, 0, n - 1, l, r);
      if (tot == 0) {
        cout << 0 << "\n";
      } else if ((r - l + 1) % 2) {
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    TEST_CASE();
  }
  return 0;
}
