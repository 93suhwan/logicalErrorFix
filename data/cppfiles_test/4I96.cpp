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
  static long long buf[50], top = 0;
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
inline long long lowbit(long long x) { return x & (-x); }
const long long MaxN = 2e5 + 50;
const long long p = 1e9 + 7;
long long a[MaxN], n, K;
struct BIT {
  long long tr[MaxN];
  inline void add(long long x, long long k) {
    ++x;
    while (x <= n) (tr[x] += k) %= p, x += lowbit(x);
  }
  inline long long ask(long long x) {
    long long ret = 0;
    ++x;
    while (x) (ret += tr[x]) %= p, x ^= lowbit(x);
    return ret;
  }
  inline void del(long long x) {
    ++x;
    while (x <= n) tr[x] = 0, x += lowbit(x);
  }
} T[2], C[2];
std::vector<std::pair<long long, long long> > E[MaxN];
long long siz[MaxN], vis[MaxN], root, mnsiz, allsiz, ans;
inline void getroot(long long u, long long fa) {
  long long mx = 0;
  for (auto v : E[u])
    if (v.first != fa && !vis[v.first])
      getroot(v.first, u), ckmax(mx, siz[v.first]), siz[u] += siz[v.first];
  ckmax(mx, allsiz - siz[u]);
  if (ckmin(mnsiz, u)) root = u;
}
std::vector<std::pair<long long, long long> > dr1[2], dr2[2];
inline void go(long long u, long long fa, long long s, long long cnt,
               long long col, long long st) {
  if (cnt > K) return;
  dr1[st].push_back(std::make_pair(cnt, s));
  for (auto v : E[u])
    if (v.first != fa && !vis[v.first])
      go(v.first, u, (s + a[v.first]) % p, cnt + (v.second != col), v.second,
         st);
}
inline void solve(long long u) {
  for (auto v : E[u])
    if (!vis[v.first]) {
      go(v.first, u, a[v.first], 0, v.second, v.second);
      for (long long o = (0); o <= (1); ++o)
        for (auto i : dr1[o])
          for (long long r = (0); r <= (1); ++r)
            if (K - i.first - (o ^ r) >= 0)
              (ans += T[r].ask(K - i.first - (o ^ r)) +
                      C[r].ask(K - i.first - (o ^ r)) * i.second % p) %= p;
      for (long long o = (0); o <= (1); ++o)
        for (auto i : dr1[o])
          (ans += i.second + a[u]) %= p, dr2[o].push_back(i),
              T[o].add(i.first, i.second + a[u]), C[o].add(i.first, +1);
      dr1[0].clear(), dr1[1].clear();
    }
  ans += a[u];
  for (long long o = (0); o <= (1); ++o)
    for (auto i : dr2[o]) T[o].del(i.first), C[o].del(i.first);
  dr2[0].clear(), dr2[1].clear();
}
inline void divide(long long u) {
  vis[u] = 1, solve(u);
  for (auto v : E[u])
    if (!vis[v.first])
      allsiz = siz[v.first], mnsiz = 1e9, getroot(v.first, u), getroot(root, 0),
      divide(root);
}
signed main(void) {
  read(n, K);
  for (long long i = (1); i <= (n); ++i) read(a[i]);
  long long u, v, w;
  for (long long i = (1); i <= (n - 1); ++i)
    read(u, v, w), E[u].push_back(std::make_pair(v, w)),
        E[v].push_back(std::make_pair(u, w));
  mnsiz = 1e9, getroot(1, 0), getroot(root, 0), divide(root);
  write(ans), putchar('\n');
  return 0;
}
