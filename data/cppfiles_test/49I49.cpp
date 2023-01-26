#include <cstdio>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
char rbuf[1 << 20], *ps, *pt, wbuf[1 << 20], *po = wbuf;
char Getchar() {
  if (ps == pt) {
    pt = (ps = rbuf) + std::fread(rbuf, 1, 1 << 20, stdin);
    if (ps == pt) return EOF;
  }
  return *ps++;
}
template <typename T = int>
T Read() {
  T x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  return x * f;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
void Read(char &c) { c = Getchar(); }
void Read(char *s) {
  char c = Getchar();
  while (c <= 32) c = Getchar();
  while (c > 32) *s++ = c, c = Getchar();
  *s = '\0';
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x), Read(args...);
}
void Putchar(const char &c) {
  if (po - wbuf == 1 << 20) std::fwrite(wbuf, po - wbuf, 1, stdout), po = wbuf;
  *po++ = c;
}
template <typename T>
void Write(const T &x) {
  if (x < 0) {
    Putchar('-'), Write(-x);
    return;
  }
  if (x > 9) Write(x / 10);
  Putchar(x % 10 + '0');
}
void Write(const char c) { Putchar(c); }
void Write(const char *s) {
  while (*s != '\0') Putchar(*s++);
}
template <typename T, typename... Args>
void Write(const T &x, const Args &...args) {
  Write(x), Write(args...);
}
class AutoFlusher {
 public:
  AutoFlusher() {}
  ~AutoFlusher() { std::fwrite(wbuf, po - wbuf, 1, stdout); }
} autoflusher;
struct Edge {
  int to, nxt;
} e[1000001];
int T, n, q, a[1000001], E, head[1000001], cnt[1000001], ans[1000001];
std::vector<std::tuple<int, int, int>> b[1000001];
__gnu_pbds::tree<std::pair<int, int>, __gnu_pbds::null_type,
                 std::less<std::pair<int, int>>, __gnu_pbds::rb_tree_tag,
                 __gnu_pbds::tree_order_statistics_node_update>
    t;
void Add(int f, int t) { e[E] = {t, head[f]}, head[f] = E++; }
void Dfs(int u) {
  if (cnt[a[u]]) t.erase({cnt[a[u]], a[u]});
  t.insert({++cnt[a[u]], a[u]});
  for (auto &&[l, k, id] : b[u]) {
    k += t.order_of_key({l - 1, n + 1});
    if (k > static_cast<int>(t.size()))
      ans[id] = -1;
    else
      ans[id] = t.find_by_order(k - 1)->second;
  }
  std::vector<std::tuple<int, int, int>>().swap(b[u]);
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    Dfs(v);
  }
  t.erase({cnt[a[u]], a[u]});
  if (--cnt[a[u]]) t.insert({cnt[a[u]], a[u]});
}
void Solve() {
  Read(n, q);
  for (int i = 1; i <= n; i++) Read(a[i]);
  E = 0, std::memset(head + 1, -1, 4 * n);
  for (int i = 2; i <= n; i++) Add(Read(), i);
  for (int i = 1; i <= q; i++) {
    int v = Read(), l = Read(), k = Read();
    b[v].emplace_back(l, k, i);
  }
  Dfs(1);
  for (int i = 1; i <= n; i++) Write(ans[i], " \n"[i == n]);
}
int main(int argc, char const *argv[]) {
  Read(T);
  while (T--) Solve();
  return 0;
}