#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
namespace MyMinMax {
template <typename T>
inline T mn(const T x, const T y) {
  return x < y ? x : y;
}
template <typename T>
inline T mx(const T x, const T y) {
  return x > y ? x : y;
}
template <typename T>
inline bool chmin(T &x, const T y) {
  return (x > y) && ((x = y), 1);
}
template <typename T>
inline bool chmax(T &x, const T y) {
  return (x < y) && ((x = y), 1);
}
template <typename T, typename... Args>
inline T mx(const T x, const Args... args) {
  return mx(x, mx(args...));
}
template <typename T, typename... Args>
inline T mn(const T x, const Args... args) {
  return mn(x, mn(args...));
}
}  // namespace MyMinMax
using namespace MyMinMax;
namespace IO {
const int DPAIRSIZ = 1 << 18;
char BB[DPAIRSIZ], *SS = BB, *TT = BB;
inline char getcha() {
  return SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT)
             ? EOF
             : *SS++;
}
template <typename T = int>
inline T read() {
  T x = 0;
  int fu = 1;
  char c = getcha();
  while (c < 48) {
    if (c == 45) {
      fu = -1;
    }
    c = getcha();
  }
  while (c >= 48) {
    x = x * 10 + c - 48;
    c = getcha();
  }
  x *= fu;
  return x;
}
template <typename T>
inline void read(T &x) {
  x = 0;
  int fu = 1;
  char c = getcha();
  while (c < 48) {
    if (c == 45) {
      fu = -1;
    }
    c = getcha();
  }
  while (c >= 48) {
    x = x * 10 + c - 48;
    c = getcha();
  }
  x *= fu;
}
template <typename T>
inline void read(T *bg, T *ed) {
  while (bg != ed) read(*bg++);
}
inline void read(char &ch) {
  ch = getcha();
  while (ch <= 32) ch = getcha();
}
inline void read(char *s) {
  char ch = getcha();
  while (ch <= 32) ch = getcha();
  while (ch > 32) *s++ = ch, ch = getcha();
  *s = '\0';
}
inline void getl(char *s) {
  char ch = getcha();
  while (ch < 32) ch = getcha();
  while (ch >= 32) *s++ = ch, ch = getcha();
  *s = '\0';
}
inline void pread(char *&s) {
  char ch = getcha();
  while (ch <= 32) ch = getcha();
  while (ch > 32) *s++ = ch, ch = getcha();
  *s = '\0';
}
inline void pgetl(char *&s) {
  char ch = getcha();
  while (ch <= 32) ch = getcha();
  while (ch > 32) *s++ = ch, ch = getcha();
  *s = '\0';
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
char out[DPAIRSIZ], *Out = out;
inline void putcha(char x) {
  *Out++ = x;
  if (Out - out >= (DPAIRSIZ)) fwrite(out, 1, Out - out, stdout), Out = out;
}
template <typename T>
inline void fprint(T x) {
  if (x < 0) putcha(45), x = -x;
  if (x > 9) fprint(x / 10);
  putcha(x % 10 + 48);
}
inline void print() { putcha(10); }
template <typename T>
inline void print(T x) {
  fprint(x);
  putcha(10);
}
inline void print(char *ch) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(10);
}
inline void put(char *ch) {
  while (*ch != '\0') putcha(*(ch++));
}
inline void print(const char *ch) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(10);
}
inline void put(const char *ch) {
  while (*ch != '\0') putcha(*(ch++));
}
template <typename T, typename... Args>
inline void print(T x, Args... args) {
  fprint(x);
  putcha(32);
  print(args...);
}
template <typename... Args>
inline void print(const char *ch, Args... args) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(32);
  print(args...);
}
template <typename... Args>
inline void print(char *ch, Args... args) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(32);
  print(args...);
}
template <typename T, typename... Args>
inline void printl(T x, Args... args) {
  fprint(x);
  putcha(10);
  printl(args...);
}
template <typename... Args>
inline void printl(const char *ch, Args... args) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(10);
  printl(args...);
}
template <typename... Args>
inline void printl(char *ch, Args... args) {
  while (*ch != '\0') putcha(*(ch++));
  putcha(10);
  printl(args...);
}
template <typename T>
inline void sprint(T x) {
  fprint(x);
  putcha(32);
}
template <typename T, typename... Args>
inline void sprint(T x, Args... args) {
  fprint(x);
  putcha(32);
  sprint(args...);
}
template <typename T>
inline void sprint(T *bg, T *ed) {
  while (bg != ed) sprint(*bg++);
}
template <typename T>
inline void print(T *bg, T *ed) {
  while (bg != ed) sprint(*bg++);
  putcha(10);
}
template <typename T>
inline void printl(T *bg, T *ed) {
  while (bg != ed) print(*bg++);
}
class AutoFlush {
 public:
  ~AutoFlush() { fwrite(out, 1, Out - out, stdout); }
} __AutoFlush;
}  // namespace IO
using namespace IO;
const int INF = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1e6 + 5;
int n, m, a[MAXN], b[MAXN], d[MAXN << 1], p;
int c[MAXN << 1];
inline int lowbit(int x) { return x & -x; }
inline void add(int x) {
  for (; x <= p; x += lowbit(x)) ++c[x];
}
inline int ask(int x) {
  int s = 0;
  for (; x; x -= lowbit(x)) s += c[x];
  return s;
}
struct Segtree {
  struct Dat {
    int L, S;
    Dat(int L = 0, int S = 0) : L(L), S(S) {}
    inline Dat operator+(const Dat &b) const {
      return Dat(mx(L, S + b.L), S + b.S);
    }
  } t[MAXN << 2];
  inline void pushup(int rt) { t[rt] = t[rt << 1] + t[rt << 1 | 1]; }
  void build(int rt, int l, int r) {
    if (l == r) {
      t[rt] = Dat(0, -1);
      return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
  }
  void modify(int rt, int l, int r, int x, int y) {
    if (l == r) {
      t[rt] = (Dat){y, y};
      return;
    }
    int mid = (l + r) >> 1;
    x <= mid ? modify(rt << 1, l, mid, x, y)
             : modify(rt << 1 | 1, mid + 1, r, x, y);
    pushup(rt);
  }
} t;
int q[MAXN];
inline void work() {
  read(n, m);
  p = 0;
  read(a + 1, a + n + 1);
  read(b + 1, b + m + 1);
  for (int i = (1), iEND = (n); i <= iEND; ++i) d[++p] = a[i];
  for (int i = (1), iEND = (m); i <= iEND; ++i) d[++p] = b[i];
  std::sort(d + 1, d + p + 1);
  std::sort(b + 1, b + m + 1);
  p = std::unique(d + 1, d + p + 1) - d - 1;
  for (int i = (1), iEND = (n); i <= iEND; ++i)
    a[i] = std::lower_bound(d + 1, d + p + 1, a[i]) - d, q[i] = i;
  for (int i = (1), iEND = (m); i <= iEND; ++i)
    b[i] = std::lower_bound(d + 1, d + p + 1, b[i]) - d;
  memset(c + 1, 0, p * sizeof(int));
  long long ans = 0;
  for (int i = (1), iEND = (n); i <= iEND; ++i) {
    add(a[i]);
    ans += i - ask(a[i]);
  }
  t.build(1, 1, n);
  std::sort(q + 1, q + n + 1, [](int x, int y) { return a[x] < a[y]; });
  int it1 = 1, it2 = 1;
  for (int i = (1), iEND = (m); i <= iEND; ++i) {
    while (it1 <= n && a[q[it1]] == b[i]) t.modify(1, 1, n, q[it1++], 0);
    while (it2 <= n && a[q[it2]] < b[i]) t.modify(1, 1, n, q[it2++], 1);
    chmax(it1, it2);
    ans += it2 - 1 - t.t[1].L;
  }
  print(ans);
}
signed main() {
  int T = read();
  while (T--) work();
}
