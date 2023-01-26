#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<int> hist, lst = {0}, par, _sz, cnt;
  DSU(int n) : par(n + 1), _sz(n + 1), cnt(n + 1) {
    iota(par.begin(), par.end(), 0);
    fill(_sz.begin(), _sz.end(), 1);
    fill(cnt.begin(), cnt.end(), 0);
  }
  int qry(int x) { return par[x] == x ? x : qry(par[x]); }
  void join(int x, int y) {
    if ((x = qry(x)) == (y = qry(y))) {
      cnt[x]++;
      hist.push_back(~x);
      return;
    }
    if (_sz[y] < _sz[x]) swap(x, y);
    _sz[par[x] = y] += _sz[x];
    cnt[y] += cnt[x];
    hist.push_back(x);
  }
  void snapshot() { lst.push_back((int)hist.size()); }
  void rollback() {
    while (hist.size() != lst.back()) {
      int u = hist.back();
      if (0 <= u)
        _sz[par[u]] -= _sz[u], par[u] = u, cnt[par[u]] -= cnt[u];
      else
        cnt[~u]--;
      hist.pop_back();
    }
    lst.pop_back();
  }
  int is_desert(pair<int, int> x) {
    return qry(x.first) != qry(x.second) || cnt[qry(x.first)] == 0;
  }
  void apply(pair<int, int> x) {
    snapshot();
    join(x.first, x.second);
  }
  void undo() { rollback(); }
};
template <class T, class O>
struct dsqueue {
  T ds;
  vector<pair<int, O>> a;
  int cnt = 0;
  dsqueue(int n = 0) : ds(n) {}
  void pop() {
    if (!cnt) {
      cnt = a.size();
      reverse(a.begin(), a.end());
      for (auto& [t, o] : a) ds.undo(), t = 0;
      for (auto& [t, o] : a) ds.apply(o);
    }
    deque<O> b[2];
    for (int t : {1, 0}) {
      for (int i = 0; !t ? i < (cnt & -cnt) : a.back().first; i++) {
        b[t].push_front(a.back().second);
        a.pop_back();
        ds.undo();
      }
    }
    for (int t : {1, 0}) {
      for (auto& o : b[t]) {
        ds.apply(o);
        a.emplace_back(t, o);
      }
    }
    cnt--;
    ds.undo();
    a.pop_back();
  }
  void push(O o) {
    a.emplace_back(1, o);
    ds.apply(o);
  }
  int is_desert(O o) { return ds.is_desert(o); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> e(m);
  for (int i = 0; i < m; i++) cin >> e[i].first >> e[i].second;
  dsqueue<DSU, pair<int, int>> d(n);
  long long ans = 0;
  for (int i = 0, j = 0; i < m; i++) {
    while (j < m && d.is_desert(e[j])) d.push(e[j++]);
    ans += j - i;
    d.pop();
  }
  cout << ans << "\n";
}
