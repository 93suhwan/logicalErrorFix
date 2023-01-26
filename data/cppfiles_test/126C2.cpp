#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
inline int mrand(int k) { return abs((int)mt()) % k; }
template <typename X>
void debug(X x) {
  cerr << x << "] ";
}
template <typename X, typename... Y>
void debug(X x, Y... y) {
  cerr << x << " ";
  debug(y...);
}
template <class T, T oo>
struct Dinic {
  static const int MAXV = 1e5 + 5;
  static const int MAXE = 1e6 + 5;
  int n, s, t, E;
  int adj[MAXE], nxt[MAXE], lst[MAXV], ptr[MAXV], lev[MAXV], que[MAXV];
  T flw[MAXE], cap[MAXE];
  void init(int n, int s, int t) {
    this->n = n, this->s = s, this->t = t, E = 0;
    fill_n(lst, n, -1);
  }
  void add(int u, int v, T c1, T c2) {
    adj[E] = v, flw[E] = 0, cap[E] = c1, nxt[E] = lst[u], lst[u] = E++;
    adj[E] = u, flw[E] = 0, cap[E] = c2, nxt[E] = lst[v], lst[v] = E++;
  }
  int bfs() {
    fill_n(lev, n, -1), lev[s] = 0;
    int qsize = 0;
    que[qsize++] = s;
    for (int i = 0; i < qsize; i++) {
      for (int u = que[i], e = lst[u]; ~e; e = nxt[e]) {
        int v = adj[e];
        if (flw[e] < cap[e] && !~lev[v]) {
          lev[v] = lev[u] + 1;
          que[qsize++] = v;
        }
      }
    }
    return lev[t] != -1;
  }
  T dfs(int u, T bot) {
    if (u == t) return bot;
    for (int& e = ptr[u]; ~e; e = nxt[e]) {
      int v = adj[e];
      T delta = 0;
      if (lev[v] == lev[u] + 1 && flw[e] < cap[e] &&
          (delta = dfs(v, min(bot, cap[e] - flw[e]))) > 0) {
        flw[e] += delta;
        flw[e ^ 1] -= delta;
        return delta;
      }
    }
    return 0;
  }
  T maxflow() {
    T total = 0;
    while (bfs()) {
      for (int i = 0; i < n; i++) ptr[i] = lst[i];
      for (T delta = dfs(s, oo); delta > 0; delta = dfs(s, oo)) total += delta;
    }
    return total;
  }
  pair<vector<int>, vector<int> > getmincut() {
    pair<vector<int>, vector<int> > res;
    static int vis[MAXV];
    fill_n(vis, n, 0);
    queue<int> que;
    vis[s] = 1, que.push(s);
    while (int((que).size())) {
      int u = que.front();
      que.pop();
      if (u != s) {
        res.first.push_back(u);
      }
      for (int e = lst[u]; ~e; e = nxt[e])
        if (flw[e] < cap[e]) {
          int v = adj[e];
          if (!vis[v]) {
            vis[v] = 1, que.push(v);
          }
        }
    }
    for (int u = (0); u < (n); ++u)
      if (u != t && !vis[u]) {
        res.second.push_back(u);
      }
    return res;
  }
};
Dinic<long long, (long long)1e18> dinic;
const int maxn = 1e5 + 5;
int n, m;
vector<int> adj[maxn];
int d[maxn];
inline int ff(int x, int d) { return abs(x - d) - abs(x - 1 - d); }
long long divide(vector<int> ver, int lo, int hi) {
  if (!int((ver).size())) return 0;
  int x = (lo + hi + 1) / 2;
  if (lo == hi) {
    long long res = 0;
    for (int i = (0); i < (int((ver).size())); ++i) {
      int u = ver[i];
      d[u] = x;
    }
    return res;
  }
  map<int, int> hs;
  for (int i = (0); i < (int((ver).size())); ++i) {
    int u = ver[i];
    hs[u] = i;
  }
  int tot = int((ver).size()), s = tot++, t = tot++;
  dinic.init(tot, s, t);
  for (int i = (0); i < (int((ver).size())); ++i) {
    int u = ver[i];
    int w = ff(x, d[u]);
    if (w < 0) {
      dinic.add(s, i, -w, 0);
    } else {
      dinic.add(i, t, +w, 0);
    }
    for (int j = (0); j < (int((adj[u]).size())); ++j) {
      int v = adj[u][j];
      if (hs.count(v)) {
        dinic.add(i, hs[v], INF, 0);
      }
    }
  }
  dinic.maxflow();
  pair<vector<int>, vector<int> > res = dinic.getmincut();
  vector<int> v1, v2;
  for (int i = (0); i < (int((res.first).size())); ++i) {
    v2.push_back(ver[res.first[i]]);
  }
  for (int i = (0); i < (int((res.second).size())); ++i) {
    v1.push_back(ver[res.second[i]]);
  }
  return divide(v1, lo, x - 1) + divide(v2, x, hi);
}
void chemthan() {
  cin >> n >> m;
  for (int i = (0); i < (n); ++i) cin >> d[i];
  for (int i = (0); i < (m); ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }
  vector<int> ver;
  for (int i = (0); i < (n); ++i) ver.push_back(i);
  divide(ver, -INF, +INF);
  for (int i = (0); i < (n); ++i) cout << d[i] << " \n"[i == n - 1];
}
int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
