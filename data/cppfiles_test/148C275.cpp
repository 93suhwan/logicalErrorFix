#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long b[202000];
long long c[202000];
long long d[202000];
signed main() {
  long long T, w, h;
  cin >> T;
  while (T--) {
    cin >> w >> h;
    long long ans = 0;
    long long k;
    cin >> k;
    long long ma = 0;
    for (long long i = 1; i <= k; i++) {
      cin >> a[i];
    }
    ans = max(a[k] * h - a[1] * h, ans);
    cin >> k;
    ma = 0;
    for (long long i = 1; i <= k; i++) {
      cin >> b[i];
      ma = max(ma, b[i] - b[i - 1]);
    }
    ans = max(ans, (b[k] - b[1]) * h);
    cin >> k;
    ma = 0;
    for (long long i = 1; i <= k; i++) {
      cin >> b[i];
      ma = max(ma, b[i] - b[i - 1]);
    }
    ans = max(ans, (b[k] - b[1]) * w);
    cin >> k;
    ma = 0;
    for (long long i = 1; i <= k; i++) {
      cin >> b[i];
      ma = max(ma, b[i] - b[i - 1]);
    }
    ans = max(ans, (b[k] - b[1]) * w);
    printf("%lld\n", ans);
  }
}
