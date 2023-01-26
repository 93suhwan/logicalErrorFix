#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmx(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmn(T &x, T y) {
  return x > y ? x = y, true : false;
}
const int maxn = 2e5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int inv2 = (mod + 1) / 2;
int cnt, head[maxn + 5];
int a[maxn + 5];
int n, k, u, v, w;
int rt, all, mxsum, size[maxn + 5], mx[maxn + 5], vis[maxn + 5];
pair<int, int> f[2][maxn + 5];
int ans;
struct Edge {
  int to, next, w;
} e[maxn * 2 + 5];
inline int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline int mul(int a, int b) { return 1ll * a * b % mod; }
void add(int u, int v, int w) {
  e[++cnt] = (Edge){v, head[u], w}, head[u] = cnt;
}
void findrt(int u, int par) {
  size[u] = 1, mx[u] = 0;
  for (int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
    if (v != par && !vis[v]) {
      findrt(v, u);
      size[u] += size[v];
      chkmx(mx[u], size[v]);
    }
  chkmx(mx[u], all - size[u]);
  if (mx[rt] > mx[u]) rt = u;
}
void dfs(int u, int par, int sum, int lst, int val, int opt) {
  if (chkmx(mxsum, sum)) f[0][sum] = f[1][sum] = {0, 0};
  f[opt][sum].first++;
  f[opt][sum].second = add(f[opt][sum].second, val);
  for (int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
    if (v != par && !vis[v]) {
      dfs(v, u, sum + (lst != e[i].w), e[i].w, val + a[v], opt);
    }
}
pair<int, int> operator*(pair<int, int> a, pair<int, int> b) {
  return {a.first * b.first,
          add(mul(a.first, b.second), mul(a.second, b.first))};
}
pair<int, int> c[maxn + 5];
void calc(pair<int, int> *a, pair<int, int> *b, int k, int lim, int t, int v) {
  for (int i = (1); i <= int(min(k, lim)); i++)
    c[i].second = add(c[i - 1].second, a[i].second),
    c[i].first = c[i - 1].first + a[i].first;
  for (int i = (1); i <= int(min(k, lim)); i++)
    ans = add(ans, mul(t, add((b[i] * c[k - i]).second,
                              mul((b[i] * c[k - i]).first, v))));
}
void solve(int u) {
  vis[u] = 1, mxsum = 0;
  for (int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
    if (!vis[v]) dfs(v, u, 1, e[i].w, a[v], e[i].w);
  calc(f[0], f[0], k + 1, mxsum, 1, a[u]);
  calc(f[1], f[1], k + 1, mxsum, 1, a[u]);
  calc(f[0], f[1], k, mxsum, 2, a[u]);
  for (int i = (1); i <= int(min(mxsum, k)); i++)
    ans = add(ans, mul(2, add(f[0][i].second, f[1][i].second))),
    ans = add(ans, mul(2, mul(add(f[0][i].first, f[1][i].first), a[u])));
  ans = add(ans, add(a[u], a[u]));
  for (int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
    if (!vis[v]) {
      mxsum = 0;
      dfs(v, u, 1, e[i].w, a[v], e[i].w);
      calc(f[0], f[0], k + 1, mxsum, mod - 1, a[u]);
      calc(f[1], f[1], k + 1, mxsum, mod - 1, a[u]);
      calc(f[0], f[1], k + 1, mxsum, mod - 2, a[u]);
      findrt(v, v), all = size[v], rt = 0, findrt(v, v), solve(rt);
    }
}
int main() {
  cin >> n >> k;
  k++;
  for (int i = (1); i <= int(n); i++) cin >> a[i];
  for (int i = (2); i <= int(n); i++)
    cin >> u >> v >> w, add(u, v, w), add(v, u, w);
  all = n, mx[rt = 0] = inf, findrt(1, 1), solve(rt);
  cout << mul(ans, inv2) << '\n';
  return 0;
}
