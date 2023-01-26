#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[200005], ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    if (n == 1) {
      printf("%lld\n", a[0]);
      continue;
    }
    sort(a, a + n);
    long long temp = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) temp -= (a[i]);
    }
    if (a[n - 2] >= 0) {
      ans = a[n - 1] - a[n - 2];
    } else {
      ans = a[n - 1] - temp;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
