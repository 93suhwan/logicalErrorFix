#include <bits/stdc++.h>
using namespace std;
char _c;
bool _f;
template <class T>
inline void IN(T& x) {
  x = 0, _f = 0;
  while (_c = getchar(), !isdigit(_c))
    if (_c == '-') _f = 1;
  while (isdigit(_c)) x = x * 10 + _c - '0', _c = getchar();
  if (_f) x = -x;
}
template <class T>
inline void chkmin(T& x, T y) {
  if (x > y) x = y;
}
template <class T>
inline void chkmax(T& x, T y) {
  if (x < y) x = y;
}
const int N = 3e5 + 5;
const int LogN = 19;
long long ans[N];
bool vis[N];
int n, q, k, atop, a[N], dep[N], asta[N], fa[N][LogN];
struct Node {
  int l, r, id;
};
vector<Node> qsta[N];
vector<int> to[N];
void dfs1(int u, int pre) {
  dep[u] = dep[pre] + 1, fa[u][0] = pre;
  for (int i = 1; i <= 18; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : to[u]) dfs1(v, u);
}
long long res[N];
set<int> S[N];
void dfs2(int u, int pre) {
  vis[u] = true;
  S[u].insert(u);
  for (auto v : to[u]) {
    dfs2(v, u);
    for (auto ele : S[v]) S[u].insert(ele);
  }
  for (auto que : qsta[u]) {
    int buf = (que.r - (que.l + ((u - que.l + k - 1) / k) * k) + k) / k;
    ans[que.id] = res[que.l] + 1ll * a[u] * buf;
  }
  if (pre) {
    int lim = (pre - u) % k;
    for (auto ele : S[u]) {
      int buf = k - ((u % k) - (ele % k) + k) % k;
      if (buf < lim)
        res[ele] += 1ll * a[u] * ((pre - u + k - 1) / k);
      else
        res[ele] += 1ll * a[u] * ((pre - u + k - 1) / k - 1);
    }
    for (auto ele : S[u])
      if ((u % k) == (ele % k)) res[ele] += a[u];
  }
}
int main() {
  IN(n), IN(q), IN(k);
  for (int i = 1; i <= n; ++i) IN(a[i]);
  for (int i = 1; i <= n; ++i) {
    while (atop && a[asta[atop]] > a[i]) to[i].push_back(asta[atop]), --atop;
    asta[++atop] = i;
  }
  for (int i = n; i >= 1; --i)
    if (!dep[i]) dfs1(i, 0);
  for (int l, r, t, i = 1; i <= q; ++i) {
    IN(l), IN(r), t = l;
    for (int i = 18; i >= 0; --i)
      if (fa[t][i] && fa[t][i] <= r) t = fa[t][i];
    qsta[t].push_back((Node){l, r, i});
  }
  for (int i = n; i >= 1; --i)
    if (!vis[i]) dfs2(i, 0);
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
