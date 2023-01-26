#include <bits/stdc++.h>
using namespace std;
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline int read() {
  int ans = 0, f = 1;
  char c = nc();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = nc();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = nc();
  }
  return ans * f;
}
};  // namespace fastIO
using namespace fastIO;
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x / 10) write(x / 10);
  putchar((char)(x % 10) + '0');
}
template <typename T>
inline T Abs(T a) {
  return a > 0 ? a : -a;
};
template <typename T, typename TT>
inline T Min(T a, TT b) {
  return a < b ? a : b;
}
template <typename T, typename TT>
inline T Max(T a, TT b) {
  return a < b ? b : a;
}
const int N = 1e6 + 5;
int t, n, q, a[N], sm[N], ans[N];
set<int> hav[N];
struct Seg {
  int val[N << 2];
  void build(int x, int l, int r) {
    val[x] = 0;
    if (l == r) return;
    build((x << 1), l, ((l + r) >> 1));
    build((x << 1 | 1), ((l + r) >> 1) + 1, r);
  }
  void update(int x, int l, int r, int p, int v) {
    if (l == r) {
      val[x] += v;
      return;
    }
    if (p <= ((l + r) >> 1))
      update((x << 1), l, ((l + r) >> 1), p, v);
    else
      update((x << 1 | 1), ((l + r) >> 1) + 1, r, p, v);
    val[x] = val[(x << 1)] + val[(x << 1 | 1)];
  }
  int query1(int x, int l, int r, int p) {
    if (p < 0) return 0;
    if (r <= p) return val[x];
    int res = query1((x << 1), l, ((l + r) >> 1), p);
    if (((l + r) >> 1) + 1 <= p)
      res += query1((x << 1 | 1), ((l + r) >> 1) + 1, r, p);
    return res;
  }
  int query2(int x, int l, int r, int p, int k) {
    if (val[x] - p < k) return -1;
    if (l == r) return l;
    if (val[(x << 1)] - p >= k)
      return query2((x << 1), l, ((l + r) >> 1), p, k);
    else
      return query2((x << 1 | 1), ((l + r) >> 1) + 1, r,
                    Max(0, p - val[(x << 1)]), k - Max(0, val[(x << 1)] - p));
  }
} sum;
struct Qus {
  int x, y, id;
};
vector<Qus> qs[N];
struct Edge {
  int v, ne;
} e[N * 2];
int head[N], tot;
inline void add(int u, int v);
void dfs(int u, int fa);
signed main() {
  t = read();
  while (t--) {
    n = read();
    q = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 2; i <= n; ++i) {
      int x = read();
      add(x, i);
      add(i, x);
    }
    for (int i = 1; i <= q; ++i) {
      int x = read(), y = read(), z = read();
      qs[x].push_back((Qus){y, z, i});
    }
    sum.build(1, 0, n);
    for (int i = 1; i <= n; ++i) hav[0].insert(i);
    sum.update(1, 0, n, 0, n);
    dfs(1, 0);
    for (int i = 1; i <= q; ++i) write(ans[i]), putchar(' ');
    puts("");
    tot = 0;
    for (int i = 0; i <= n; ++i) head[i] = 0, qs[i].clear(), hav[i].clear();
  }
  return 0;
}
inline void add(int u, int v) {
  e[++tot] = (Edge){v, head[u]};
  head[u] = tot;
}
void dfs(int u, int fa) {
  hav[sm[a[u]]].erase(a[u]);
  sum.update(1, 0, n, sm[a[u]], -1);
  sm[a[u]]++;
  hav[sm[a[u]]].insert(a[u]);
  sum.update(1, 0, n, sm[a[u]], 1);
  for (int i = 0; i < qs[u].size(); ++i) {
    int tmp = sum.query1(1, 0, n, qs[u][i].x - 1);
    tmp = sum.query2(1, 0, n, tmp, qs[u][i].y);
    if (tmp == -1)
      ans[qs[u][i].id] = -1;
    else
      ans[qs[u][i].id] = *hav[tmp].begin();
  }
  for (int i = head[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
  }
  hav[sm[a[u]]].erase(a[u]);
  sum.update(1, 0, n, sm[a[u]], -1);
  sm[a[u]]--;
  hav[sm[a[u]]].insert(a[u]);
  sum.update(1, 0, n, sm[a[u]], 1);
}
