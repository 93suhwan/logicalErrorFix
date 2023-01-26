#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& u) {
  return out << "(" << u.first << ", " << u.second << ")";
}
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type operator<<(
    ostream& out, const Con& con) {
  out << "{";
  for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
    out << (it == beg ? "" : ", ") << *it;
  return out << "}";
}
template <size_t i, class T>
ostream& print_tuple_utils(ostream& out, const T& tup) {
  if constexpr (i == tuple_size<T>::value)
    return out << ")";
  else
    return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup),
                                       tup);
}
template <class... U>
ostream& operator<<(ostream& out, const tuple<U...>& u) {
  return print_tuple_utils<0, tuple<U...>>(out, u);
}
const int maxn = 201010;
int n;
vector<int> gr[maxn];
int par[maxn];
bool is_leaf[maxn];
bool is_bud[maxn];
int deg(int u) { return ((int)gr[u].size()) - (u != 1); }
void dfs(int u, int p) {
  is_leaf[u] = 0;
  if (u != p and deg(u) == 0) {
    is_leaf[u] = 1;
    return;
  }
  par[u] = p;
  is_bud[u] = u != p and !is_leaf[u];
  for (auto v : gr[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (!is_leaf[v]) is_bud[u] = false;
  }
  bool all_children_bud = 1;
  for (auto v : gr[u]) {
    if (v == p) continue;
    if (!is_bud[v]) {
      all_children_bud = 0;
      break;
    }
  }
  if (all_children_bud) {
    is_leaf[u] = 1;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int ntest;
  cin >> ntest;
  while (ntest--) {
    ;
    cin >> n;
    for (int i = (int)(0); i < (int)(n + 1); ++i) {
      gr[i].clear();
      par[i] = -1;
      is_leaf[i] = 0;
      is_bud[i] = 0;
    }
    for (int i = (int)(0); i < (int)(n - 1); ++i) {
      int u, v;
      cin >> u >> v;
      gr[u].push_back(v);
      gr[v].push_back(u);
    }
    dfs(1, 1);
    int total_leaves = (int)accumulate(is_leaf + 1, is_leaf + n + 1, 0);
    if (0)
      cerr << "["
              "total_leaves"
              " = "
           << (total_leaves) << "] " << endl;
    int cnt_buds = 0;
    for (int i = (int)(1); i < (int)(n + 1); ++i) {
      if (0)
        cerr << "["
                "i"
                " = "
             << (i) << "] "
             << "["
                "is_bud[i]"
                " = "
             << (is_bud[i]) << "] "
             << "["
                "is_leaf[i]"
                " = "
             << (is_leaf[i]) << "] " << endl;
      cnt_buds += is_bud[i];
    }
    int ans = total_leaves;
    for (int i = (int)(1); i < (int)(n + 1); ++i) ans -= is_bud[i];
    cout << ans << '\n';
  }
  return 0;
}
