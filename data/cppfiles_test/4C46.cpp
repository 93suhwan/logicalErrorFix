#include <bits/stdc++.h>
template <class t>
inline void read(t &s) {
  s = 0;
  signed f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  ;
  s *= f;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0) putchar('-'), x = -x;
  static int buf[50], top = 0;
  while (x) buf[++top] = x % 10, x /= 10;
  if (!top) buf[++top] = 0;
  while (top) putchar(buf[top--] ^ '0');
}
inline void setIn(std::string s) {
  freopen(s.c_str(), "r", stdin);
  return;
}
inline void setOut(std::string s) {
  freopen(s.c_str(), "w", stdout);
  return;
}
inline void setIO(std::string s = "") {
  setIn(s + ".in");
  setOut(s + ".out");
  return;
}
template <class t>
inline bool ckmin(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
inline bool ckmax(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline int lowbit(int x) { return x & (-x); }
const int MaxN = 2e5 + 50;
const int p = 1e9 + 7;
int a[MaxN], n, K;
inline int plus(const int &x, const int &y) {
  int s = x + y - p;
  return s + (s >> 31 & p);
}
inline void add(int &x, const int &y) { (x += y) >= p && (x -= p); }
struct BIT {
  int tr[MaxN];
  inline void add(int x, int k) {
    ++x;
    while (x <= n) ::add(tr[x], k), x += lowbit(x);
  }
  inline int ask(int x) {
    int ret = 0;
    ++x;
    while (x) ::add(ret, tr[x]), x ^= lowbit(x);
    return ret;
  }
  inline void del(int x) {
    ++x;
    while (x <= n) tr[x] = 0, x += lowbit(x);
  }
} T[2], C[2];
std::vector<std::pair<int, int> > E[MaxN];
int siz[MaxN], vis[MaxN], root, mnsiz, allsiz, ans;
inline void getroot(int u, int fa) {
  siz[u] = 1;
  int mx = 0;
  for (auto v : E[u])
    if (v.first != fa && !vis[v.first])
      getroot(v.first, u), ckmax(mx, siz[v.first]), siz[u] += siz[v.first];
  ckmax(mx, allsiz - siz[u]);
  if (ckmin(mnsiz, mx)) root = u;
}
std::vector<std::pair<int, int> > dr1[2], dr2[2];
inline void go(int u, int fa, int s, int cnt, int col, int st) {
  if (cnt > K) return;
  dr1[st].push_back(std::make_pair(cnt, s));
  for (auto v : E[u])
    if (v.first != fa && !vis[v.first])
      go(v.first, u, plus(s, a[v.first]), cnt + (v.second != col), v.second,
         st);
}
inline void solve(int u) {
  for (auto v : E[u])
    if (!vis[v.first]) {
      go(v.first, u, a[v.first], 0, v.second, v.second);
      for (int o = (0); o <= (1); ++o)
        for (auto i : dr1[o])
          for (int r = (0); r <= (1); ++r)
            if (K - i.first - (o ^ r) >= 0)
              ans = (ans + (T[r].ask(K - i.first - (o ^ r)) +
                            1LL * C[r].ask(K - i.first - (o ^ r)) * i.second)) %
                    p;
      for (int o = (0); o <= (1); ++o)
        for (auto i : dr1[o])
          add(ans, plus(i.second, a[u])), dr2[o].push_back(i),
              T[o].add(i.first, plus(i.second, a[u])), C[o].add(i.first, +1);
      dr1[0].clear(), dr1[1].clear();
    }
  add(ans, a[u]);
  for (int o = (0); o <= (1); ++o)
    for (auto i : dr2[o]) T[o].del(i.first), C[o].del(i.first);
  dr2[0].clear(), dr2[1].clear();
}
inline void divide(int u) {
  vis[u] = 1, solve(u);
  for (auto v : E[u])
    if (!vis[v.first])
      allsiz = siz[v.first], mnsiz = 1e9, getroot(v.first, u), getroot(root, 0),
      divide(root);
}
signed main(void) {
  read(n, K);
  for (int i = (1); i <= (n); ++i) read(a[i]);
  int u, v, w;
  for (int i = (1); i <= (n - 1); ++i)
    read(u, v, w), E[u].push_back(std::make_pair(v, w)),
        E[v].push_back(std::make_pair(u, w));
  allsiz = n, mnsiz = 1e9, getroot(1, 0), getroot(root, 0), divide(root);
  write(ans), putchar('\n');
  return 0;
}
