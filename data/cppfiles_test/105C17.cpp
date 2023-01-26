#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7, inf = 1e9 + 7;
struct node {
  int x, y, m, s, l, r, id, val;
  bool operator<(const node& a) const {
    if (s != a.s) return s < a.s;
    return r < a.r;
  }
};
inline void solve() {
  int n, cnt(0);
  cin >> n;
  vector<node> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].m;
    a[i].l = a[i].x - min(a[i].x, a[i].m),
    a[i].r = a[i].x - a[i].m + min(a[i].y, a[i].m);
    a[i].s = a[i].x + a[i].y - a[i].m;
    a[i].id = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0, j; i < n;) {
    j = i;
    while (j < n && a[j].s == a[i].s) ++j;
    int lim = -inf;
    for (int k = i; k < j; ++k) {
      if (a[k].l > lim) {
        lim = a[k].r;
        ++cnt;
      }
      a[k].val = lim;
    }
    i = j;
  }
  cout << cnt << '\n';
  vector<pair<int, int> > ans(n);
  for (int i = 0, x, y; i < n; ++i) {
    x = a[i].x - a[i].val, y = a[i].m - x;
    ans[a[i].id] = {x, y};
  }
  for (auto i : ans) {
    cout << i.first << ' ' << i.second << '\n';
  }
}
int main() {
  cin.sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
