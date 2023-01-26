#include <bits/stdc++.h>
deque > using namespace std;
mt19937 rng(time(0));
int randint(int l, int r) { return (rng() & 0x7fffffff) % (r - l + 1) + 1; }
const int N = 500100;
struct alp {
  int a, s;
  bool operator<(const alp &b) const { return s == b.s ? a < b.a : s < b.s; }
} a[N];
int n, d, x[N], f[N], num[N];
int main() {
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].s, &a[i].a);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    x[i] = a[i].s;
    num[i] = num[i - 1] + (a[i].s >= a[i].a);
  }
  for (int i = n; i >= 1; i--) {
    if (a[i].s >= a[i].a) {
      f[i] = f[i + 1] + 1;
      continue;
    }
    int p = lower_bound(x + 1, x + n + 1, a[i].a) - x;
    f[i] = max(f[i + 1], f[p] + 1 + num[p - 1] - num[i]);
  }
  int p = lower_bound(x + 1, x + n + 1, d) - x;
  printf("%d\n", f[p]);
}
