#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 5;
const int MR = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
int read() {
  int x = 0, bei = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') bei = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * bei;
}
struct Node {
  int x, y, m, id;
  bool operator<(const Node &b) const {
    if (x + y - m != b.x + b.y - b.m) return x + y - m < b.x + b.y - b.m;
    return y < b.y;
  }
} a[NR];
int ans1[NR], ans2[NR];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].m), a[i].id = i;
    sort(a + 1, a + n + 1);
    int nw = 1e9;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (i == 1 ||
          a[i].x + a[i].y - a[i].m != a[i - 1].x + a[i - 1].y - a[i - 1].m)
        nw = 1e9;
      if (a[i].y - a[i].m > nw || nw > a[i].y ||
          (a[i].m - (a[i].y - nw) > a[i].x))
        ++ans, nw = min(a[i].y - a[i].m + a[i].x, a[i].y);
      ans2[a[i].id] = a[i].y - nw, ans1[a[i].id] = a[i].m - ans2[a[i].id];
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) printf("%d %d\n", ans1[i], ans2[i]);
  }
  return 0;
}
