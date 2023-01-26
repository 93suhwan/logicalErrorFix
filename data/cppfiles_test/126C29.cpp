#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int w = 1, c = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') w = -1;
  for (; isdigit(ch); ch = getchar()) c = (c << 1) + (c << 3) + (ch ^ 48);
  return w * c;
}
const int M = 1010, E = M * M;
int n;
const long long inf = 1e12;
namespace FLOW {
int head[M], cur[M], S, T, nxt[E], to[E], cnt;
long long w[E];
void add(int x, int y, long long z) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
  w[cnt] = z;
}
void jb(int x, int y, long long z) {
  add(x, y, z);
  add(y, x, 0);
}
int q[M], dep[M];
bool bfs() {
  int l = 1, r = 1;
  q[1] = S;
  memset(dep, 0, sizeof dep);
  dep[S] = 1;
  while (l <= r) {
    int x = q[l++];
    for (int i = head[x]; i; i = nxt[i]) {
      int y = to[i];
      if (w[i] && !dep[y]) {
        dep[y] = dep[x] + 1;
        q[++r] = y;
      }
    }
  }
  return dep[T];
}
long long dfs(int x, long long flow) {
  if (x == T || !flow) return flow;
  long long res = flow;
  for (int &i = cur[x]; i; i = nxt[i]) {
    int y = to[i];
    if (dep[y] == dep[x] + 1 && w[i]) {
      long long ff = dfs(y, min(w[i], res));
      res -= ff;
      w[i] -= ff;
      w[i ^ 1] += ff;
      if (!res) return flow;
    }
  }
  return flow - res;
}
void init() {
  cnt = 1;
  memset(head, 0, sizeof head);
  S = 0;
  T = n + 1;
}
long long MF() {
  long long ret = 0;
  while (bfs()) {
    memcpy(cur, head, sizeof cur);
    ret += dfs(S, inf);
  }
  return ret;
}
}  // namespace FLOW
vector<int> P[M];
int ans[M], v[M], a[M], b[M], tp[M], p[M];
bool in[M];
int m, dfn[M], low[M], tim, stk[M], tpp, SCC, bl[M], sz[M];
vector<int> scc[M];
long long suan(int id, int mid) {
  long long val = 0;
  for (int x : scc[id]) {
    val += abs(a[x] - mid) - abs(a[x] - mid - 1);
  }
  return val;
}
void solve(int l, int r, int ll, int rr) {
  if (ll > rr) return;
  if (l == r) {
    for (int i = (ll); i <= (rr); ++i) ans[p[i]] = l;
    return;
  }
  int mid = (l + r >> 1);
  for (int i = (ll); i <= (rr); ++i) in[p[i]] = 1;
  FLOW::init();
  int tmp = 0;
  for (int i = (ll); i <= (rr); ++i) {
    int x = p[i];
    long long val = suan(x, mid);
    if (val >= 0)
      tmp += val, FLOW::jb(FLOW::S, x, val);
    else
      FLOW::jb(x, FLOW::T, -val);
    for (int j = (0); j <= (((int)P[x].size() - 1)); ++j) {
      int y = P[x][j];
      if (in[y]) FLOW::jb(x, y, inf);
    }
  }
  FLOW::MF();
  int tl = ll, tr = rr;
  for (int i = (ll); i <= (rr); ++i) {
    int x = p[i];
    if (FLOW::dep[x])
      tp[tr] = x, tr--;
    else
      tp[tl] = x, tl++;
  }
  for (int i = (ll); i <= (rr); ++i) p[i] = tp[i];
  for (int i = (ll); i <= (rr); ++i) in[p[i]] = 0;
  solve(l, mid, ll, tl - 1);
  solve(mid + 1, r, tr + 1, rr);
}
vector<int> ve[M];
void tarjan(int x) {
  dfn[x] = low[x] = ++tim;
  stk[++tpp] = x;
  for (int y : ve[x]) {
    if (!dfn[y])
      tarjan(y), low[x] = min(low[x], low[y]);
    else if (!bl[y]) {
      low[x] = min(low[x], dfn[y]);
    }
  }
  if (low[x] == dfn[x]) {
    SCC++;
    while (1) {
      int y = stk[tpp--];
      bl[y] = SCC;
      sz[SCC]++;
      scc[SCC].push_back(y);
      v[SCC] = a[y];
      if (y == x) break;
    }
  }
}
bool edge[1010][1010];
void init() {
  for (int i = (1); i <= (n); ++i)
    if (!dfn[i]) tarjan(i);
  for (int x = (1); x <= (n); ++x) {
    for (int y : ve[x]) {
      if (bl[x] ^ bl[y] && !edge[bl[x]][bl[y]]) {
        P[bl[x]].push_back(bl[y]);
        edge[bl[x]][bl[y]] = 1;
      }
    }
  }
}
int main() {
  n = read();
  m = read();
  int mx = 0;
  for (int i = (1); i <= (n); ++i) a[i] = read(), mx = max(mx, a[i]);
  for (int i = (1); i <= (m); ++i) {
    int x = read(), y = read();
    ve[x].push_back(y);
  }
  init();
  for (int i = (1); i <= (SCC); ++i) p[i] = i;
  solve(0, mx, 1, SCC);
  long long finalans = 0;
  for (int i = (1); i <= (n); ++i)
    cout << ans[bl[i]] << " ", finalans += abs(a[i] - ans[bl[i]]);
  cout << "\n";
  return 0;
}
