#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000 + 5;
int n, T;
int a[MAX_N], b[MAX_N];
bool check(long long x) {
  for (int i = 1; i <= n; i++) b[i] = a[i];
  for (int i = 3; i <= n; i++) {
    if (a[i - 2] < x) {
      int t = x - a[i - 2];
      int tt = t / 2 + (t & 1);
      tt = min(a[i] / 3, tt);
      a[i] -= 3 * tt, a[i - 1] += tt, a[i - 2] += 2 * tt;
    }
    if (a[i - 1] < x) {
      int tt = x - a[i - 1];
      tt = min(a[i] / 3, tt);
      a[i] -= 3 * tt, a[i - 1] += tt, a[i - 2] += 2 * tt;
    }
  }
  int minn = 1e9;
  for (int i = 1; i <= n; i++) minn = min(minn, a[i]), a[i] = b[i];
  return minn >= x;
}
void _main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 1, r = 1e9, ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) _main();
  return 0;
}
