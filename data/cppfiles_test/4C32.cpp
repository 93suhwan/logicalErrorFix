#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 50;
int n, k;
ll a[maxn];
struct edge_node {
  int to, nxt;
  int w;
} edge[maxn << 2];
int head[maxn], id = 2;
inline void add_edge(int u, int v, int w) {
  edge[id] = edge_node{v, head[u], w};
  head[u] = id++;
  edge[id] = edge_node{u, head[v], w};
  head[v] = id++;
}
int wc;
bool st[maxn];
int get_sz(int u, int pre) {
  if (st[u]) {
    return 0;
  }
  int res = 1;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v != pre) {
      res += get_sz(v, u);
    }
  }
  return res;
}
int get_wc(int u, int pre, int tot) {
  if (st[u]) {
    return 0;
  }
  int sz = 1, mx = 0;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v != pre) {
      int szv = get_wc(v, u, tot);
      mx = max(mx, szv);
      sz += szv;
    }
  }
  mx = max(mx, tot - sz);
  if (mx <= tot / 2) {
    wc = u;
  }
  return sz;
}
struct BIT {
  ll c[maxn];
  inline static int lowbit(int x) { return x & (-x); }
  void modify(int x, ll val) {
    while (x < maxn) {
      c[x] = (c[x] + val) % mod;
      x += lowbit(x);
    }
  }
  ll get_sum(int x) {
    ll res = 0;
    while (x) {
      res = (res + c[x]) % mod;
      x -= lowbit(x);
    }
    return res;
  }
  BIT() { memset(c, 0, sizeof(c)); }
} bit[2];
struct BIT2 {
  ll c[maxn];
  inline static int lowbit(int x) { return x & (-x); }
  void modify(int x, ll val) {
    while (x < maxn) {
      c[x] += val;
      x += lowbit(x);
    }
  }
  ll get_sum(int x) {
    ll res = 0;
    while (x) {
      res += c[x];
      x -= lowbit(x);
    }
    return res;
  }
  BIT2() { memset(c, 0, sizeof(c)); }
} bit2[2];
ll calc2(int u, int pre, int pre_clr, int clr_num, ll val) {
  if (st[u]) {
    return 0;
  }
  if (clr_num > k) {
    return 0;
  }
  val = (val + a[u]) % mod;
  ll res = val;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    int w = edge[i].w;
    if (v != pre) {
      ll tmp = calc2(v, u, w, clr_num + (pre_clr != w), val);
      res = (res + tmp) % mod;
    }
  }
  return res;
}
void count(int u, int pre, int pre_clr, int clr_num, ll val, int st_clr) {
  if (st[u]) {
    return;
  }
  if (clr_num > k) {
    return;
  }
  val = (val + a[u]) % mod;
  bit[st_clr].modify(clr_num + 1, val);
  bit2[st_clr].modify(clr_num + 1, 1);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    int w = edge[i].w;
    if (v != pre) {
      count(v, u, w, clr_num + (pre_clr != w), val, st_clr);
    }
  }
}
void del(int u, int pre, int pre_clr, int clr_num, ll val, int st_clr) {
  if (st[u]) {
    return;
  }
  if (clr_num > k) {
    return;
  }
  val = (val + a[u]) % mod;
  bit[st_clr].modify(clr_num + 1, (-val % mod + mod) % mod);
  bit2[st_clr].modify(clr_num + 1, -1);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    int w = edge[i].w;
    if (v != pre) {
      del(v, u, w, clr_num + (pre_clr != w), val, st_clr);
    }
  }
}
ll calc3(int u, int pre, int pre_clr, int clr_num, ll val, int st_clr) {
  if (st[u]) {
    return 0;
  }
  if (clr_num > k) {
    return 0;
  }
  val = (val + a[u]) % mod;
  ll res = 0;
  ll tmp = bit[st_clr].get_sum(k - clr_num + 1);
  ll cnt = bit2[st_clr].get_sum(k - clr_num + 1);
  res = (res + tmp) % mod;
  res = (res + val * cnt % mod) % mod;
  if (clr_num <= k - 1) {
    ll tmp = bit[!st_clr].get_sum(k - clr_num - 1 + 1);
    ll cnt = bit2[!st_clr].get_sum(k - clr_num - 1 + 1);
    res = (res + tmp) % mod;
    res = (res + val * cnt % mod) % mod;
  }
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    int w = edge[i].w;
    if (v != pre) {
      ll tmp = calc3(v, u, w, clr_num + (pre_clr != w), val, st_clr);
      res = (res + tmp) % mod;
    }
  }
  return res;
}
inline ll tydq(int u) {
  if (st[u]) {
    return 0;
  }
  ll res = 0;
  wc = u;
  get_wc(u, 0, get_sz(u, 0));
  u = wc;
  st[u] = true;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    int w = edge[i].w;
    res = (res + calc3(v, u, w, 0, a[u], w)) % mod;
    res = (res + calc2(v, u, w, 0, a[u])) % mod;
    count(v, u, w, 0, 0, w);
  }
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    int w = edge[i].w;
    del(v, u, w, 0, 0, w);
  }
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    res = (res + tydq(v)) % mod;
  }
  return res;
}
signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  ll ans = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ans = (ans + a[i]) % mod;
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    add_edge(u, v, w);
  }
  ll res = tydq(1);
  ans = (ans + res) % mod;
  cout << ans << '\n';
  return 0;
}
