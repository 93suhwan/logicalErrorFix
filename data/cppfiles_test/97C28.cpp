#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
const int N = 200005;
vector<int> adj[N];
int n, m, fa[N], a[N], siz[N], dfn[N], tmr;
long long ans[N];
vector<int> e[N];
struct node {
  long long val, key;
  int siz, u;
  node() { val = siz = 0; }
  node(long long v_, int s_, int u_) {
    val = v_, siz = s_, u = u_, key = ceil((double)-val / siz);
  }
  inline bool operator==(const node &t) const {
    return key == t.key && u == t.u;
  }
  inline bool operator<(const node &t) const {
    return key != t.key ? key > t.key : u > t.u;
  }
};
struct QUE {
  int u, x, id;
  inline bool operator<(const QUE &t) const { return x < t.x; }
} q[N];
namespace Set {
priority_queue<node> pq, del;
inline void insert(const node &t) { pq.push(t); }
inline void erase(const node &t) { del.push(t); }
inline node top() {
  while (!del.empty() && del.top() == pq.top()) del.pop(), pq.pop();
  return pq.top();
}
inline bool empty() { return pq.size() == del.size(); }
}  // namespace Set
int F[N];
struct BIT {
  long long tr[N];
  inline void add(int x, long long d) {
    if (!x) return;
    for (int i = x; i <= n; i += i & -i) tr[i] += d;
  }
  inline long long ask(int x) {
    long long res = 0;
    for (int i = x; i > 0; i -= i & -i) res += tr[i];
    return res;
  }
  inline long long ask(int l, int r) { return ask(r) - ask(l - 1); }
} tr[2];
inline int anc(int x) { return x == F[x] ? x : F[x] = anc(F[x]); }
inline void init_DSU() {
  for (int i = 1, iend = n; i <= iend; ++i) F[i] = i;
}
int heng[N], hengid;
void dfs1(int u, int fa) {
  ++hengid, heng[hengid] = u;
  siz[u] = 1, dfn[u] = ++tmr;
  for (int v : adj[u]) {
    if (v == fa) continue;
    a[u]++;
    ::fa[v] = u;
    dfs1(v, u), siz[u] += siz[v];
  }
  if (u != 1) Set::insert(node(a[u], 1, u));
}
inline void link(int u) {
  int sz = (tr[0].ask(dfn[u], dfn[u] + siz[u] - 1));
  long long sm = (tr[1].ask(dfn[u], dfn[u] + siz[u] - 1));
  F[u] = anc(fa[u]);
  if (F[u] != 1) {
    Set::erase(node((tr[1].ask(dfn[F[u]], dfn[F[u]] + siz[F[u]] - 1)),
                    (tr[0].ask(dfn[F[u]], dfn[F[u]] + siz[F[u]] - 1)), F[u]));
  }
  tr[0].add(dfn[fa[u]], sz), tr[1].add(dfn[fa[u]], sm);
  if (F[u] != 1) {
    int gfa = fa[F[u]];
    tr[0].add(dfn[gfa], -sz), tr[1].add(dfn[gfa], -sm);
    Set::insert(node((tr[1].ask(dfn[F[u]], dfn[F[u]] + siz[F[u]] - 1)),
                     (tr[0].ask(dfn[F[u]], dfn[F[u]] + siz[F[u]] - 1)), F[u]));
  }
}
signed main() {
  n = read(), init_DSU();
  for (int i = 1, iend = n - 1; i <= iend; ++i) {
    int u = read(), v = read();
    adj[u].push_back(v), adj[v].push_back(u);
  }
  m = read();
  for (int i = 1, iend = m; i <= iend; ++i) {
    q[i].u = read(), q[i].x = -read() - 1, q[i].id = i;
    ans[i] -= q[i].x;
  }
  dfs1(1, 0), sort(q + 1, q + m + 1);
  for (int _ = 1, _end = n; _ <= _end; ++_) {
    int i = heng[_];
    tr[0].add(dfn[i], 1), tr[1].add(dfn[i], a[i]);
    if (i != 1) tr[0].add(dfn[fa[i]], -1), tr[1].add(dfn[fa[i]], -a[i]);
  }
  for (int i = 1, iend = m; i <= iend; ++i) {
    int u = q[i].u, x = q[i].x;
    while (!Set::empty()) {
      node now = Set::top();
      if (now.key <= x)
        Set::erase(now), link(now.u);
      else
        break;
    }
    int l = dfn[u], r = dfn[u] + siz[u] - 1;
    ans[q[i].id] += tr[0].ask(l, r) * q[i].x + tr[1].ask(l, r);
  }
  for (int i = 1, iend = m; i <= iend; ++i) printf("%lld\n", ans[i]);
  return 0;
}
