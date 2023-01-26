#include <bits/stdc++.h>
using namespace std;
long long T, n;
long long a[200001];
signed main() {
  scanf("%lld", &n);
  long long sum = 0;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), sum += a[i];
  sort(a + 1, a + n + 1);
  scanf("%lld", &T);
  while (T--) {
    long long p, q;
    scanf("%lld%lld", &p, &q);
    long long at1 = lower_bound(a + 1, a + n + 1, p) - a;
    long long minc = 0;
    if (at1 == n + 1) {
      minc = p - a[n] + max(0ll, q - (sum - a[n]));
    } else {
      minc = max(0ll, q - (sum - a[at1]));
      if (at1 != 1)
        minc = min(minc, p - a[at1 - 1] + max(0ll, q - (sum - a[at1 - 1])));
    }
    cout << minc << endl;
  }
  return 0;
}
