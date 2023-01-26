#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int t = 3 * 1e3;
long long a[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    long long ans = -0x3f3f3f3f;
    for (int i = n; i >= max((int)n - t, 1); i--) {
      for (int j = i - 1; j >= max((int)n - t, 1); j--) {
        ans = max(ans, i * j - k * (a[i] | a[j]));
      }
    }
    printf("%lld\n", ans);
  }
}
