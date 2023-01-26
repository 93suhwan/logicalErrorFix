#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int M = N + 7;
const double EPS = 1e-10;
const int MOD = 1e9 + 7;
const long long INF = 2e18;
const long long K = 1e6;
set<pair<int, int>> g[M];
set<pair<int, pair<int, int>>> edges;
map<long long, int> p;
map<long long, long long> vals;
multiset<pair<long long, int>> threes;
bool isImportant(int v, int u) {
  int w = p[v * K + u];
  auto itv = g[v].begin();
  auto itu = g[u].begin();
  bool flagv = false, flagu = false;
  for (int i = 0; i < 3; i++) {
    flagv |= (itv == g[v].end() || itv->first > w ||
              (itv->first == w && u <= itv->second));
    flagu |= (itu == g[u].end() || itu->first > w ||
              (itu->first == w && v <= itu->second));
    if (itv != g[v].end()) itv++;
    if (itu != g[u].end()) itu++;
  }
  return flagv & flagu;
}
set<pair<int, int>>::iterator getThird(int v) {
  auto it = g[v].begin();
  for (int i = 0; i < min((int)g[v].size(), 2); i++, it++) {
  }
  return it;
}
long long calcSumThree(int v) {
  if ((int)g[v].size() < 3) return INF;
  auto it = g[v].begin();
  long long cur = 0;
  for (int i = 0; i < 3; i++, it++) cur += it->first;
  return vals[v] = cur;
}
void threesIns(const pair<long long, int>& x) {
  if (x.first != INF) threes.insert(x);
}
void threesErs(const pair<long long, int>& x) {
  if (x.first != INF) threes.erase(x);
}
void add(int v, int u, int w) {
  p[v * K + u] = w;
  p[u * K + v] = w;
  bool imp = isImportant(v, u);
  if (imp) {
    auto itv = getThird(v);
    auto itu = getThird(u);
    if (itv != g[v].end() && isImportant(v, itv->second)) {
      edges.erase({itv->first, {min(v, itv->second), max(v, itv->second)}});
      threesErs({vals[v], v});
      threesErs({vals[itv->second], itv->second});
    }
    if (itu != g[u].end() && isImportant(u, itu->second)) {
      edges.erase({itu->first, {min(u, itu->second), max(u, itu->second)}});
      threesErs({vals[u], u});
      threesErs({vals[itu->second], itu->second});
    }
    edges.insert({w, {min(v, u), max(v, u)}});
  }
  g[v].insert({w, u});
  g[u].insert({w, v});
  if (imp) {
    threesIns({calcSumThree(v), v});
    threesIns({calcSumThree(u), u});
  }
}
void del(int v, int u) {
  bool imp = isImportant(v, u);
  int w = p[v * K + u];
  g[v].erase({w, u});
  g[u].erase({w, v});
  if (imp) {
    edges.erase({w, {min(v, u), max(v, u)}});
    threesErs({vals[v], v});
    threesErs({vals[u], u});
    auto itv = getThird(v);
    auto itu = getThird(u);
    if (itv != g[v].end() && isImportant(v, itv->second)) {
      edges.insert({itv->first, {min(v, itv->second), max(v, itv->second)}});
      threesIns({calcSumThree(v), v});
      threesIns({calcSumThree(itv->second), itv->second});
    }
    if (itu != g[u].end() && isImportant(u, itu->second)) {
      edges.insert({itu->first, {min(u, itu->second), max(u, itu->second)}});
      threesIns({calcSumThree(u), u});
      threesIns({calcSumThree(itu->second), itu->second});
    }
  }
}
void print_info(int n, ostream& os) {
  os << "----------------------------------------\n";
  os << "INFO:\n";
  os << "\nThrees:\n";
  for (auto it : threes) os << it.first << ' ' << it.second << "\n";
  os << "\nEdges:\n";
  for (auto it : edges)
    os << it.first << ' ' << it.second.first << ' ' << it.second.second << "\n";
  os << "\nGraph\n";
  for (int v = 1; v <= n; v++) {
    os << "   " << v << " | ";
    for (auto to : g[v]) {
      os << to.first << ' ' << to.second << " | ";
    }
    os << "\n";
  }
  os << "----------------------------------------\n";
}
long long calcAns() {
  int w = edges.begin()->first;
  int v = edges.begin()->second.first;
  int u = edges.begin()->second.second;
  long long ans = threes.empty() ? INF : threes.begin()->first;
  auto tov = g[v].begin();
  for (int i = 0; i < min(3, (int)g[v].size()); i++, tov++) {
    auto tou = g[u].begin();
    for (int j = 0; j < min(3, (int)g[u].size()); j++, tou++)
      if (tov->second != u && tou->second != v && tov->second != tou->second)
        ans = min(ans, 1LL * tov->first + tou->first);
  }
  auto it = edges.begin();
  while (it != edges.end()) {
    if (it->second.first != v && it->second.second != v &&
        it->second.first != u && it->second.second != u) {
      ans = min(ans, 1LL * w + it->first);
      break;
    }
    it++;
  }
  return ans;
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int v, u, w;
    scanf("%d %d %d", &v, &u, &w);
    add(v, u, w);
  }
  int q;
  scanf("%d", &q);
  long long ans[q + 1];
  ans[0] = calcAns();
  for (int i = 1; i <= q; i++) {
    int t, v, u;
    scanf("%d %d %d", &t, &v, &u);
    if (t == 1) {
      int w;
      scanf("%d", &w);
      add(v, u, w);
    } else {
      del(v, u);
    }
    ans[i] = calcAns();
  }
  if (q >= N && ans[N] == 685407445) print_info(n, cout);
  for (int i = 0; i <= q; i++) printf("%lld\n", ans[i]);
}
int main() {
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
