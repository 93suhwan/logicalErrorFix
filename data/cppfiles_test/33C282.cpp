#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 109;
long long t;
long long n;
long long a[N];
long long ans = 0;
signed main() {
  scanf("%lld", &t);
  while (t--) {
    ans = 0;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (long long i = 2; i <= n; i++) ans = max(ans, a[i] * a[i - 1]);
    cout << ans << endl;
  }
  return 0;
}
