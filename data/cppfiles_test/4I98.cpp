#include <bits/stdc++.h>
using namespace std;
const int maxn = 210000;
const int mod = 1e9 + 7;
int n, k, a[maxn];
struct Tree {
  long long C[maxn];
  int n;
  void init(int N) {
    this->n = N + 4;
    memset(C, 0, sizeof(C[0]) * (n + 2));
  }
  void add(int x, long long d) {
    x += 1;
    for (int i = x; i <= n; i += ((i) & (-i))) C[i] = (C[i] + d) % mod;
  }
  long long sum(int x) {
    if (x < 0) return 0;
    x += 1;
    long long ret = 0;
    for (int i = x; i > 0; i -= ((i) & (-i))) ret += C[i];
    return ret % mod;
  }
} value[2], times[2];
vector<pair<int, int>> G[maxn];
int vis[maxn], siz[maxn], f[maxn], pos, sum;
long long answer = 0;
void init(int n) {
  for (int i = 0; i <= n; ++i) {
    vis[i] = false;
    G[i].clear();
  }
}
void getroot(int x, int fa) {
  f[x] = 0;
  siz[x] = 1;
  for (auto [y, w] : G[x])
    if (y != fa && !vis[y]) {
      getroot(y, x);
      f[x] = max(f[x], siz[y]);
      siz[x] += siz[y];
    }
  f[x] = max(f[x], sum - siz[x]);
  if (f[x] < f[pos]) pos = x;
}
void dfs1(int x, int fa, long long w, int color, int cnt, int start) {
  w += a[x];
  answer += value[start].sum(k - cnt);
  answer += times[start].sum(k - cnt) * w % mod;
  answer += value[start ^ 1].sum(k - cnt - 1);
  answer += times[start ^ 1].sum(k - cnt - 1) * w % mod;
  for (auto [y, t] : G[x])
    if (y != fa && !vis[y]) {
      dfs1(y, x, w, t, cnt + (t != color), start);
    }
}
void dfs2(int x, int fa, long long w, int color, int cnt, int start) {
  w += a[x];
  if (cnt <= k) {
    answer += w;
    value[start].add(cnt, w);
    times[start].add(cnt, 1);
  }
  for (auto [y, t] : G[x])
    if (y != fa && !vis[y]) {
      dfs2(y, x, w, t, cnt + (t != color), start);
    }
}
void calc(int x, int size) {
  answer += a[x];
  for (int i = 0; i < 2; ++i) {
    value[i].init(size);
    times[i].init(size);
  }
  for (auto [y, t] : G[x])
    if (!vis[y]) {
      dfs1(y, x, 0, t, 0, t);
      dfs2(y, x, a[x], t, 0, t);
    }
  answer %= mod;
}
void solve(int x, int cnt) {
  pos = maxn - 1;
  f[pos] = sum = cnt;
  getroot(x, -1);
  int root = pos;
  vis[root] = 1;
  calc(root, cnt);
  for (auto [y, w] : G[root])
    if (!vis[y]) solve(y, siz[y] < siz[root] ? siz[y] : cnt - siz[root]);
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  init(n);
  for (int i = 1; i < n; ++i) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    G[x].emplace_back(y, w);
    G[y].emplace_back(x, w);
  }
  solve(1, n);
  answer %= mod;
  printf("%lld\n", answer);
  return 0;
}
