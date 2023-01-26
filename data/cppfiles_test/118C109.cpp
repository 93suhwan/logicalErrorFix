#include <bits/stdc++.h>
using namespace std;
const int N = 600010;
const int Mod = 998244353;
inline int sub(int x, int y) { return (x - y < 0 ? x - y + Mod : x - y); }
inline int add(int x, int y) { return (x + y >= Mod ? x + y - Mod : x + y); }
int po(int x, int y) {
  int r = 1;
  for (; y; y >>= 1, x = (1ll * x * x % Mod))
    if (y & 1) r = (1ll * r * x % Mod);
  return r;
}
namespace poly {
int r[N], a[N], b[N], w[N], iw[N], m, l;
void init(int x) {
  for (m = 1, l = 0; m <= x; m <<= 1, ++l)
    ;
  for (int i = 0; i < m; ++i) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
  int b = po(3, (Mod - 1) / m), ib = po(b, Mod - 2);
  w[m / 2] = iw[m / 2] = 1;
  for (int i = 1; i < m / 2; ++i)
    w[m / 2 + i] = (1ll * w[m / 2 + i - 1] * b % Mod),
              iw[m / 2 + i] = (1ll * iw[m / 2 + i - 1] * ib % Mod);
  for (int i = m / 2 - 1; i; --i) w[i] = w[i << 1], iw[i] = iw[i << 1];
}
void ntt(int* a, int f) {
  for (int i = 0; i < m; ++i)
    if (i < r[i]) swap(a[i], a[r[i]]);
  for (int i = 1, id = 1; i < m; i <<= 1, ++id) {
    for (int j = 0; j < m; j += i << 1)
      for (int k = 0; k < i; ++k) {
        int x = a[j + k],
            y = (1ll * (f == 1 ? w[i + k] : iw[i + k]) * a[i + j + k] % Mod);
        a[j + k] = add(x, y), a[i + j + k] = sub(x, y);
      }
  }
  if (f == -1) {
    int in = po(m, Mod - 2);
    for (int i = 0; i < m; ++i) a[i] = (1ll * a[i] * in % Mod);
  }
}
void prod(int* a, int* b, int len) {
  init(len);
  ntt(a, 1);
  ntt(b, 1);
  for (int i = 0; i < m; ++i) a[i] = (1ll * a[i] * b[i] % Mod);
  ntt(a, -1);
}
}  // namespace poly
using poly::a;
using poly::b;
using poly::prod;
int fac[N], inv[N];
void init() {
  const int m = 3e5;
  fac[0] = 1;
  for (int i = 1; i <= m; ++i) fac[i] = (1ll * fac[i - 1] * i % Mod);
  inv[m] = po(fac[m], Mod - 2);
  for (int i = m - 1; i >= 0; i--) inv[i] = (1ll * i + 1 * inv[i + 1] % Mod);
}
vector<int> ve[N];
priority_queue<pair<int, int> > Q;
int cq;
struct Edge {
  int to, next;
} edge[N << 1];
int head[N], num;
void add_edge(int a, int b) {
  edge[++num] = (Edge){b, head[a]};
  head[a] = num;
}
void dfs(int x, int f) {
  int cnt = 0;
  for (int i = head[x]; i; i = edge[i].next)
    if (edge[i].to != f) {
      dfs(edge[i].to, x);
      ++cnt;
    }
  if (cnt) {
    ++cq;
    ve[cq].push_back(1);
    ve[cq].push_back(cnt);
    Q.push(make_pair(-1, cq));
  }
}
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
  }
  dfs(1, 0);
  for (int i = 1; i < cq; ++i) {
    int t1 = Q.top().second;
    Q.pop();
    int t2 = Q.top().second;
    Q.pop();
    int la = ve[t1].size() - 1, lb = ve[t2].size() - 1;
    for (int j = 0; j <= la; j++) a[j] = ve[t1][j];
    for (int j = 0; j <= lb; j++) b[j] = ve[t2][j];
    prod(a, b, la + lb + 2);
    ve[t1].clear();
    for (int j = 0; j <= la + lb; j++) ve[t1].push_back(a[j]);
    for (int i = 0; i <= poly ::m; i++) a[i] = b[i] = 0;
    Q.push(make_pair(-la - lb, t1));
  }
  int rt = Q.top().second, len = -Q.top().first;
  int ans = 0;
  for (int i = 0; i <= len; ++i) {
    int tmp = (1ll * ve[rt][i] * fac[n - i] % Mod);
    ans = (i & 1) ? sub(ans, tmp) : add(ans, tmp);
  }
  printf("%d\n", ans);
  return 0;
}
