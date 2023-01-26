#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
template <typename T>
inline void read(T &WOW) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  WOW = flag * x;
}
int n, tot, d;
struct Node {
  int r, s, a;
  bool operator<(const Node &rhs) const {
    if (r != rhs.r) return (r < rhs.r);
    if (s != rhs.s) return (s < rhs.s);
    return (a < rhs.a);
  }
} c[MAXN];
void solve() {
  read(n);
  read(d);
  for (int i = 1, s, a; i <= n; ++i) {
    read(s);
    read(a);
    if (s >= d) {
      c[++tot] = (Node){max(s, a), s, a};
    }
  }
  sort(c + 1, c + tot + 1);
  int ans = 0;
  for (int i = 1; i <= tot; ++i) {
    if (c[i].s >= d) {
      ++ans;
      d = max(d, c[i].a);
    }
  }
  printf("%d\n", ans);
}
int main() {
  solve();
  return 0;
}
