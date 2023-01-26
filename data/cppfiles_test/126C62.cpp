#include <bits/stdc++.h>
using namespace std;
template <unsigned N, unsigned M>
struct Maxflow {
  long long const inf = 1e14;
  long long maxflow, s, t, tot = 1, target[M], pre[M], last[N], cap[M], deep[N],
                           cur[N];
  queue<long long> q;
  void add(long long x, long long y, long long z) {
    target[++tot] = y;
    pre[tot] = last[x];
    last[x] = tot;
    cap[tot] = z;
    target[++tot] = x;
    pre[tot] = last[y];
    last[y] = tot;
    cap[tot] = 0;
  }
  bool bfs() {
    for (long long i = s; i <= t; i++) deep[i] = 0, cur[i] = last[i];
    q.push(s);
    while (!q.empty()) {
      long long now = q.front();
      q.pop();
      for (long long i = last[now]; i; i = pre[i]) {
        long long tar = target[i];
        if (tar != s && cap[i] && (!deep[tar]))
          deep[tar] = deep[now] + 1, q.push(tar);
      }
    }
    return deep[t];
  }
  long long dfs(long long x, long long lim) {
    if ((!lim) || x == t) return lim;
    long long flow = 0;
    for (long long &i = cur[x]; i; i = pre[i]) {
      long long tar = target[i];
      if (cap[i] && deep[tar] == deep[x] + 1) {
        long long d = dfs(tar, min(lim, cap[i]));
        cap[i] -= d;
        cap[i ^ 1] += d;
        lim -= d;
        flow += d;
        if (!lim) break;
      }
    }
    return flow;
  }
  void dinic() {
    while (bfs()) maxflow += dfs(s, inf);
  }
  void init(long long n) {
    for (long long i = 0; i < n + 5; i++) last[i] = 0;
    tot = 1;
    maxflow = 0;
  }
};
struct BASE {
  unsigned long long b[65], id[65];
  void insert(unsigned long long x, unsigned long long &y) {
    for (long long i = 63; i >= 0; i--)
      if (x & (1ull << i)) {
        if (!b[i]) {
          b[i] = x;
          id[i] = y;
          return;
        }
        x ^= b[i], y ^= id[i];
      }
  }
} B1, B2;
Maxflow<1005, 1100005> g;
unsigned long long c[1005];
long long n, m, a[65], b[65], delta[1005], w[1005], id[1005], res, ANS[1005];
bool vis1[1005], vis2[1005], lk[1005][1005];
inline long long W(long long x, long long y) { return max(x, y) - min(x, y); }
void solve(vector<long long> v, long long l, long long r) {
  if (!v.size()) return;
  if (r == l + 1) {
    long long cnt = 0;
    g.init(v.size());
    g.t = v.size() + 1;
    for (auto i : v) {
      id[i] = ++cnt;
      delta[i] = (w[i] - r) - (w[i] - l);
      if (delta[i] < 0)
        g.add(0, cnt, -delta[i]);
      else
        g.add(cnt, g.t, delta[i]);
    }
    for (auto i : v)
      for (auto j : v)
        if (lk[i][j]) g.add(id[j], id[i], 1e9);
    g.dinic();
    for (auto i : v) {
      if (g.deep[id[i]])
        ANS[i] = r;
      else
        ANS[i] = l;
      res += g.deep[id[i]] ? ((w[i] - r)) : ((w[i] - l));
    }
    return;
  }
  long long mid = (l + r) >> 1, cnt = 0;
  g.init(v.size());
  g.t = v.size() + 1;
  for (auto i : v) {
    id[i] = ++cnt;
    delta[i] = W(mid + 1, w[i]) - W(mid, w[i]);
    if (delta[i] < 0)
      g.add(0, cnt, -delta[i]);
    else
      g.add(cnt, g.t, delta[i]);
  }
  for (auto i : v)
    for (auto j : v)
      if (lk[i][j]) g.add(id[j], id[i], 1e9);
  g.dinic();
  vector<long long> vl, vr;
  for (auto i : v) (g.deep[id[i]] ? vr : vl).push_back(i);
  solve(vl, l, mid), solve(vr, mid, r);
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &w[i]);
  for (long long i = 1; i <= m; i++) {
    long long x, y;
    cin >> x >> y;
    lk[y][x] = 1;
  }
  vector<long long> v;
  for (long long i = 1; i <= n; i++) v.push_back(i);
  solve(v, 0, 1e9);
  for (long long i = 1; i <= n; i++) cout << ANS[i] << " ";
  return 0;
}
