#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
char Buf[1 << 23], *P1 = Buf, *P2 = Buf;
template <typename Tp = int>
inline Tp read() {
  Tp x = 0;
  bool f = false;
  char ch =
      (P1 == P2 && (P2 = (P1 = Buf) + fread(Buf, 1, 1 << 23, stdin), P1 == P2)
           ? EOF
           : *P1++);
  while (ch < '0' || ch > '9')
    f |= (ch == '-'),
        ch = (P1 == P2 && (P2 = (P1 = Buf) + fread(Buf, 1, 1 << 23, stdin),
                           P1 == P2)
                  ? EOF
                  : *P1++);
  while (ch >= '0' && ch <= '9')
    x = x * 10 + (ch ^ 48),
    ch =
        (P1 == P2 && (P2 = (P1 = Buf) + fread(Buf, 1, 1 << 23, stdin), P1 == P2)
             ? EOF
             : *P1++);
  return f ? -x : x;
}
template <typename Tp>
inline void read(Tp &x) {
  x = read<Tp>();
}
template <typename Tp1, typename... Tp2>
inline void read(Tp1 &x, Tp2 &...y) {
  read(x), read(y...);
}
constexpr int Max = 1e5 + 100;
constexpr int max_num = 8192;
int n, x;
bool can[max_num];
vector<int> f[max_num];
int pre[max_num];
signed main() {
  read(n);
  for (int i = 0; i < max_num; ++i) f[i].emplace_back(0), pre[i] = max_num;
  can[0] = 1;
  while (n--) {
    int i;
    read(i);
    for (int x : f[i]) {
      const int y = x ^ i;
      can[y] = true;
      while (pre[y] > i) {
        --pre[y];
        if (pre[y] > i) f[pre[y]].emplace_back(y);
      }
    }
    f[i].clear();
  }
  int ans = 0;
  for (int i = 0; i < max_num; ++i) ans += can[i];
  printf("%d\n", ans);
  for (int i = 0; i < max_num; ++i)
    if (can[i]) printf("%d ", i);
  putchar('\n');
  return 0;
}
