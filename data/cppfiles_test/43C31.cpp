#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int inf = 1e9 + 10;
const int N = 2e5 + 10;
const int LOG_DEP = 18;
int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x;
}
inline int add(int x, int y) {
  x += y;
  (x >= mod && (x -= mod));
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  (x < 0 && (x += mod));
  return x;
}
inline int mul(int x, int y) { return 1ll * x * y % mod; }
int qpow(int x, int y, int p = mod) {
  int res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}
struct Edge {
  int fr, to, nex, val, lim;
} e[N << 1];
int head[N], ecnt;
void adde(int fr, int to, int val, int lim) {
  e[++ecnt] = (Edge){fr, to, head[fr], val, lim};
  head[fr] = ecnt;
}
void addedge(int fr, int to, int val, int lim) {
  adde(fr, to, val, lim);
  adde(to, fr, val, lim);
}
struct Query {
  int typ;
  union {
    struct {
      int u, v, val;
    };
    struct {
      int id, x, lim;
    };
  };
} qn[N << 2];
int enj[N];
int n, q, tol[N], maxn[N], maxid[N];
int jp[N][LOG_DEP], jpmax[N][LOG_DEP], dep[N];
void dfs(int o, int fa) {
  dep[o] = dep[fa] + 1;
  for (int j = head[o]; j; j = e[j].nex)
    if (e[j].to != fa) {
      jp[e[j].to][0] = o;
      jpmax[e[j].to][0] = e[j].val;
      dfs(e[j].to, o);
    }
}
int dist(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int del = dep[u] - dep[v], ans = 0;
  for (int i = LOG_DEP - 1; i >= 0; i--)
    if (del & (1 << i)) {
      ans = max(ans, jpmax[u][i]);
      u = jp[u][i];
    }
  if (u == v) {
    return ans;
  }
  for (int i = LOG_DEP - 1; i >= 0; i--)
    if (jp[u][i] != jp[v][i]) {
      ans = max(ans, jpmax[u][i]);
      ans = max(ans, jpmax[v][i]);
      u = jp[u][i];
      v = jp[v][i];
    }
  ans = max(ans, max(jpmax[v][0], jpmax[u][0]));
  return ans;
}
struct DSU {
  int fa[N];
  void init(int n) {
    for (int i = 1; i <= n; i++) {
      maxid[i] = fa[i] = i;
      maxn[i] = enj[i];
    }
  }
  int getfa(int x) {
    if (fa[x] != x) return fa[x] = getfa(fa[x]);
    return fa[x];
  }
  void merge(int x, int y) {
    x = getfa(x);
    y = getfa(y);
    if (x == y) return;
    if (maxn[x] != maxn[y]) {
      fa[x] = y;
      if (maxn[x] > maxn[y]) {
        maxn[y] = maxn[x];
        maxid[y] = maxid[x];
        tol[y] = tol[x];
      }
    } else {
      fa[x] = y;
      tol[y] = max(dist(maxid[x], maxid[y]), max(tol[x], tol[y]));
    }
  }
} dsu;
pair<int, int> ans[N];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &enj[i]);
  for (int i = 1; i < n; i++) {
    int u = read(), v = read(), lim = read(), val = read();
    addedge(u, v, val, lim);
  }
  dsu.init(n);
  dfs(1, 1);
  for (int i = 1; i <= LOG_DEP - 1; i++) {
    for (int j = 1; j <= n; j++) {
      jpmax[j][i] = max(jpmax[j][i - 1], jpmax[jp[j][i - 1]][i - 1]);
      jp[j][i] = jp[jp[j][i - 1]][i - 1];
    }
  }
  for (int i = 1; i <= q; i++) {
    qn[i].typ = 0;
    qn[i].lim = read();
    qn[i].x = read();
    qn[i].id = i;
  }
  for (int i = q + 1; i < q + n; i++) {
    qn[i].typ = 1;
    qn[i].u = e[(i - q) << 1].fr;
    qn[i].v = e[(i - q) << 1].to;
    qn[i].val = e[(i - q) << 1].lim;
  }
  sort(qn + 1, qn + 1 + q + n, [](Query x, Query y) -> bool {
    return (x.val > y.val) || (x.val == y.val && x.typ > y.typ);
  });
  for (int i = 1; i < q + n; i++) {
    if (qn[i].typ == 1) {
      dsu.merge(qn[i].u, qn[i].v);
    } else {
      int belong = dsu.getfa(qn[i].x);
      ans[qn[i].id].first = maxn[belong];
      ans[qn[i].id].second = max(tol[belong], dist(qn[i].x, maxid[belong]));
    }
  }
  for (int i = 1; i <= q; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
