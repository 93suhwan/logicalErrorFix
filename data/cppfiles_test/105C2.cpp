#include <bits/stdc++.h>
using namespace std;
inline void rd(char *x) { scanf("%s", x); }
inline void rd(double &x) { scanf("%lf", &x); }
template <typename T>
inline void rd(T &x) {
  x = 0;
  bool is = 0;
  char ch = getchar();
  while (!isdigit(ch)) is |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  is && (x = -x);
}
template <typename T, typename... U>
inline void rd(T &x, U &...y) {
  rd(x), rd(y...);
}
template <typename T>
inline void write(T x) {
  if (x >= 10) write(x / 10);
  putchar('0' + x % 10);
}
const int maxn = 214514;
struct node {
  int a, b, m, s, id;
  int l, r;
  node() {}
  node(int a, int b, int m, int id)
      : a(a),
        b(b),
        m(m),
        s(a + b - m),
        id(id),
        l(max(0, a - m)),
        r(a - max(0, m - b)) {}
  bool operator<(const node &oth) const {
    if (s != oth.s) return s < oth.s;
    return l < oth.l;
  }
} t[maxn];
int ans[maxn][2], n;
const int inf = 0x3fffffff;
int main() {
  int T;
  rd(T);
  for (int kase = (1), __kase = (T); kase <= __kase; ++kase) {
    rd(n);
    for (int i = (1), __i = (n); i <= __i; ++i) {
      int a, b, m;
      rd(a, b, m);
      t[i] = node(a, b, m, i);
    }
    sort(t + 1, t + n + 1);
    int pre = 1, mnr = inf, cnt = 0;
    for (int cur = (1), __cur = (n + 1); cur <= __cur; ++cur) {
      if ((cur != 1 && t[cur].s != t[cur - 1].s) || (t[cur].l > mnr) ||
          cur == n + 1) {
        ++cnt;
        for (int i = (pre), __i = (cur - 1); i <= __i; ++i) {
          int id = t[i].id;
          ans[id][0] = t[i].a - mnr;
          ans[id][1] = t[i].m - ans[id][0];
        }
        pre = cur, mnr = inf;
      }
      mnr = min(mnr, t[cur].r);
    }
    printf("%d\n", cnt);
    for (int i = (1), __i = (n); i <= __i; ++i)
      printf("%d %d\n", ans[i][0], ans[i][1]);
  }
}
