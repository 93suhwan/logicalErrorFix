#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
struct UnionFind {
  vector<int> link, siz, ans, cnt;
  vector<priority_queue<int>> pq;
  vector<pair<int, bool>> v;
  int n, m, nm, fa;
  UnionFind(vector<pair<int, bool>> _v) {
    v = _v;
    fa = 0;
    nm = (int)(v).size();
    siz.resize(nm, 1);
    link.resize(nm);
    iota(begin(link), end(link), 0);
    ans.resize(nm);
    cnt.resize(nm);
    pq.resize(nm);
    for (int i = 0; i < nm; ++i) {
      n += v[i].second;
      ans[i] += v[i].first * v[i].second;
      fa += ans[i];
      cnt[i] = v[i].second;
      pq[i].push(v[i].first);
    }
    m = nm - n;
  }
  int find(int x) {
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
  }
  void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    link[b] = a;
    while (!pq[b].empty()) {
      pq[a].push(pq[b].top());
      pq[b].pop();
    }
    cnt[a] += cnt[b];
    fa -= ans[a];
    fa -= ans[b];
    ans[a] = 0;
    auto cp = pq[a];
    for (int i = 0; i < cnt[a]; ++i) {
      ans[a] += cp.top();
      cp.pop();
    }
    fa += ans[a];
  }
};
void solve(int tc) {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, bool>> v(n + m);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = true;
  }
  for (int i = n; i < n + m; ++i) cin >> v[i].first;
  sort(begin(v), end(v));
  vector<pair<int, int>> qe(q);
  for (int i = 0; i < q; ++i) {
    cin >> qe[i].first;
    qe[i].second = i;
  }
  vector<int> ans(q);
  sort(begin(qe), end(qe));
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (int i = 0; i < n + m - 1; ++i) pq.push({v[i + 1].first - v[i].first, i});
  UnionFind uf(v);
  for (auto [a, b] : qe) {
    while (!pq.empty() and pq.top().first <= a) {
      int x = pq.top().second;
      pq.pop();
      uf.unite(x, x + 1);
    }
    ans[b] = uf.fa;
  }
  for (int x : ans) cout << x << '\n';
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int tc = 1;
  for (int i = 1; i <= tc; ++i) solve(i);
  return 0;
}
