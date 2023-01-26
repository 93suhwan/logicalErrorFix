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
const int MaxN = 105;
int n;
inline int ask(int x, int opt) {
  printf("?");
  for (int i = (1); i <= (n); ++i)
    if (!opt)
      std::printf(" %d", 1 + (i == x));
    else
      std::printf(" %d", 2 - (i == x));
  printf("\n");
  int y;
  std::cin >> y;
  return y;
}
int pre[MaxN], to[MaxN], ans[MaxN];
inline void got() {
  printf("!");
  for (int i = (1); i <= (n); ++i) std::printf(" %d", ans[i]);
  printf("\n");
}
inline void work() {
  std::cin >> n;
  for (int i = (1); i <= (n); ++i) {
    int j = ask(i, 0);
    if (j && j != i) pre[j] = i, to[i] = j;
  }
  for (int i = (1); i <= (n); ++i) {
    int j = ask(i, 1);
    if (j && j != i) pre[i] = j, to[j] = i;
  }
  int x = 1;
  for (int i = (1); i <= (n); ++i)
    if (!to[i]) x = i;
  ans[x] = n, x = pre[x];
  int pos = n - 1;
  while (x) ans[x] = pos--, x = pre[x];
  got();
}
signed main(void) {
  int t = 1;
  while (t--) work();
  return 0;
}
