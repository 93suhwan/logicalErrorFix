#include <bits/stdc++.h>
using namespace std;
namespace jyy {
const int mod = 998244353, N = 400010;
const double eps = 1e-8;
inline int read() {
  static int x = 0, f = 1;
  x = 0, f = 1;
  static char ch = getchar();
  while (ch < '0' || ch > '9') {
    (ch == '-') ? f *= -1 : f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + int(ch - 48), ch = getchar();
  return x * f;
}
inline void fw(int x) {
  if (x < 0) putchar('-'), x = -x;
  x >= 10 ? fw(x / 10), 1 : 0;
  putchar(char(x % 10 + 48));
}
inline int qmo(int x) { return x + ((x >> 31) & mod); }
inline int ksm(int x, int y) {
  int tmp = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) tmp = 1ll * tmp * x % mod;
  return tmp;
}
inline int inv(int x) { return ksm(x, mod - 2); }
int tot, head[N], fa[N];
struct edge {
  int to, next;
} dat[N * 2];
void add_edge(int x, int y) { dat[++tot] = (edge){y, head[x]}, head[x] = tot; }
inline int find(int x) { return fa[x] ? fa[x] = find(fa[x]) : x; }
inline int merge(int x, int y) {
  return find(x) != find(y) ? fa[find(x)] = find(y), 0 : 1;
}
inline int low(int x) { return x & -x; }
int ifac[N], fac[N];
inline void init(int x) {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= x; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[x] = inv(fac[x]);
  for (int i = x - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
inline int C(int x, int y) {
  return (x < y || y < 0 || x < 0)
             ? 0
             : 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
}  // namespace jyy
using namespace jyy;
int a[N], n, b[N], c[N], p[N], cnt, val[N];
vector<int> v1[4][N], v2[4][N];
int do11(int mid) {
  int num = 0, now = 0;
  for (int i = 1; i <= cnt; i++) {
    now = i + 1;
    num += v1[p[1]][i].size();
    if (num >= mid) break;
  }
  if (now > cnt) return 0;
  int hh = now;
  num = 0;
  for (int i = now; i <= cnt; i++) {
    now = i + 1;
    num += v1[p[2]][i].size();
    if (num >= mid) break;
  }
  if (now > cnt) return 0;
  num = 0;
  for (int i = now; i <= cnt; i++) num += v1[p[3]][i].size();
  if (num >= mid) return 1;
  num = 0;
  now = 0;
  for (int i = 1; i <= cnt; i++) {
    now = i + 1;
    num += v2[p[2]][i].end() -
           lower_bound(v2[p[2]][i].begin(), v2[p[2]][i].end(), hh);
    if (num >= mid) break;
  }
  if (now > cnt) return 0;
  num = 0;
  for (int i = now; i <= cnt; i++) {
    num += v2[p[3]][i].end() -
           lower_bound(v2[p[3]][i].begin(), v2[p[3]][i].end(), hh);
  }
  if (num >= mid) return 1;
  return 0;
}
int do12(int mid) {
  int num = 0, now = 0;
  for (int i = 1; i <= cnt; i++) {
    now = i + 1;
    num += v2[p[1]][i].size();
    if (num >= mid) break;
  }
  if (now > cnt) return 0;
  int hh = now;
  num = 0;
  for (int i = now; i <= cnt; i++) {
    now = i + 1;
    num += v2[p[2]][i].size();
    if (num >= mid) break;
  }
  if (now > cnt) return 0;
  num = 0;
  for (int i = now; i <= cnt; i++) num += v2[p[3]][i].size();
  if (num >= mid) return 1;
  num = 0;
  now = 0;
  for (int i = 1; i <= cnt; i++) {
    now = i + 1;
    num += v1[p[2]][i].end() -
           lower_bound(v1[p[2]][i].begin(), v1[p[2]][i].end(), hh);
    if (num >= mid) break;
  }
  if (now > cnt) return 0;
  num = 0;
  for (int i = now; i <= cnt; i++) {
    num += v1[p[3]][i].end() -
           lower_bound(v1[p[3]][i].begin(), v1[p[3]][i].end(), hh);
  }
  if (num >= mid) return 1;
  return 0;
}
bool check(int mid) {
  for (int i = 1; i <= 3; i++) p[i] = i;
  do {
    if (do11(mid)) return 1;
    if (do12(mid)) return 1;
  } while (next_permutation(p + 1, p + 1 + 3));
  return 0;
}
void solve() {
  n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read(), b[i] = read(), c[i] = read(), val[++cnt] = a[i],
    val[++cnt] = b[i];
  sort(val + 1, val + 1 + cnt), cnt = unique(val + 1, val + 1 + cnt) - val - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(val + 1, val + 1 + cnt, a[i]) - val;
    b[i] = lower_bound(val + 1, val + 1 + cnt, b[i]) - val;
    v1[c[i]][a[i]].push_back(b[i]);
    v2[c[i]][b[i]].push_back(a[i]);
  }
  for (int k = 1; k <= 3; k++)
    for (int i = 1; i <= cnt; i++) {
      sort(v1[k][i].begin(), v1[k][i].end());
      sort(v2[k][i].begin(), v2[k][i].end());
    }
  int l = 0, r = n / 3, res = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      l = mid + 1, res = mid;
    else
      r = mid - 1;
  }
  cout << res * 3 << endl;
}
int main() {
  int T = 1;
  while (T--) solve();
}
