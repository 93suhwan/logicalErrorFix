#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
  int x, y, num;
  bool operator<(const node b) const { return x > b.x; }
} a[N];
int t, n, mar[N], ans[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(mar, 0, sizeof mar);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].x), a[i].num = i;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].y);
    stable_sort(a + 1, a + n + 1);
    int ma = -1e9;
    for (int i = n; i >= 1; i--) {
      ma = max(ma, a[i].y);
      if (ma >= a[1].y)
        ans[a[i].num] = 1;
      else
        ans[a[i].num] = 0;
    }
    for (int i = 1; i <= n; i++) printf("%d", ans[i]);
    puts("");
  }
  return 0;
}
