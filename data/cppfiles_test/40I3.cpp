#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
class DSU {
 public:
  vector<long long int> parent;
  vector<long long int> urank;
  DSU(long long int MAX = 10001) {
    parent.resize(MAX);
    urank.assign(MAX, 1);
    for (long long int i = 0; i <= MAX - 1; i++) {
      parent[i] = i;
    }
  }
  long long int find(long long int x) {
    return parent[x] != x ? parent[x] = find(parent[x]) : x;
  }
  bool join(long long int x, long long int y) {
    long long int xroot = find(x);
    long long int yroot = find(y);
    if (xroot == yroot) return false;
    if (urank[xroot] <= urank[yroot]) {
      parent[xroot] = yroot;
      urank[yroot] = urank[yroot] + urank[xroot];
    } else {
      parent[yroot] = xroot;
      urank[xroot] = urank[xroot] + urank[yroot];
    }
    return true;
  }
};
vector<vector<long long int> > G;
map<pair<long long int, long long int>, long long int> ed_id;
vector<long long int> isOdd;
vector<long long int> par;
void dfs(long long int x, long long int p, long long int d) {
  par[x] = p;
  if (x == d) return;
  for (long long int nb : G[x]) {
    if (nb != p) {
      dfs(nb, x, d);
    }
  }
}
long long int cnt = 0;
bool dfs(long long int x, long long int p) {
  for (long long int nb : G[x]) {
    if (nb != p) {
      long long int id = ed_id[{x, nb}];
      if (isOdd[id]) {
        isOdd[id] = 0;
        dfs(nb, x);
        return true;
      }
    }
  }
  return false;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  DSU dsu(n + 1);
  G.assign(n + 1, vector<long long int>());
  long long int p = 1;
  for (long long int i = 1; i <= m; i++) {
    long long int u, v;
    cin >> u >> v;
    if (dsu.join(u, v)) {
      G[u].emplace_back(v);
      G[v].emplace_back(u);
      ed_id[{v, u}] = p;
      ed_id[{u, v}] = p;
      p++;
    }
  }
  isOdd.assign(n + 1, 0);
  long long int q;
  cin >> q;
  vector<vector<long long int> > ret;
  for (long long int i = 1; i <= q; i++) {
    long long int l, r;
    par.assign(n + 1, -1);
    cin >> l >> r;
    dfs(l, -1, r);
    vector<long long int> path;
    long long int cr = r;
    while (cr != -1) {
      path.emplace_back(cr);
      if (par[cr] != -1) {
        long long int id = ed_id[{cr, par[cr]}];
        isOdd[id] = !isOdd[id];
      }
      cr = par[cr];
    }
    reverse(path.begin(), path.end());
    ret.emplace_back(path);
  }
  bool ans = true;
  for (long long int i = 1; i <= n - 1; i++) {
    if (isOdd[i]) {
      ans = false;
    }
  }
  if (ans) {
    cout << "YES" << '\n';
    for (auto &p : ret) {
      cout << p.size() << '\n';
      for (long long int x : p) cout << x << ' ';
      cout << '\n';
    }
  } else {
    long long int cn = 0;
    for (long long int i = 1; i <= n; i++) {
      if (dfs(i, 0)) {
        cn++;
      }
    }
    cout << "NO" << '\n';
    cout << cn << '\n';
  }
  return 0;
}
