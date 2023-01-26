#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const long long INFll = 4e18;
const long long INFi = 1e9 + 63;
const double pi = acos(-1);
const int maxn = 6e5;
const int maxd = 16;
const long long mod = 998244353;
const int sqrtN = 300;
int caseNo = 1;
void E() {}
template <class A, class... B>
void E(A $, B... _) {
  cerr << ' ' << $;
  E(_...);
}
struct rmq_t {
  using val_t = long long;
  const static int size = 2e5;
  val_t mas[size << 1];
  static long long op(long long a, long long b) { return a + b; }
  void modify(int ind, val_t val) {
    ind += size;
    mas[ind] = val;
    for (ind >>= 1; ind > 0; ind >>= 1)
      mas[ind] = op(mas[ind << 1], mas[(ind << 1) + 1]);
  }
  val_t query(int l, int r) {
    if (l > r) return 0;
    l += size;
    r += size;
    val_t ans = mas[l];
    if (l < r) ans = op(ans, mas[r]);
    for (; l < r; l >>= 1, r >>= 1) {
      if ((l & 1) == 0 && (l + 1) < r) ans = op(ans, mas[l + 1]);
      if ((r & 1) == 1 && (r - 1) > l) ans = op(ans, mas[r - 1]);
    }
    return ans;
  }
};
rmq_t rmq;
vector<int> g[maxn];
namespace {
const int maxn = 2e5;
int par[maxn];
int sz_sub[maxn];
int mx[maxn];
int pos[maxn];
int root[maxn];
int depth[maxn];
void dfs_all(int v, int d = 0) {
  depth[v] = d;
  sz_sub[v] = 1;
  int ind = -1, mai = -1;
  for (auto it : g[v]) {
    if (par[v] != it) {
      par[it] = v;
      dfs_all(it, d + 1);
      sz_sub[v] += sz_sub[it];
      if (sz_sub[it] > mai) {
        mai = sz_sub[it];
        ind = it;
      }
    }
  }
  mx[v] = ind;
}
void build_array() {
  int cpos = 0;
  for (int i = 0; i < maxn; ++i) {
    if (sz_sub[i] && (par[i] == -1 || mx[par[i]] != i)) {
      for (int v = i; v != -1; v = mx[v]) {
        pos[v] = cpos++;
        root[v] = i;
      }
    }
  }
}
int get(int u, int v) {
  int ans = 0;
  while (root[u] != root[v]) {
    if (depth[root[u]] < depth[root[v]]) swap(u, v);
    ans = rmq_t::op(ans, rmq.query(pos[root[u]], pos[u]));
    u = par[root[u]];
  }
  if (depth[u] < depth[v]) swap(u, v);
  ans = rmq_t::op(ans, rmq.query(pos[v], pos[u]));
  return ans;
}
}  // namespace
void solve() {
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    g[s].push_back(t);
    g[t].push_back(s);
  }
  dfs_all(0);
  build_array();
  for (int i = 0; i < n; i++) {
    rmq.modify(pos[i], a[i]);
  }
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, c;
      cin >> u >> c;
      u--;
      rmq.modify(pos[u], abs(c));
    } else {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      long long test = 2 * get(u, v);
      test -= get(u, u);
      test -= get(v, v);
      cout << test << "\n";
    }
  }
}
int main(int argc, char** argv) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  int t = 1;
  clock_t start = clock();
  for (int i = 0; i < t; i++) solve();
  return 0;
}
