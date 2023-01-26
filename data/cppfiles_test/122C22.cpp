#include <bits/stdc++.h>
using namespace std;
inline int min(int x, int y) { return (x < y) ? x : y; }
inline int max(int x, int y) { return (x > y) ? x : y; }
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
namespace IO {
int len = 0;
char ibuf[(1 << 20) + 1], *iS, *iT, out[(1 << 25) + 1];
inline int read() {
  char ch = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
             (iS == iT ? EOF : *iS++) : *iS++);
  int x = 0;
  char t = 0;
  while (ch < '0' || ch > '9')
    t |= ch == '-', ch = (iS == iT ? iT = (iS = ibuf) +
                                          fread(ibuf, 1, (1 << 20) + 1, stdin),
                          (iS == iT ? EOF : *iS++) : *iS++);
  while (ch >= '0' && ch <= '9')
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
          (iS == iT ? EOF : *iS++) : *iS++);
  return t ? -x : x;
}
inline void putc(char ch) { out[len++] = ch; }
template <class T>
inline void write(T x) {
  if (x < 0) putc('-'), x = -x;
  if (x > 9) write(x / 10);
  out[len++] = x % 10 + 48;
}
string getstr(void) {
  string s = "";
  char c = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
            (iS == iT ? EOF : *iS++) : *iS++);
  while (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF)
    c = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
         (iS == iT ? EOF : *iS++) : *iS++);
  while (!(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF))
    s.push_back(c),
        c = (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin),
             (iS == iT ? EOF : *iS++) : *iS++);
  return s;
}
void putstr(string str, int begin = 0, int end = -1) {
  if (end == -1) end = str.size();
  for (int i = begin; i < end; i++) putc(str[i]);
  return;
}
inline void flush() {
  fwrite(out, 1, len, stdout);
  len = 0;
}
}  // namespace IO
using IO::flush;
using IO::getstr;
using IO::putc;
using IO::putstr;
using IO::read;
using IO::write;
const int N = 2e6;
int ans, t, n, m, rk[N];
int U[N], V[N], W[N];
int popcount(int x) {
  int ans = 0;
  while (x) x &= (x - 1), ans ^= 1;
  return ans;
}
vector<pair<int, int> > ver[N];
void dfs(int x) {
  for (auto y : ver[x]) {
    if (rk[y.first] == -1) {
      rk[y.first] = rk[x] ^ y.second;
      dfs(y.first);
    }
    if (rk[y.first] != (rk[x] ^ y.second)) ans = 0;
  }
}
signed main() {
  t = read();
  while (t--) {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) rk[i] = -1, ver[i].clear(), ans = 1;
    for (int i = 1; i < n; i++) {
      int x = read(), y = read(), z = read();
      U[i] = x, V[i] = y, W[i] = z;
      if (z < 0) continue;
      ver[x].emplace_back(make_pair(y, popcount(z)));
      ver[y].emplace_back(make_pair(x, popcount(z)));
    }
    for (int i = 1; i <= m; i++) {
      int a = read(), b = read(), c = read();
      ver[a].emplace_back(make_pair(b, c));
      ver[b].emplace_back(make_pair(a, c));
    }
    for (int i = 1; i <= n; i++) {
      if (rk[i] == -1) rk[i] = 0, dfs(i);
    }
    if (ans) {
      putc('Y'), putc('E'), putc('S'), putc('\n');
      for (int i = 1; i < n; i++) {
        write(U[i]), putc(' ');
        write(V[i]), putc(' ');
        write(W[i] != -1 ? W[i] : rk[U[i]] ^ rk[V[i]]), putc('\n');
      }
    } else {
      putc('N'), putc('O'), putc('\n');
    }
  }
  flush();
  return 0;
}
