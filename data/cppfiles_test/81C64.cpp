#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
int randint(int l, int r) { return (rng() & 0x7fffffff) % (r - l + 1) + 1; }
const int N = 500100;
struct alp {
  int a, s;
  bool operator<(const alp &b) const {
    return min(a, s) == min(b.a, b.s) ? max(a, s) > max(b.a, b.s)
                                      : min(a, s) > min(b.a, b.s);
  }
} a[N], b[N];
int n, m, d;
int main() {
  scanf("%d %d", &n, &d);
  int num = 0, tn = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].s, &a[i].a);
    if (a[i].s >= d) a[++tn] = a[i];
  }
  n = tn, sort(a + 1, a + n + 1);
  for (int i = 1, mn = 2e9; i <= n; i++) {
    if (a[i].a <= a[i].s)
      mn = min(mn, a[i].s), num++;
    else if (mn >= a[i].a)
      b[++m] = a[i];
  }
  sort(b + 1, b + m + 1, [](const alp &a, const alp &b) { return a.a < b.a; });
  for (int i = 1, p = 0; i <= m; i++)
    if (b[i].s >= p) p = b[i].a, num++;
  printf("%d\n", num);
}
