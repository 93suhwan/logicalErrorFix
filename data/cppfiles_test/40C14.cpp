#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 3e5 + 10;
const int md = 1e9 + 7;
inline int add(int x, int y) { return (x += y) >= md ? x -= md : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x += md : x; }
inline int mul(int x, int y) { return 1ll * x * y % md; }
inline int qpow(int x, ll n, int mod = md) {
  int r = 1;
  while (n > 0) {
    if (n & 1) r = 1ll * r * x % mod;
    n >>= 1;
    x = 1ll * x * x % mod;
  }
  return r;
}
int fa[maxn][20];
vector<int> G[maxn];
int dep[maxn], vis[maxn];
void dfs(int x, int f) {
  fa[x][0] = f;
  vis[x] = 1;
  dep[x] = dep[f] + 1;
  for (auto v : G[x]) {
    if (vis[v]) continue;
    dfs(v, x);
  }
}
int X[maxn], Y[maxn];
int Mark[maxn], cnt = 0;
int Lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 19; i >= 0; i--)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; i--) {
    int f1 = fa[x][i], f2 = fa[y][i];
    if (f1 != f2) {
      x = f1, y = f2;
    }
  }
  return fa[x][0];
}
void work() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }
  dfs(1, 0);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> X[i] >> Y[i];
    if (!Mark[X[i]])
      Mark[X[i]] = 1, cnt++;
    else
      Mark[X[i]] = 0, cnt--;
    if (!Mark[Y[i]])
      Mark[Y[i]] = 1, cnt++;
    else
      Mark[Y[i]] = 0, cnt--;
  }
  if (cnt) {
    cout << "NO\n" << cnt / 2 << "\n";
    return;
  }
  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= n; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  }
  vector<int> ans1, ans2;
  cout << "YES\n";
  for (int i = 1; i <= q; i++) {
    int rt = Lca(X[i], Y[i]);
    ans1.clear();
    ans2.clear();
    int x = X[i];
    while (x != rt) {
      ans1.emplace_back(x);
      x = fa[x][0];
    }
    int y = Y[i];
    while (y != rt) {
      ans2.emplace_back(y);
      y = fa[y][0];
    }
    std::reverse(ans2.begin(), ans2.end());
    cout << ans1.size() + ans2.size() + 1 << "\n";
    for (auto x1 : ans1) cout << x1 << " ";
    cout << rt << " ";
    for (auto y1 : ans2) cout << y1 << " ";
    cout << "\n";
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  work();
}
