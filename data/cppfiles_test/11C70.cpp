#include <bits/stdc++.h>
using namespace std;
const long long dim = 200009, inf = 1e9;
struct AINT {
  long long aint[4 * dim];
  void update(long long nod, long long tl, long long tr, long long pos,
              long long val) {
    if (tl == tr) {
      aint[nod] = max(aint[nod], val);
      return;
    }
    long long tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * nod, tl, tm, pos, val);
    else
      update(2 * nod + 1, tm + 1, tr, pos, val);
    aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
  }
  long long query(long long nod, long long tl, long long tr, long long l,
                  long long r) {
    if (tl == l && tr == r) {
      return aint[nod];
    }
    long long tm = (tl + tr) / 2;
    if (r <= tm) return query(2 * nod, tl, tm, l, r);
    if (l > tm) return query(2 * nod + 1, tm + 1, tr, l, r);
    return max(query(2 * nod, tl, tm, l, tm),
               query(2 * nod + 1, tm + 1, tr, tm + 1, r));
  }
} aint;
struct elem {
  long long val, diff;
  bool operator<(const elem x) const {
    if (val == x.val) return diff > x.diff;
    return val < x.val;
  }
};
vector<elem> p;
long long n, v[dim], ans;
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
    if (v[i] <= i) {
      p.push_back({v[i], i - v[i] + 1});
    }
  }
  sort(p.begin(), p.end());
  for (auto it : p) {
    long long nr = it.diff;
    long long val = aint.query(1, 1, n, 1, nr);
    ans = max(ans, val + 1);
    aint.update(1, 1, n, nr, val + 1);
  }
  cout << ans;
}
