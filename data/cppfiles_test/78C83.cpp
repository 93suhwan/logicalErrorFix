#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <typename T>
inline void redi(T& ret) {
  ret = 0;
  T f = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (ch >= '0' && ch <= '9')
    ret = ret * 10 + ch - '0',
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  ret *= f;
}
template <typename T, typename... Args>
inline void redi(T& t, Args&... args) {
  redi(t);
  redi(args...);
}
char buffer[1 << 21];
long long p11 = -1;
const long long p22 = (1 << 21) - 1;
inline void flush() { fwrite(buffer, 1, p11 + 1, stdout), p11 = -1; }
inline void putc(const char& x) {
  if (p11 == p22) flush();
  buffer[++p11] = x;
}
template <typename T>
inline void wrtn(T x) {
  static char buf[15];
  static T len = -1;
  if (x >= 0) {
    do {
      buf[++len] = x % 10 + 48, x /= 10;
    } while (x);
  } else {
    putc('-');
    do {
      buf[++len] = -(x % 10) + 48, x /= 10;
    } while (x);
  }
  while (len >= 0) {
    putc(buf[len]), --len;
  }
}
template <typename T>
inline void wrti(T x) {
  wrtn(x), putc('\n');
}
template <typename T>
inline void wrtk(T x) {
  wrtn(x), putc(' ');
}
long long t, n, a[200010], bit[40], mx;
vector<long long> v;
signed main() {
  redi(t);
  while (t--) {
    v.clear();
    redi(n);
    mx = -1e9;
    for (long long i = 1; i <= n; i++) redi(a[i]), mx = max(a[i], mx);
    memset(bit, 0, sizeof bit);
    for (long long i = 1; i <= n; i++) {
      for (long long j = 0; j < 32 && a[i]; j++) {
        if (a[i] & 1) ++bit[j];
        a[i] >>= 1;
      }
    }
    for (long long i = 1; i <= n; i++) {
      long long tag = 1;
      for (long long j = 0; j <= 30; j++) {
        if (bit[j] && bit[j] % i != 0) {
          tag = 0;
          break;
        }
      }
      if (tag) v.emplace_back(i);
    }
    for (auto i : v) wrtk(i);
    putc('\n');
  }
  flush();
  return 0;
}
