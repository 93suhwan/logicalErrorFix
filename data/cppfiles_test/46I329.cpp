#include <bits/stdc++.h>
using namespace std;
int a[1000 + 5];
int main() {
  int n, i, j, ans = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i += 2) {
    int minn = a[i] - 1, sum = a[i];
    for (j = i + 1; j <= n; j++) {
      if (j & 1)
        sum += a[j];
      else {
        int lx = sum - minn, rx = sum;
        ans += max(min(rx, a[j]) - max(lx, 1) + 1, 0);
        if (sum < a[j]) break;
        sum -= a[j];
        minn = min(minn, sum);
      }
    }
  }
  printf("%d\n", ans);
}
