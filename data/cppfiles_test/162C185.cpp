#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000 + 5;
int n, T;
int a[MAX_N], b[MAX_N];
bool check(long long x) {
  for (int i = 1; i <= n; i++) b[i] = 0;
  for (int i = n; i >= 3; i--) {
    if (a[i] + b[i] > x) {
      int d = (a[i] + b[i] - x) / 3;
      d = min(d, a[i] / 3);
      b[i] -= d * 3, b[i - 1] += d, b[i - 2] += d * 2;
    }
  }
  int minn = 1e9;
  for (int i = 1; i <= n; i++) minn = min(minn, a[i] + b[i]);
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
