#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int wx = 0, fsi = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fsi = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    wx = wx * 10 + ch - '0';
    ch = getchar();
  }
  return wx * fsi;
}
struct node {
  int s, a;
} cl[500005];
int n, d, ans;
bool cmp(const node &x, const node &y) {
  if (max(x.a, x.s) == max(y.a, y.s)) return x.s < y.s;
  return max(x.a, x.s) < max(y.a, y.s);
}
signed main(signed argc, char const *argv[]) {
  clock_t c1 = clock();
  n = read();
  d = read();
  for (int i = 1; i <= n; ++i) {
    cl[i].s = read();
    cl[i].a = read();
  }
  sort(cl + 1, cl + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    if (cl[i].s >= d) {
      ++ans;
      d = max(d, cl[i].a);
    }
  }
  printf("%d", ans);
  cerr << "Time Used:" << clock() - c1 << "ms" << endl;
  return 0;
}
