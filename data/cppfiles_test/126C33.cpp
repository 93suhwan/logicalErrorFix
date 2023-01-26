#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
template <typename T>
T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <typename T>
void chkmax(T &x, const T &y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = x < y ? x : y;
}
const int N = 1010;
int n, m, u[N], nid[N];
ull c[N], tb[110];
vec G[N];
ll calc(int x, int v) { return abs(v - u[x]); }
void clear() {
  for (int i = (0); i <= (63); i++) tb[i] = 0;
}
bool ins(ull val, int fl) {
  for (int i = (63); i >= (0); i--)
    if (val >> i & 1ull) {
      if (tb[i])
        val ^= tb[i];
      else if (fl)
        return tb[i] = val, true;
      else
        return true;
    }
  return false;
}
const ll inf = 0x3f3f3f3f3f3f3f3f;
namespace F {
const int N = 1010;
const int M = N * N;
int h[N], now[N], d[N], cnt = 1, S, T, tot;
struct edge {
  ll v, w, nxt;
} e[M << 1];
inline void tlink(int x, int y, ll w) {
  e[++cnt] = (edge){y, w, h[x]};
  h[x] = cnt;
}
inline void link(int x, int y, ll w) {
  tlink(x, y, w);
  tlink(y, x, 0);
}
inline void setst(int s, int t) {
  S = s;
  T = t;
}
void init(int tot) {
  F ::tot = tot;
  for (int i = (0); i <= (tot); i++) h[i] = 0;
  setst(0, tot);
  cnt = 1;
}
queue<int> q;
bool bfs() {
  while (q.size()) q.pop();
  q.push(S);
  for (int i = (0); i <= (tot); i++) d[i] = 0;
  d[S] = 1;
  now[S] = h[S];
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = h[x], y; i; i = e[i].nxt)
      if (e[i].w && !d[y = e[i].v]) {
        d[y] = d[x] + 1;
        q.push(y);
        now[y] = h[y];
        if (y == T) return 1;
      }
  }
  return 0;
}
ll dinic(int x, ll flow) {
  if (x == T) return flow;
  ll res = flow;
  for (int i = now[x], y; i && res; i = e[i].nxt) {
    now[x] = i;
    if (e[i].w && d[y = e[i].v] == d[x] + 1) {
      ll k = dinic(y, min(res, e[i].w));
      if (!k) d[y] = 0;
      e[i].w -= k;
      e[i ^ 1].w += k;
      res -= k;
    }
  }
  return flow - res;
}
ll runit() {
  ll maxflow = 0, flow;
  while (bfs())
    while (flow = dinic(S, inf)) maxflow += flow;
  return maxflow;
}
}  // namespace F
int ans[N], p[N], q[N];
void divide(int l, int r, int lval, int rval) {
  if (l > r || lval == rval) {
    for (int i = (l); i <= (r); i++) ans[p[i]] = lval;
    return;
  }
  int mid = lval + rval >> 1, tot = 0;
  for (int i = (l); i <= (r); i++) nid[p[i]] = ++tot;
  F ::init(tot + 1);
  for (int i = (l); i <= (r); i++) {
    int x = p[i];
    for (auto y : G[x])
      if (nid[y]) F ::link(nid[y], nid[x], inf);
  }
  for (int i = (l); i <= (r); i++) {
    ll t1 = calc(p[i], mid), t2 = calc(p[i], mid + 1), delta = t1 - t2;
    if (delta < 0)
      F ::link(0, nid[p[i]], -delta);
    else
      F ::link(nid[p[i]], tot + 1, +delta);
  }
  F ::runit();
  int cur = l, top = 0, tcur = 0;
  for (int i = (l); i <= (r); i++) {
    if (F ::d[nid[p[i]]] == 0)
      q[++top] = p[i];
    else
      p[cur++] = p[i];
    nid[p[i]] = 0;
  }
  tcur = cur;
  for (int i = (1); i <= (top); i++) p[cur++] = q[i];
  divide(l, tcur - 1, lval, mid);
  divide(tcur, r, mid + 1, rval);
}
int a[N], b[N];
int main() {
  n = read<int>(), m = read<int>();
  int mx = 0;
  for (int i = (1); i <= (n); i++) u[i] = read<int>(), mx = max(mx, u[i]);
  for (int i = (1); i <= (m); i++) {
    int u = read<int>(), v = read<int>();
    G[u].emplace_back(v);
  }
  for (int i = (1); i <= (n); i++) p[i] = i;
  divide(1, n, 0, mx);
  ll ans = 0;
  for (int i = (1); i <= (n); i++)
    ans += calc(i, ::ans[i]), printf("%d ", ::ans[i]);
}
