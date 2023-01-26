#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    long long maxv = *max_element(a.begin(), a.end()), ans = 0;
    for (int i = 0; i < n; ++i)
      if (a[i] == maxv) {
        if (i + 1 < n && a[i + 1] == maxv) {
          ans = a[i] * a[i];
          break;
        } else {
          if (i - 1 >= 0) ans = max(ans, a[i] * a[i - 1]);
          if (i + 1 < n) ans = max(ans, a[i] * a[i + 1]);
        }
      }
    printf("%I64d\n", ans);
  }
}
