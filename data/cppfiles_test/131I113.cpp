#include <bits/stdc++.h>
using namespace std;
void in() {}
template <typename T, typename... otr_T>
void in(T& t, otr_T&... otr) {
  cin >> t;
  in(otr...);
}
void out(int a, bool ln) { printf("%d%c", a, " \n"[ln]); }
void out(long long a, bool ln) { printf("%lld%c", a, " \n"[ln]); }
void out(double a, int digit, bool ln) {
  printf("%.*f%c", digit, a, " \n"[ln]);
}
const int maxn = 5e5 + 5;
const int maxm = 2e6 + 5;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
const long long mod = 998244353;
int a[maxn], n;
map<long long, int> m;
vector<int> v, dep;
vector<vector<int>> edge;
inline bool add(int u) {
  if (m.count(u)) return false;
  m[u] = v.size();
  edge.emplace_back();
  dep.emplace_back(0);
  v.emplace_back(u);
  return true;
}
void init(long long u) {
  if (!add(u)) return;
  long long tmp = 1;
  while (tmp < u) tmp <<= 1;
  while (u) {
    bool flag = add(tmp - u);
    edge[m[tmp - u]].emplace_back(m[u]);
    edge[m[u]].emplace_back(m[tmp - u]);
    if (!flag) return;
    u = tmp - u;
    while (tmp && (tmp >> 1) >= u) tmp >>= 1;
  }
}
pair<int, int> dfs(int u, int f, int d) {
  pair<int, int> ret = {d, u};
  for (auto& v : edge[u]) {
    if (v == f) continue;
    pair<int, int> tmp = dfs(v, u, d + 1);
    if (tmp.first > ret.first) {
      ret = tmp;
    }
  }
  return ret;
}
int main() {
  in(n);
  for (int i = 1; i <= n; ++i) {
    in(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    init(a[i]);
  }
  long long ans = 0, x, y;
  x = dfs(m[0], -1, 1).first;
  tie(ans, y) = dfs(x, -1, 1);
  for (int i = 1; i <= n; ++i) {
    if (a[i] == v[x]) out(i, 0);
    if (a[i] == v[y]) out(i, 0);
  }
  out(ans - 1, 1);
}
