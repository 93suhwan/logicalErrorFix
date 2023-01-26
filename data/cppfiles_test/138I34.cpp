#include <bits/stdc++.h>
using namespace std;
class dsu {
  vector<int> p, sz, goodsz;
  vector<deque<int>> good, bad;
  vector<long long> tot;

 public:
  dsu(int n) {
    p.resize(n);
    sz.resize(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  int get(int v) { return (v == p[v] ? v : p[v] = get(p[v])); }
  bool unite(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) {
      return false;
    }
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    res -= tot[v];
    if (u < v) {
      for (int x : bad[v]) {
        tot[u] += x;
        res += x;
        good[u].push_back(x);
      }
      for (int x : good[v]) {
        tot[u] += x;
        res += x;
        good[u].push_back(x);
      }
      while (good[u].size() > goodsz[u] + goodsz[v]) {
        tot[u] -= good[u].front();
        res -= good[u].front();
        bad[u].push_back(good[u].front());
        good[u].pop_front();
      }
    } else {
      for (int i = 0; i < goodsz[v]; ++i) {
        if (!bad[u].empty()) {
          tot[u] += bad[u].back();
          res += bad[u].back();
          good[u].push_front(bad[u].back());
          bad[u].pop_back();
        } else {
          tot[u] += good[v].back();
          res += good[v].back();
          good[u].push_back(good[v].back());
          good[v].pop_back();
        }
      }
      for (int x : good[v]) {
        bad[u].push_front(x);
      }
      for (int x : bad[v]) {
        bad[u].push_front(x);
      }
    }
    good[v].clear();
    bad[v].clear();
    goodsz[u] += goodsz[v];
    return true;
  }
  int size(int v) { return sz[get(v)]; }
  dsu(vector<pair<int, int>> a) {
    int n = a.size();
    p.resize(n);
    sz.resize(n, 1);
    iota(p.begin(), p.end(), 0);
    tot.resize(n);
    good.resize(n);
    bad.resize(n);
    goodsz.resize(n);
    for (int i = 0; i < n; ++i) {
      if (a[i].second) {
        goodsz[i] = 1;
        tot[i] += a[i].first;
        res += a[i].first;
        good[i].push_back(a[i].first);
      } else {
        bad[i].push_back(a[i].first);
      }
    }
  }
  long long res = 0;
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
