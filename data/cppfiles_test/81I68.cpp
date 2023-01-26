#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
int randint(int l, int r) { return (rng() & 0x7fffffff) % (r - l + 1) + 1; }
const int N = 500100;
struct alp {
  int a, s;
  bool operator<(const alp &b) const { return s < b.s; }
} a[N];
int n, d, x[N], f[N], g[N], h[N], p[N], y[N << 1];
vector<int> buc[N << 1];
int bit[N << 1];
int lowbit(int x) { return x & (-x); }
int qsum(int x) {
  int k = 0;
  for (; x <= n + n; x += lowbit(x)) k += bit[x];
  return k;
}
void modify(int x, int k) {
  for (; x; x ^= lowbit(x)) bit[x] += k;
}
int main() {
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; i++)
    scanf("%d %d", &a[i].s, &a[i].a), y[i] = a[i].s, y[i + n] = a[i].a;
  sort(y + 1, y + n + n + 1);
  d = lower_bound(y + 1, y + n + n + 1, d) - y;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    x[i] = a[i].s = lower_bound(y + 1, y + n + n + 1, a[i].s) - y;
    a[i].a = lower_bound(y + 1, y + n + n + 1, a[i].a) - y;
  }
  for (int i = 1; i <= n; i++)
    if (a[i].s < a[i].a) {
      p[i] = upper_bound(x + 1, x + n + 1, a[i].a) - x - 1;
      buc[p[i]].emplace_back(i);
    }
  for (int i = 1; i <= n; i++) {
    if (a[i].a <= a[i].s)
      modify(a[i].a, 1), modify(a[i].s + 1, -1);
    else
      g[i] -= qsum(a[i].s);
    for (int p : buc[i]) g[p] += qsum(a[p].s);
  }
  for (int i = n; i >= 1; i--) {
    if (a[i].s >= a[i].a) {
      f[i] = f[i + 1] + 1;
      continue;
    }
    f[i] = max(f[i + 1], f[p[i]] + 1 + g[i]);
  }
  int p = lower_bound(x + 1, x + n + 1, d) - x;
  printf("%d\n", f[p]);
}
