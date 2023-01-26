#include <bits/stdc++.h>
using namespace std;
template <typename T>
void emilia_mata_tenshi(const char *s, T l, T r) {
  cerr << "\e[1;33m" << s << " = [";
  while (l != r) {
    cerr << *l;
    cerr << (++l == r ? ']' : ',');
  }
  cerr << "\e[0m\n";
}
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS = 1e-8;
const int INF = 0x3F3F3F3F;
const ll LINF = 4611686018427387903;
const int MOD = 1e9 + 7;
const int N = 1e5 + 25;
struct disjoint_set {
  int pa[N];
  vector<int> has[N];
  set<pair<int, int>> sz;
  void init(int n) {
    for (int i = 1; i <= n; i++)
      pa[i] = i, has[i].push_back(i), sz.insert({1, i});
  }
  int fnd(int x) { return pa[x] == x ? pa[x] : pa[x] = fnd(pa[x]); }
  bool uni(int a, int b) {
    if ((a = fnd(a)) == (b = fnd(b))) return false;
    sz.erase({has[a].size(), a});
    sz.erase({has[b].size(), b});
    if (has[a].size() > has[b].size()) swap(a, b);
    for (int x : has[a]) has[b].push_back(x);
    pa[a] = b;
    sz.insert({has[b].size(), b});
    return true;
  }
  vector<int> &getmn() { return has[sz.begin()->second]; }
} dsu, dsu2;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu.init(n);
  dsu2.init(n);
  while (m1--) {
    int u, v;
    cin >> u >> v;
    dsu.uni(u, v);
  }
  while (m2--) {
    int u, v;
    cin >> u >> v;
    dsu2.uni(u, v);
  }
  vector<pair<int, int>> ans;
  while (true) {
    auto &a = dsu.getmn(), b = dsu2.getmn();
    if (a.size() == n || b.size() == n) break;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int co = -1;
    for (int i = 0; i < b.size(); i++) {
      auto it = lower_bound(a.begin(), a.end(), b[i]);
      if (it != a.end() && *it == b[i]) {
        co = b[i];
        break;
      }
    }
    int mex = 1;
    while (true) {
      auto it = lower_bound(a.begin(), a.end(), mex);
      auto it2 = lower_bound(b.begin(), b.end(), mex);
      if ((it != a.end() && *it == mex) || (it2 != b.end() && *it2 == mex))
        mex++;
      else
        break;
    }
    if (~co && mex <= n) {
      ans.push_back({co, mex});
      dsu.uni(co, mex);
      dsu2.uni(co, mex);
    } else {
      int x = a[0], y = b[0];
      ans.push_back({x, y});
      dsu.uni(x, y);
      dsu2.uni(x, y);
    }
  }
  cout << ans.size() << '\n';
  for (const auto &[a, b] : ans) cout << a << ' ' << b << '\n';
}
