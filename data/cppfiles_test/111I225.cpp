#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool read(T& x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c) && (c != '-') && (c != EOF)) c = getchar();
  if (c == EOF) return 0;
  if (c == '-') f = -1, c = getchar();
  while (isdigit(c)) {
    x = x * 10 + (c & 15);
    c = getchar();
  }
  x *= f;
  return 1;
}
template <typename T, typename... Args>
inline bool read(T& x, Args&... args) {
  bool res = 1;
  res &= read(x);
  res &= read(args...);
  return res;
}
const int M = 1000000007, INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int N = 1000009;
int n;
inline void f(int x) {
  for (int i = (1), (ii) = (x); i <= (ii); ++i) {
    for (int j = (1), (jj) = (x); j <= (jj); ++j) putchar('(');
    for (int j = (1), (jj) = (x); j <= (jj); ++j) putchar(')');
    for (int j = (x + 1), (jj) = (n); j <= (jj); ++j) printf("()");
    putchar('\n');
  }
}
inline void init() {
  read(n);
  f(n);
}
inline void solve() {}
signed main() {
  int t;
  read(t);
  while (t--) {
    init();
    solve();
  }
  return 0;
}
