#include <bits/stdc++.h>
using namespace std;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int maxn = 1e6 + 7, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int N = 1e6 + 7;
vector<pair<int, int> > E[N];
int sz[N], dep[N];
long long a[N];
bool vis[N];
int mx;
int rt, tp, k, n;
struct bit {
  long long t[maxn];
  int lowbit(int x) { return x & (-x); }
  void add(int x, long long v) {
    x++;
    for (int i = x; i <= mx; i += lowbit(i)) t[i] = (t[i] + v) % mod;
  }
  long long ask(int x) {
    long long res = 0;
    x++;
    for (int i = x; i; i -= lowbit(i)) res = (res + t[i]) % mod;
    return res;
  }
} cnt[2], val[2];
long long ans;
void upd(long long &x, long long v) {
  x += v;
  if (x >= mod) x %= mod;
}
void prepare(int u, int fa) {
  sz[u] = 1;
  mx = max(dep[u], mx);
  for (auto &e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (v == fa || vis[v]) continue;
    dep[v] = dep[u] + 1;
    prepare(v, u);
    sz[u] += sz[v];
  }
}
void getroot(int u, int fa, int &m, int &root) {
  if (sz[u] * 2 < m) return;
  if (sz[u] < sz[root]) root = u;
  for (auto &e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (v == fa || vis[v]) continue;
    getroot(v, u, m, root);
  }
}
void calc(int u, int fa, int pre, int swich, long long sum) {
  if (swich > k) return;
  if (swich <= k) upd(ans, sum + a[rt]);
  if (swich <= k)
    upd(ans, val[tp].ask(min(mx, k - swich)) +
                 sum * cnt[tp].ask(min(mx, k - swich)) % mod);
  if (swich + 1 <= k)
    upd(ans, val[tp ^ 1].ask(min(mx, k - swich)) +
                 sum * cnt[tp ^ 1].ask(min(mx, k - swich)) % mod);
  ;
  for (auto &e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (v == fa || vis[v]) continue;
    calc(v, u, w, swich + (w != pre), (sum + a[v]) % mod);
  }
}
void add(int u, int fa, int pre, int swich, long long sum) {
  val[tp].add(swich, sum);
  cnt[tp].add(swich, 1);
  for (auto &e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (v == fa || vis[v]) continue;
    add(v, u, w, swich + (w != pre), (sum + a[v]) % mod);
  }
}
void conquer(int u) {
  mx = 0, dep[u] = 0;
  prepare(u, 0);
  mx++;
  upd(ans, a[u]);
  rt = u;
  for (auto &e : E[u]) {
    int v, w;
    tie(v, w) = e;
    if (vis[v]) continue;
    tp = w;
    calc(v, u, tp, 0, a[v]);
    add(v, u, tp, 0, a[u] + a[v]);
  }
  for (int i = 0; i <= mx; ++i)
    cnt[0].t[i] = cnt[1].t[i] = val[0].t[i] = val[1].t[i] = 0;
}
void divide(int u) {
  prepare(u, 0);
  int m = sz[u], root = u;
  getroot(u, 0, m, root);
  conquer(root);
  vis[root] = 1;
  for (auto &e : E[root]) {
    int v, w;
    tie(v, w) = e;
    if (vis[v]) continue;
    divide(v);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0, u, v, w; i < n - 1; ++i) {
    cin >> u >> v >> w;
    E[u].push_back({v, w});
    E[v].push_back({u, w});
  }
  divide(1);
  cout << ans << '\n';
  return 0;
}
