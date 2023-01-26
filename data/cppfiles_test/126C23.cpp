#include <bits/stdc++.h>
using namespace std;
using ui64 = unsigned long long;
using i64 = long long;
const int MAXN = 1000;
const int MAXM = 64;
const ui64 INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
i64 v[MAXN + 5];
i64 val[MAXN + 5];
ui64 c[MAXN + 5];
vector<int> leq[MAXN + 5], geq[MAXN + 5];
int ncnt;
struct Edge {
  int tot;
  int fst[MAXN + 5], nxt[MAXN * MAXM * 10], to[MAXN * MAXM * 10];
  i64 f[MAXN * MAXM * 10];
  Edge() {
    tot = -1;
    memset(fst, -1, sizeof(fst));
    memset(nxt, -1, sizeof(nxt));
  }
  void clear() {
    memset(fst, -1, sizeof(int) * (ncnt + 1));
    memset(nxt, -1, sizeof(int) * (tot + 1));
    memset(f, 0, sizeof(i64) * (tot + 1));
    memset(to, 0, sizeof(int) * (tot + 1));
    tot = -1;
  }
  void _add(int u, int v, i64 w) {
    ++tot;
    nxt[tot] = fst[u];
    fst[u] = tot;
    to[tot] = v;
    f[tot] = w;
  }
  void add(int u, int v, i64 w) {
    _add(u, v, w);
    _add(v, u, 0);
  }
} e;
struct Basis {
  ui64 a[MAXM], b[MAXM];
  bool insert(ui64 x, int id) {
    ui64 S = 1ull << (id - 1);
    for (int i = MAXM - 1; ~i; --i) {
      if (!((x >> i) & 1)) continue;
      if (!a[i]) {
        a[i] = x;
        b[i] = S;
        return true;
      }
      x ^= a[i];
      S ^= b[i];
    }
    return false;
  }
  vector<int> num;
  bool query(ui64 x) {
    num.clear();
    ui64 S = 0;
    for (int i = MAXM - 1; ~i; --i) {
      if (!((x >> i) & 1)) continue;
      x ^= a[i];
      S ^= b[i];
    }
    for (int i = 0; i < MAXM; ++i)
      if ((S >> i) & 1) num.push_back(i + 1);
    return x == 0;
  }
} A, B;
int S, T;
int dep[MAXN + 5], cure[MAXN + 5];
bool get_dep() {
  static queue<int> q;
  memset(dep, 0, sizeof(int) * (ncnt + 1));
  q.push(S);
  dep[S] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int k = e.fst[u]; ~k; k = e.nxt[k]) {
      int to = e.to[k], f = e.f[k];
      if (f > 0 && !dep[to]) {
        dep[to] = dep[u] + 1;
        q.push(to);
      }
    }
  }
  return dep[T] != 0;
}
i64 Augment(int x, i64 flow) {
  if (x == T) return flow;
  i64 rest = flow;
  for (int &k = cure[x]; ~k; k = e.nxt[k]) {
    int to = e.to[k];
    i64 f = e.f[k];
    if (f > 0 && dep[to] == dep[x] + 1) {
      i64 tmp = Augment(to, min(rest, f));
      e.f[k] -= tmp;
      e.f[k ^ 1] += tmp;
      rest -= tmp;
      if (!tmp) dep[to] = -1;
      if (!rest) break;
    }
  }
  return flow - rest;
}
i64 Dinic() {
  i64 res = 0;
  while (get_dep()) {
    i64 tmp = 0;
    memcpy(cure, e.fst, sizeof(int) * (ncnt + 1));
    while ((tmp = Augment(S, INF)) != 0) res += tmp;
  }
  return res;
}
i64 myabs(i64 x) { return x < 0 ? -x : x; }
int idx[MAXN | 1];
void solve(int al, int ar, i64 vl, i64 vr) {
  if (al > ar) return;
  if (vl == vr) {
    for (int i = al; i <= ar; ++i) val[idx[i]] = vl;
    return;
  }
  int mid = (vl + vr) >> 1, tot1 = 0, tot2 = 0;
  static int rid[MAXN + 5], id[MAXN + 5], idx1[MAXN + 5], idx2[MAXN + 5];
  e.clear();
  S = 1;
  T = 2;
  ncnt = 2;
  for (int i = al; i <= ar; ++i) {
    i64 val = myabs(i64(mid + 1 - v[idx[i]])) - myabs(i64(mid - v[idx[i]]));
    if (!id[idx[i]]) rid[id[idx[i]] = ++ncnt] = idx[i];
    if (val < 0) e.add(id[idx[i]], T, -val);
    if (val > 0) e.add(S, id[idx[i]], val);
    for (int to : geq[idx[i]]) {
      if (!id[to]) rid[id[to] = ++ncnt] = to;
      e.add(id[idx[i]], id[to], INF);
    }
    for (int to : leq[idx[i]]) {
      if (!id[to]) rid[id[to] = ++ncnt] = to;
      e.add(id[to], id[idx[i]], INF);
    }
  }
  i64 res = Dinic();
  for (int i = al; i <= ar; ++i) {
    if (dep[id[idx[i]]])
      idx1[++tot1] = idx[i];
    else
      idx2[++tot2] = idx[i];
  }
  for (int i = 1; i <= tot1; ++i) idx[al + i - 1] = idx1[i];
  for (int i = 1; i <= tot2; ++i) idx[al + tot1 + i - 1] = idx2[i];
  for (int i = 1; i <= ncnt; ++i) id[rid[i]] = 0;
  solve(al, al + tot1 - 1, vl, mid);
  solve(al + tot1, ar, mid + 1, vr);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> v[i];
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    leq[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i) idx[i] = i;
  solve(1, n, 0, 1e15);
  i64 res = 0;
  for (int i = 1; i <= n; ++i) cout << val[i] << " ";
  return 0;
}
