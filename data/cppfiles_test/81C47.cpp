#include <bits/stdc++.h>
using namespace std;
int n, d;
struct node {
  int s, t;
} a[500005];
template <typename _T>
void rd(_T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9')
    x = (x << 3) + (x << 1) + (s ^ 48), s = getchar();
  x *= f;
}
bool cmp(const node &x, const node &y) {
  if (max(x.s, x.t) < max(y.s, y.t)) return true;
  if (max(x.s, x.t) == max(y.s, y.t) && x.s < y.s) return true;
  return false;
}
int main() {
  rd(n), rd(d);
  for (register int i(1); i <= n; ++i) rd(a[i].s), rd(a[i].t);
  sort(a + 1, a + 1 + n, cmp);
  int ans = 0;
  for (register int i(1); i <= n; ++i)
    if (a[i].s >= d) d = max(d, a[i].t), ++ans;
  printf("%d", ans);
  return 0;
}
