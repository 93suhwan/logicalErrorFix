#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 10;
const int MOD = 1e9 + 7;
int n, k, ans, h[MAXN], sz[MAXN], val[MAXN], a[MAXN], st[MAXN], en[MAXN],
    idx[MAXN], tme = 0;
int f1[MAXN], f2[MAXN], F1[MAXN], F2[MAXN];
vector<int> child[MAXN];
vector<pair<int, int> > g[MAXN];
inline int add(int a, int b) {
  int res = a + b;
  if (res >= MOD) res -= MOD;
  if (res < 0) res += MOD;
  return res;
}
inline void add(int idx, int x, int *f) {
  if (idx <= 0) return;
  for (; idx <= n + k; idx += idx & -idx) {
    f[idx] = add(f[idx], x);
  }
}
inline int get(int idx, int *f) {
  if (idx < 0) return 0;
  int res = 0;
  for (; idx; idx -= idx & -idx) res = add(res, f[idx]);
  return res;
}
inline int get(int l, int r, int *f) {
  if (l > r) return 0;
  return add(get(r, f), -get(l - 1, f));
}
void dfs(int v, int p, int e) {
  tme++;
  idx[tme] = v;
  st[v] = tme;
  sz[v] = 1;
  val[v] = a[v];
  if (p != -1) {
    val[v] = add(val[v], val[p]);
  }
  for (auto [u, w] : g[v]) {
    if (u != p) {
      h[u] = h[v] + (w == e ? 0 : 1);
      dfs(u, v, w);
      sz[v] += sz[u];
    }
  }
  en[v] = tme;
}
void sack(int v, int p, int e, bool keep) {
  int mx = -1, bigchild = -1, ce = 0;
  for (auto [u, w] : g[v]) {
    if (u != p && sz[u] > mx) {
      mx = sz[u];
      bigchild = u;
      ce = w;
    }
  }
  for (auto [u, w] : g[v]) {
    if (u != p && u != bigchild) {
      sack(u, v, w, false);
    }
  }
  if (bigchild != -1) {
    sack(bigchild, v, ce, true);
  }
  for (auto [u, w] : g[v]) {
    if (u == p || u == bigchild) continue;
    for (int tmp = st[u]; tmp <= en[u]; tmp++) {
      int X = idx[tmp];
      if (w == e) {
        int H = h[X] - h[v];
        int VAL = add(val[X], -val[v]);
        int x = get(h[v], h[v] + k - H, f1);
        int y = get(h[v], h[v] + k - H, f2);
        ans = add(
            ans,
            add(1LL * VAL * x % MOD,
                add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD)))));
        x = get(h[v], h[v] + k - H, F1);
        y = get(h[v], h[v] + k - H, F2);
        ans = add(
            ans,
            add(1LL * VAL * x % MOD,
                add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD)))));
      } else if (w == ce) {
        int H = h[X] - h[v] - 1;
        int VAL = add(val[X], -val[v]);
        int x = get(h[v] + 1, h[v] + k - H + 1, f1);
        int y = get(h[v] + 1, h[v] + k - H + 1, f2);
        ans = add(
            ans,
            add(1LL * VAL * x % MOD,
                add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD)))));
        x = get(h[v] - 1, h[v] + k - H - 1, F1);
        y = get(h[v] - 1, h[v] + k - H - 1, F2);
        ans = add(
            ans,
            add(1LL * VAL * x % MOD,
                add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD)))));
      } else {
        int H = h[X] - h[v] - 1;
        int VAL = add(val[X], -val[v]);
        int x = get(h[v] - 1, h[v] + k - H - 1, f1);
        int y = get(h[v] - 1, h[v] + k - H - 1, f2);
        ans = add(
            ans,
            add(1LL * VAL * x % MOD,
                add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD)))));
        x = get(h[v] + 1, h[v] + k - H + 1, F1);
        y = get(h[v] + 1, h[v] + k - H + 1, F2);
        ans = add(
            ans,
            add(1LL * VAL * x % MOD,
                add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD)))));
      }
    }
    for (int tmp = st[u]; tmp <= en[u]; tmp++) {
      int x = idx[tmp];
      if (w == ce) {
        add(h[x], 1, f1);
        add(h[x], val[x], f2);
      } else {
        add(h[x], 1, F1);
        add(h[x], val[x], F2);
        child[v].push_back(x);
      }
    }
  }
  if (e == ce) {
    int x = get(h[v], h[v] + k, f1);
    int y = get(h[v], h[v] + k, f2);
    ans =
        add(ans, add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD))));
    x = get(h[v] + 1, h[v] + k + 1, F1);
    y = get(h[v] + 1, h[v] + k + 1, F2);
    ans =
        add(ans, add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD))));
  } else {
    int x = get(h[v] + 1, h[v] + k + 1, f1);
    int y = get(h[v] + 1, h[v] + k + 1, f2);
    ans =
        add(ans, add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD))));
    x = get(h[v], h[v] + k, F1);
    y = get(h[v], h[v] + k, F2);
    ans =
        add(ans, add(y, add(1LL * x * a[v] % MOD, -(1LL * x * val[v] % MOD))));
  }
  for (auto u : child[v]) {
    add(h[u], -1, F1);
    add(h[u], -val[u], F2);
    add(h[u], 1, f1);
    add(h[u], val[u], f2);
  }
  add(h[v], 1, f1);
  add(h[v], val[v], f2);
  if (!keep) {
    for (int tmp = st[v]; tmp <= en[v]; tmp++) {
      int u = idx[tmp];
      add(h[u], -1, f1);
      add(h[u], -val[u], f2);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  h[1] = 1;
  dfs(1, -1, 0);
  sack(1, -1, 0, false);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum = add(sum, a[i]);
  }
  ans = add(sum, ans);
  cout << ans << '\n';
  return 0;
}
