#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct fenwick {
  vector<vector<T>> a;
  int n;
  fenwick(int n) : n(n), a(2, vector<T>(n)) {}
  void add(int x, int p, T v) {
    assert(0 <= x && x < n);
    for (int i = x + 1; i <= n; i += i & -i) a[p][i - 1] += v;
  }
  T qry(int p, int x) {
    T ret = 0;
    for (int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[p][i - 1];
    return ret;
  }
  int qry2() {
    int lg = 31 - __builtin_clz(n), pos = 0, s1 = qry(1, n - 1), ls = 0, rs = 0;
    for (int i = 1 << lg; i; i >>= 1) {
      if (pos + i <= n &&
          ls + a[0][pos + i - 1] <= s1 - rs - a[1][pos + i - 1]) {
        ls += a[0][pos + i - 1];
        rs += a[1][pos + i - 1];
        pos += i;
      }
    }
    int ret = min(ls, s1 - rs);
    if (pos < n) {
      ret = max(ret, min(qry(0, pos), s1 - qry(1, pos)));
    }
    return ret;
  }
};
struct node {
  int x, y, c;
  bool operator<(const node& n) const { return x < n.x; }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<node> a(n);
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].c;
    a[i].c -= 1;
    b.push_back(a[i].x);
    b.push_back(a[i].y);
  }
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  for (int i = 0; i < n; ++i) {
    a[i].x = lower_bound(b.begin(), b.end(), a[i].x) - b.begin();
    a[i].y = lower_bound(b.begin(), b.end(), a[i].y) - b.begin();
  }
  int m = b.size(), ret = 0;
  for (int qaq = 0; qaq < 2; ++qaq) {
    sort(a.begin(), a.end());
    for (int c1 = 0; c1 < 3; ++c1) {
      int c2 = (c1 + 1) % 3, c3 = (c2 + 1) % 3;
      for (int qwq = 0; qwq < 2; ++qwq, swap(c2, c3)) {
        assert(c1 != c2 && c2 != c3 && c1 != c3);
        fenwick<int> fx(m), fy(m);
        for (int i = 0; i < n; ++i) {
          if (a[i].c != c1) {
            fx.add(a[i].x, a[i].c == c2, 1);
            fy.add(a[i].y, a[i].c == c2, 1);
          }
        }
        int cnt1 = 0;
        for (int i = 0; i < n;) {
          int j = i;
          while (j < n && a[i].x == a[j].x) {
            if (a[j].c != c1) {
              fx.add(a[j].x, a[j].c == c2, -1);
              fy.add(a[j].y, a[j].c == c2, -1);
            }
            cnt1 += a[j].c == c1;
            ++j;
          }
          ret = max(ret, min(cnt1, fx.qry2()));
          ret = max(ret, min(cnt1, fy.qry2()));
          i = j;
        }
      }
    }
    for (int i = 0; i < n; ++i) swap(a[i].x, a[i].y);
  }
  cout << ret * 3 << '\n';
}
