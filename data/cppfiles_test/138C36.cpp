#include <bits/stdc++.h>
using namespace std;
class dsu {
  vector<int> p, sz, good, a, r;

 public:
  long long res = 0;
  dsu(vector<pair<int, int>> b) {
    int n = b.size();
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    good.resize(n);
    sz.resize(n, 1);
    r.resize(n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
      if (b[i].second) {
        res += b[i].first;
        good[i] = 1;
      }
      a[i] = b[i].first;
      r[i] = i;
    }
  }
  int get(int v) { return (v == p[v] ? v : p[v] = get(p[v])); }
  bool unite(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) {
      return false;
    }
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    for (int i = 0; i < good[v]; ++i) res -= a[r[v] - i];
    if (u < v) {
      for (int i = 0; i < sz[v]; ++i) res += a[r[v] - i];
      for (int i = 0; i < sz[v] - good[v]; ++i)
        res -= a[r[u] - good[u] + 1 + i];
    } else {
      for (int i = 0; i < good[v]; ++i) res += a[r[u] - good[u] - i];
    }
    sz[u] += sz[v];
    good[u] += good[v];
    r[u] = max(r[u], r[v]);
    return true;
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.emplace_back(x, 1);
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    a.emplace_back(x, 0);
  }
  sort(a.begin(), a.end());
  vector<pair<int, int>> seg;
  for (int i = 0; i < n + m - 1; ++i) {
    seg.emplace_back(a[i + 1].first - a[i].first, i);
  }
  sort(seg.begin(), seg.end());
  vector<pair<int, int>> qr(q);
  for (int i = 0; i < q; ++i) {
    cin >> qr[i].first;
    qr[i].second = i;
  }
  sort(qr.begin(), qr.end());
  dsu d(a);
  vector<long long> ans(q);
  for (int i = 0, j = 0; i < q; ++i) {
    while (j < seg.size() and seg[j].first <= qr[i].first) {
      d.unite(seg[j].second, seg[j].second + 1);
      ++j;
    }
    ans[qr[i].second] = d.res;
  }
  for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
  return 0;
}
