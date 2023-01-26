#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) {
  long long t;
  scanf("%lld", &t);
  x = t;
}
void _R(unsigned long long &x) { scanf("%llu", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) {
  long long t = x;
  printf("%lld", t);
}
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const int MOD = 1e9 + 7, mod = 998244353;
long long qpow(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int MAXN = 2e4 + 10, MAXM = 4e4 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX, SLINF = 0x3f3f3f3f3f3f3f3f;
const int inv2 = (MOD + 1) / 2;
const int Lim = 1 << 20;
struct MCMF {
  const long long SLINF = 0x3f3f3f3f3f3f3f3f;
  struct Edge {
    int u, v;
    long long flow, cap, cost;
    int next;
  };
  int e_ptr = 1, S = 0, T = 1, head[MAXN + 10];
  Edge E[(MAXM + 10) << 1];
  long long MaxFlow = 0;
  long long dist[MAXN + 10], MinCost = 0, delta;
  int inq[MAXN + 10], done[MAXN + 10], n;
  bool vis[MAXN + 10];
  void add_edge(int u, int v, long long cap, long long cost) {
    E[++e_ptr] = {u, v, 0, cap, cost, head[u]};
    head[u] = e_ptr;
    E[++e_ptr] = {v, u, 0, 0, -cost, head[v]};
    head[v] = e_ptr;
  }
  void Reduce() {
    for (int i = 2; i <= e_ptr; i++) E[i].cost += dist[E[i].v] - dist[E[i].u];
    delta += dist[S];
  }
  bool BellmanFord() {
    queue<int> Q;
    memset(dist, -0x3f, (n + 5) * sizeof(long long));
    long long p = dist[T];
    dist[T] = 0;
    Q.push(T);
    inq[T] = true;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      inq[u] = false;
      for (int j = head[u]; j; j = E[j].next) {
        int v = E[j].v;
        long long f = E[j ^ 1].flow, c = E[j ^ 1].cap;
        long long len = E[j ^ 1].cost;
        if (f < c && dist[v] < dist[u] + len) {
          dist[v] = dist[u] + len;
          if (!inq[v]) {
            inq[v] = true;
            Q.push(v);
          }
        }
      }
    }
    return dist[S] != p;
  }
  bool Dijkstra() {
    memset(dist, -0x3f, (n + 5) * sizeof(long long));
    memset(vis, 0, (n + 5));
    long long p = dist[S];
    priority_queue<pair<long long, long long> > pq;
    dist[T] = 0;
    pq.push({dist[T], T});
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      if (vis[u]) continue;
      vis[u] = 1;
      for (int j = head[u]; j; j = E[j].next) {
        int v = E[j].v;
        long long f = E[j ^ 1].flow, c = E[j ^ 1].cap;
        long long len = E[j ^ 1].cost;
        if (f < c && dist[v] < dist[u] + len) {
          dist[v] = dist[u] + len;
          pq.push({dist[v], v});
        }
      }
    }
    return dist[S] != p;
  }
  long long DFS(int u, long long flow) {
    if (u == T || flow == 0) return flow;
    vis[u] = true;
    long long res = flow;
    for (int j = head[u]; j; j = E[j].next) {
      int v = E[j].v;
      long long f = E[j].flow, c = E[j].cap, len = E[j].cost;
      if (!vis[v] && f < c && len == 0) {
        long long tmp = DFS(v, min(res, c - f));
        E[j].flow += tmp;
        E[j ^ 1].flow -= tmp;
        res -= tmp;
      }
    }
    return flow - res;
  }
  void Augment() {
    long long CurFlow = 0;
    while (memset(vis, 0, (n + 5)), (CurFlow = DFS(S, SLINF))) {
      MaxFlow += CurFlow;
      MinCost += CurFlow * delta;
    }
  }
  pair<long long, long long> solve() {
    if (!BellmanFord()) return {-1, -1};
    Reduce();
    Augment();
    while (Dijkstra()) {
      Reduce();
      Augment();
    }
    return {MinCost, MaxFlow};
  }
  void init(int s, int t, int N) {
    S = s;
    T = t;
    n = N;
    e_ptr = 1;
    MaxFlow = MinCost = delta = 0;
    for (int i = 0; i <= n; i++) inq[i] = done[i] = vis[i] = head[i] = 0;
  }
} G;
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(long long x) { return __builtin_popcountll(x); }
int ctz(int x) { return __builtin_ctz(x); }
int ctz(long long x) { return __builtin_ctzll(x); }
int clz(int x) { return 31 - __builtin_clz(x); }
int clz(long long x) { return 63 - __builtin_clzll(x); }
int n, k;
int a[2000005];
vector<pair<int, int> > vec;
bool cmp(pair<int, int> &x, pair<int, int> &y) {
  return a[x.first] + a[x.second] >= a[y.first] + a[y.second];
}
void calc(vector<pair<int, int> > &vec) {
  vector<int> etc;
  for (auto j : vec) {
    int u = j.first, v = j.second;
    etc.push_back(u);
    etc.push_back(v);
  }
  sort((etc).begin(), (etc).end()),
      etc.resize(unique((etc).begin(), (etc).end()) - etc.begin());
  int sz = ((int)etc.size());
  G.init(sz + 3, sz + 2, sz + 2);
  for (auto j : vec) {
    int u = j.first, v = j.second;
    if (popcnt(u) & 1) swap(u, v);
    G.add_edge((lower_bound((etc).begin(), (etc).end(), u) - etc.begin()) + 1,
               (lower_bound((etc).begin(), (etc).end(), v) - etc.begin()) + 1,
               1, 0);
  }
  for (auto j : etc) {
    if (popcnt(j) & 1)
      G.add_edge((lower_bound((etc).begin(), (etc).end(), j) - etc.begin()) + 1,
                 sz + 2, 1, a[j]);
    else
      G.add_edge(sz + 1,
                 (lower_bound((etc).begin(), (etc).end(), j) - etc.begin()) + 1,
                 1, a[j]);
  }
  G.add_edge(sz + 3, sz + 1, k, 0);
}
void landsort(vector<pair<int, int> > &vec, int k, int l, int r) {
  if (l >= r) return;
  int p = rand() % (r - l + 1) + l;
  swap(vec[p], vec[r]);
  int p1 = l, p2 = r - 1;
  while (p1 < p2) {
    while (p1 < p2 && cmp(vec[p1], vec[r])) p1++;
    while (p1 < p2 && !cmp(vec[p2], vec[r])) p2--;
    if (p1 < p2) swap(vec[p1], vec[p2]), p1++, p2--;
  }
  swap(vec[r], vec[p2]);
  int cl = p2, cr = p2;
  while (cl > l && vec[cl - 1] == vec[p2]) cl--;
  while (cr < r && vec[cr + 1] == vec[p2]) cr++;
  if (cl <= k && cr >= k) return;
  if (k > cr)
    landsort(vec, k, cr + 1, r);
  else
    landsort(vec, k, l, cl - 1);
}
void solve() {
  R(n, k);
  for (int i = 0; i < (1 << n); i++) R(a[i]);
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) {
        vec.push_back({i, i ^ (1 << j)});
      }
  }
  if (n * k >= ((int)vec.size()))
    calc(vec);
  else {
    landsort(vec, n * k, 0, ((int)vec.size()) - 1);
    vector<pair<int, int> > tmp;
    for (int i = 0; i < n * k; i++) tmp.push_back(vec[i]);
    calc(tmp);
  }
  W(G.solve().first);
}
int main() {
  int T = 1;
  for (int kase = 1; kase <= T; kase++) {
    solve();
  }
  return 0;
}
