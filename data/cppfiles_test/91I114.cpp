#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e18, MOD = 1e9 + 7;
template <class A, class B>
pair<A, B> operator+(pair<A, B>& a, pair<A, B>& b) {
  return {a.first + b.first, a.second + b.second};
}
template <class A, class B>
pair<A, B> operator-(pair<A, B>& a, pair<A, B>& b) {
  return {a.first - b.first, a.second - b.second};
}
template <class A, class B>
istream& operator>>(istream& is, pair<A, B>& a) {
  return is >> a.first >> a.second;
}
template <class A, class B>
ostream& operator<<(ostream& os, const pair<A, B>& a) {
  return os << "< " << a.first << " , " << a.second << " >";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
  os << '[';
  if (!v.empty()) {
    os << v[0];
    for (int64_t i = (1); i < (v.size()); i++) os << ',' << v[i];
  }
  return os << ']';
}
template <class T>
ostream& operator<<(ostream& os, set<T> v) {
  os << '{';
  if (!v.empty()) {
    os << *v.begin();
    for (auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it;
  }
  return os << '}';
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int64_t>(0, INF);
bool inter(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
  return a.first == b.first || a.first == b.second || a.second == b.first ||
         a.second == b.second;
}
map<pair<int64_t, int64_t>, int64_t> AllEdges;
vector<int64_t> vals;
multiset<int64_t> svals;
vector<set<pair<int64_t, int64_t>>> g, restg;
set<pair<int64_t, pair<int64_t, int64_t>>> edges;
pair<int64_t, pair<int64_t, int64_t>> getE(int64_t a, int64_t b, int64_t c) {
  if (a > b) swap(a, b);
  return {c, {a, b}};
}
pair<int64_t, pair<int64_t, int64_t>> flip(
    pair<int64_t, pair<int64_t, int64_t>> e) {
  return {e.first, {e.second.second, e.second.first}};
}
const int64_t K = 5;
void fix(int64_t a, bool flag = 1) {
  if (flag && vals[a] != -1) svals.erase(svals.find(vals[a])), vals[a] = -1;
  while (g[a].size() > K) {
    auto it = prev(g[a].end());
    auto itt = edges.find(getE(a, it->second, it->first));
    if (itt != edges.end()) edges.erase(itt);
    restg[a].insert(*it);
    g[a].erase(it);
  }
  while (g[a].size() < K && restg[a].size()) {
    auto it = restg[a].begin();
    edges.insert(getE(a, it->second, it->first));
    g[a].insert(*it);
    restg[a].erase(it);
  }
  if (flag && g[a].size() >= 3) {
    int64_t v = 0, cnt = 0;
    for (auto p : g[a])
      if (cnt++ < 3) v += p.first;
    vals[a] = v;
    svals.insert(v);
  }
}
void addE(int64_t a, int64_t b, int64_t c) {
  if (a > b) swap(a, b);
  AllEdges[{a, b}] = c;
  edges.insert({c, {a, b}});
  g[a].insert({c, b}), g[b].insert({c, a});
  fix(a), fix(b);
}
void removeE(int64_t a, int64_t b) {
  if (a > b) swap(a, b);
  int64_t c = AllEdges[{a, b}];
  AllEdges.erase({a, b});
  {
    auto it = edges.find({c, {a, b}});
    if (it != edges.end()) edges.erase(it);
  }
  {
    auto it = g[a].find({c, b});
    if (it != g[a].end())
      g[a].erase({c, b});
    else
      restg[a].erase({c, b});
  }
  {
    auto it = g[b].find({c, a});
    if (it != g[a].end())
      g[b].erase({c, a});
    else
      restg[b].erase({c, a});
  }
  fix(a), fix(b);
}
int64_t solve() {
  int64_t ans = INF;
  pair<int64_t, pair<int64_t, int64_t>> e = *edges.begin();
  int64_t a = e.second.first, b = e.second.second, c = e.first;
  vector<pair<int64_t, pair<int64_t, int64_t>>> backup;
  for (auto p : g[a]) {
    pair<int64_t, pair<int64_t, int64_t>> e = getE(a, p.second, p.first);
    auto it = edges.find(e);
    if (it != edges.end()) edges.erase(e), backup.push_back(e);
  }
  for (auto p : g[b]) {
    pair<int64_t, pair<int64_t, int64_t>> e = getE(b, p.second, p.first);
    auto it = edges.find(e);
    if (it != edges.end()) edges.erase(e), backup.push_back(e);
  }
  if (edges.size()) {
    ans = min(ans, c + edges.begin()->first);
    assert(!inter(e.second, edges.begin()->second));
  }
  for (auto e : backup) edges.insert(e);
  for (auto p : g[a]) {
    if (p.second == b) continue;
    for (auto q : g[b]) {
      if (q.second == a || p.second == q.second) continue;
      ans = min(ans, p.first + q.first);
    }
  }
  return min(ans, *svals.begin());
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  int64_t n, m;
  cin >> n >> m;
  vals.resize(n + 1, -1), g.resize(n + 1), restg.resize(n + 1),
      svals.insert(INF);
  for (int64_t i = (0); i < (m); i++) {
    int64_t a, b, c;
    cin >> a >> b >> c;
    addE(a, b, c);
  }
  cout << solve() << endl;
  int64_t q;
  cin >> q;
  for (int64_t i = (0); i < (q); i++) {
    int64_t op, a, b, c;
    cin >> op >> a >> b;
    if (op == 0) {
      removeE(a, b);
    } else {
      cin >> c;
      addE(a, b, c);
    }
    cout << solve() << endl;
  }
  return 0;
}
