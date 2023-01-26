#include <bits/stdc++.h>
template <typename T>
bool chkmin(T &a, T b) {
  return (b < a) ? a = b, 1 : 0;
}
template <typename T>
bool chkmax(T &a, T b) {
  return (b > a) ? a = b, 1 : 0;
}
long long ksm(long long a, long long b) {
  if (b == 0) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % 1000000007;
  if (b & 1) ns = ns * a % 1000000007;
  return ns;
}
using namespace std;
const int maxn = 300005;
int n;
int a[maxn];
int fa[maxn];
int fl[maxn];
int gfa(int a) {
  if (fa[a] == a) return a;
  return fa[a] = gfa(fa[a]);
}
int ok[maxn], hv[maxn];
int t = 1;
int gnx() {
  while (hv[t]) t++;
  return t;
}
vector<pair<long long, long long> > rg;
void fillx(int l, int r) {
  for (int j = l; j <= r; j += 2) {
    int cc = gnx();
    a[j] = a[j + 1] = cc;
    hv[cc] = 1;
  }
}
void fillrg(int id, int to) {
  pair<long long, long long> cur = rg[id];
  if (to == a[cur.first - 1]) {
    a[cur.first] = to;
    fillx(cur.first + 1, cur.second);
  } else {
    a[cur.second] = to;
    fillx(cur.first, cur.second - 1);
  }
}
namespace mat {
using namespace std;
const int BufL = 1100000;
char buf[BufL], *ins = buf, *outs = buf;
inline int getint() {
  while (*ins < '0' || *ins > '9') ++ins;
  int res = 0;
  while (*ins >= '0' && *ins <= '9') res = res * 10 + *ins++ - '0';
  return res;
}
inline void putint(int x, char c = ' ') {
  if (!x)
    *outs++ = '0';
  else {
    char s_pool[4], *s = s_pool;
    for (; x; x /= 10) *s++ = x % 10 + '0';
    while (s-- != s_pool) *outs++ = *s;
  }
  *outs++ = c;
}
const int MaxN = 601;
const int MaxM = MaxN * (MaxN - 1);
int n, m;
int nE, adj[MaxN];
int next[MaxM], go[MaxM];
inline void addEdge(const int &u, const int &v) {
  next[++nE] = adj[u], go[adj[u] = nE] = v;
  next[++nE] = adj[v], go[adj[v] = nE] = u;
}
int n_matches;
int mate[MaxN];
int q_n;
int q[MaxN];
int book_mark;
int book[MaxN];
int type[MaxN];
int fa[MaxN];
int bel[MaxN];
inline void augment(int u) {
  while (u) {
    int nu = mate[fa[u]];
    mate[mate[u] = fa[u]] = u;
    u = nu;
  }
}
inline int get_lca(int u, int v) {
  ++book_mark;
  while (true) {
    if (u) {
      if (book[u] == book_mark) return u;
      book[u] = book_mark;
      u = bel[fa[mate[u]]];
    }
    swap(u, v);
  }
}
inline void go_up(int u, int v, const int &mv) {
  while (bel[u] != mv) {
    fa[u] = v;
    v = mate[u];
    if (type[v] == 1) type[q[++q_n] = v] = 0;
    if (bel[u] == u) bel[u] = mv;
    if (bel[v] == v) bel[v] = mv;
    u = fa[v];
  }
}
inline void after_go_up() {
  for (int u = 1; u <= n; ++u) bel[u] = bel[bel[u]];
}
inline bool match(const int &sv) {
  for (int u = 1; u <= n; ++u) bel[u] = u, type[u] = -1;
  type[q[q_n = 1] = sv] = 0;
  for (int i = 1; i <= q_n; ++i) {
    int u = q[i];
    for (int e = adj[u]; e; e = next[e]) {
      int v = go[e];
      if (!~type[v]) {
        fa[v] = u, type[v] = 1;
        int nu = mate[v];
        if (!nu) {
          augment(v);
          return true;
        }
        type[q[++q_n] = nu] = 0;
      } else if (!type[v] && bel[u] != bel[v]) {
        int lca = get_lca(u, v);
        go_up(u, v, lca);
        go_up(v, u, lca);
        after_go_up();
      }
    }
  }
  return false;
}
inline void calc_max_match() {
  n_matches = 0;
  for (int u = 1; u <= n; ++u)
    if (!mate[u] && match(u)) ++n_matches;
}
vector<long long> cal(int x, vector<pair<long long, long long> > a) {
  n = x;
  for (auto v : a) addEdge(v.first, v.second);
  calc_max_match();
  vector<long long> res(n + 1);
  for (int u = 1; u <= n; u++) res[u] = mate[u];
  return res;
}
}  // namespace mat
const int h = 605;
int id[h][h];
int usa[h];
vector<pair<long long, long long> > neg[maxn];
void ade(int u, int v, int ind) {
  neg[u].push_back(make_pair(v, ind));
  neg[v].push_back(make_pair(u, ind));
}
void dfs(int u, int f) {
  for (auto v : neg[u]) {
    if (v.first == f) continue;
    fillrg(v.second, v.first);
    dfs(v.first, u);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), hv[a[i]] = 1;
  for (int i = 1; i <= n; i++) fa[i] = i, fl[i] = 0;
  for (int i = 1; i <= n;) {
    if (a[i]) {
      i++;
      continue;
    }
    int j = i;
    while (j <= n && !a[j]) j++;
    rg.push_back(make_pair(i, j - 1));
    i = j;
  }
  vector<pair<long long, long long> > nx;
  for (auto v : rg) {
    if (v.first == 1) {
      while (v.first + 1 <= v.second) {
        int cc = gnx();
        a[v.first] = a[v.first + 1] = cc;
        hv[cc] = 1;
        v.first += 2;
      }
      if (v.first == v.second) {
        if (v.first != n)
          a[v.first] = a[v.first + 1];
        else
          a[v.first] = a[v.first - 1];
      }
    } else if (v.second == n) {
      while (v.second - 1 >= v.first) {
        int cc = gnx();
        a[v.second - 1] = a[v.second] = cc;
        hv[cc] = 1;
        v.second -= 2;
      }
      if (v.first == v.second) a[v.first] = a[v.first - 1];
    } else
      nx.push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    hv[a[i]] = 1;
    if (a[i] == a[i + 1]) fl[a[i]] = a[i];
  }
  rg = nx;
  for (int i = 0; i < rg.size(); i++) {
    pair<long long, long long> v = rg[i];
    int le = v.second - v.first + 1;
    if (le % 2 == 1) {
      int aa = a[v.first - 1], b = a[v.second + 1];
      int af = gfa(aa), bf = gfa(b);
      if (af == bf)
        fl[af] = aa, fillrg(i, aa);
      else {
        fa[af] = bf;
        if (fl[af]) fl[bf] = fl[af];
        ade(aa, b, i);
      }
    }
  }
  vector<array<int, 3> > g;
  vector<pair<long long, long long> > ceg;
  for (int i = 0; i < rg.size(); i++) {
    pair<long long, long long> v = rg[i];
    int le = v.second - v.first + 1;
    if (le % 2 == 0) {
      int aa = a[v.first - 1], b = a[v.second + 1];
      int af = gfa(aa), bf = gfa(b);
      if (fl[af] || fl[bf]) continue;
      g.push_back(array<int, 3>{af, bf, i});
      ceg.push_back(make_pair(af, bf));
    }
  }
  int dd = min(600, n);
  vector<long long> res = mat::cal(dd, ceg);
  for (auto v : g) id[v[0]][v[1]] = v[2], id[v[1]][v[0]] = v[2];
  for (int i = 1; i <= dd; i++) {
    if (res[i]) {
      int cid = id[i][res[i]];
      pair<long long, long long> v = rg[cid];
      int aa = a[v.first - 1], b = a[v.second + 1];
      if (gfa(b) == i) swap(aa, b);
      dfs(aa, 0);
      usa[id[i][res[i]]] = 1;
    } else {
      if (fa[i] == i) {
        if (fl[i])
          dfs(fl[i], 0);
        else
          dfs(i, 0);
      }
    }
  }
  for (int i = 0; i < rg.size(); i++) {
    pair<long long, long long> v = rg[i];
    int le = v.second - v.first + 1;
    if (le % 2 == 0) {
      if (usa[i]) {
        a[v.first] = a[v.first - 1], a[v.second] = a[v.second + 1];
        fillx(v.first + 1, v.second - 1);
      } else
        fillx(v.first, v.second);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return (0 - 0);
}
