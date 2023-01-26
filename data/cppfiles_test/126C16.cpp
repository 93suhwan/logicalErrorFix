#include <bits/stdc++.h>
using namespace std;
int I() {
  char c = getchar();
  int x = 0;
  int f = 1;
  while (c < '0' or c > '9') f = (c == '-') ? -1 : 1, c = getchar();
  while (c >= '0' and c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return ((f == 1) ? x : -x);
}
long long tot = 0;
class Network {
 public:
  long long S, T;
  long long h[1100], to[1000006], nx[1000006], cap[1000006], ec = -1;
  long long c[1100];
  void cl() {
    memset(c, -1, sizeof(c));
    memset(h, -1, sizeof(h));
    ec = -1;
  }
  void ad(long long u, long long v, long long c) {
    ++ec;
    to[ec] = v;
    nx[ec] = h[u];
    cap[ec] = c;
    h[u] = ec;
  }
  long long af(long long u, long long v, long long c) {
    ad(u, v, c);
    ad(v, u, 0);
    return ec - 1;
  }
  long long dep[1100];
  queue<long long> Q;
  bool BFS() {
    while (!Q.empty()) Q.pop();
    for (long long i = 1; i <= tot; ++i) dep[i] = 0x3f3f3f3f3f3f3f3fll;
    dep[S] = 0;
    Q.push(S);
    c[S] = h[S];
    while (!Q.empty()) {
      long long u = Q.front();
      Q.pop();
      for (long long i = h[u], v; ~i; i = nx[i]) {
        if (dep[v = to[i]] == 0x3f3f3f3f3f3f3f3fll and cap[i]) {
          Q.push(v);
          c[v] = h[v];
          dep[v] = dep[u] + 1;
        }
      }
    }
    return dep[T] < 0x3f3f3f3f3f3f3f3fll;
  }
  long long DFS(long long u, long long flow) {
    long long s = 0, o = flow;
    if (u == T) return flow;
    for (long long &i = c[u], v; ~i; i = nx[i]) {
      if (dep[v = to[i]] == dep[u] + 1 and cap[i]) {
        long long f = DFS(v, min(o, cap[i]));
        cap[i] -= f;
        cap[i ^ 1] += f;
        s += f;
        o -= f;
      }
    }
    return s;
  }
  long long Flow() {
    long long ans = 0;
    while (BFS()) {
      ans += DFS(S, 0x3f3f3f3f3f3f3f3fll), ans = min(ans, 0x3f3f3f3f3f3f3f3fll);
    }
    return ans;
  }
} NT;
long long n, m, a[1100];
vector<pair<long long, long long> > ed;
bool g[1100][1100];
long long id[1100], b[1100];
long long v0[1100], v1[1100];
long long V = 3000000000;
void calc(long long l, long long r, long long L, long long R) {
  if (l > r) return;
  if (L == R) {
    for (long long i = l; i <= r; ++i) b[id[i]] = L;
    return;
  }
  long long mid = (L + R) >> 1;
  NT.cl();
  NT.S = n + 1;
  NT.T = n + 2;
  tot = n + 2;
  for (long long i = l; i <= r; ++i)
    v0[i] = abs(a[id[i]] - mid), v1[i] = abs(a[id[i]] - (mid + 1));
  for (long long i = l; i <= r; ++i) {
    NT.af(NT.S, id[i], V - v0[i]);
    NT.af(id[i], NT.T, V - v1[i]);
  }
  bool in[1100];
  memset(in, 0, sizeof(in));
  for (long long i = l; i <= r; ++i) in[id[i]] = 1;
  for (auto e : ed)
    if (in[e.first] and in[e.second])
      NT.af(e.second, e.first, 0x3f3f3f3f3f3f3f3fll);
  long long f = NT.Flow();
  NT.BFS();
  long long tmp[1100], tot = 0;
  for (long long i = l; i <= r; ++i)
    if (NT.dep[id[i]] < 0x3f3f3f3f3f3f3f3fll) tmp[++tot] = id[i];
  long long p = tot;
  for (long long i = l; i <= r; ++i)
    if (NT.dep[id[i]] == 0x3f3f3f3f3f3f3f3fll) tmp[++tot] = id[i];
  for (long long i = l; i <= r; ++i) id[i] = tmp[i - l + 1];
  calc(l, l + p - 1, L, mid);
  calc(l + p, r, mid + 1, R);
}
void flandre() {
  n = I(), m = I();
  for (long long i = 1; i <= n; ++i) a[i] = I();
  for (long long i = 1; i <= m; ++i) {
    long long x = I(), y = I();
    ed.push_back(pair<long long, long long>(x, y));
    g[x][y] = 1;
  }
  for (long long i = 1; i <= n; ++i) id[i] = i;
  calc(1, n, -1e9, 1e9);
  for (long long i = 1; i <= n; ++i) printf("%lld ", b[i]);
  puts("");
}
int main() {
  int t = 1;
  while (t-- > 0) {
    flandre();
  }
}
