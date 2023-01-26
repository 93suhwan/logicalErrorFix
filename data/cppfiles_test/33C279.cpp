#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long a[300005];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    long long ans = 0;
    for (long long i = 1; i < n; i++) {
      ans = max(ans, a[i] * a[i + 1]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
