#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
struct S {
  int s, a;
  bool operator<(const S& x) const {
    if (max(s, a) == max(x.s, x.a)) return s < x.s;
    return max(s, a) < max(x.s, x.a);
  }
} a[MAXN];
int n, d;
int main() {
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].s, &a[i].a);
  sort(a + 1, a + 1 + n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (d <= a[i].s) {
      cnt++;
      d = max(d, a[i].a);
    }
  }
  printf("%d\n", cnt);
  return 0;
}
