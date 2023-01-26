#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], x, y, sum;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  sort(a + 1, a + 1 + n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%lld%lld", &x, &y);
    int j = lower_bound(a + 1, a + 1 + n, x) - a;
    if (j > n) j = j - 1;
    if (j == 1) j = j + 1;
    long long cost =
        min(max(x - a[j], 0ll) + max(0ll, y - (sum - a[j])),
            max(x - a[j - 1], 0ll) + max(0ll, y - (sum - a[j - 1])));
    printf("%lld\n", cost);
  }
  return 0;
}
