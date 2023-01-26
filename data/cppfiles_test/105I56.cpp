#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7, inf = 1e9 + 7;
struct node {
  int x, y, m, s, l, r, id, val;
  bool operator<(const node& a) const { return s < a.s; }
};
struct ppt {
  int id, x, y;
  bool operator<(const ppt& a) const {
    if (x != a.x) return x < a.x;
    return y < a.y;
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
    vector<ppt> P;
    for (int k = i; k < j; ++k) {
      P.emplace_back(ppt{k, a[k].l, 1});
      P.emplace_back(ppt{k, a[k].r + 1, -1});
    }
    sort(P.begin(), P.end());
    vector<int> v;
    for (auto k : P) {
      if (k.y == 1)
        v.emplace_back(k.id);
      else {
        for (auto kk : v) a[kk].val = k.x - 1;
        if (v.size()) ++cnt;
        v.clear();
      }
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
