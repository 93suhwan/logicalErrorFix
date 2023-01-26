#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  char ch, t = 0;
  while (!isdigit(ch = getchar())) t |= ch == '-';
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x = t ? -x : x;
}
inline long long maxll(long long x, long long y) { return x > y ? x : y; }
inline long long minll(long long x, long long y) { return x < y ? x : y; }
inline long long absll(long long x) { return x > 0ll ? x : -x; }
inline long long gcd(long long x, long long y) {
  return (y == 0) ? x : gcd(y, x % y);
}
int T, n;
long long ans, All, k, a[200005], sum[200005];
bool cmp(long long x, long long y) { return x < y; }
int main() {
  T = rd();
  while (T--) {
    n = rd(), k = rd(), sum[n + 1] = sum[0] = All = 0, ans = 0x7f7f7f7f7f7f7f7f;
    for (int i = 1; i <= n; i++) a[i] = rd(), All += a[i];
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) sum[i] = a[i] - a[1];
    for (int i = n; i >= 0; i--) sum[i] += sum[i + 1];
    if (All <= k) {
      printf("0\n");
      continue;
    }
    ans = All - k;
    for (int l = 1; l < n; l++) {
      long long tmp = (All - k - sum[l + 1] + 1ll * n - 1ll * l) /
                      (1ll * n - 1ll * l + 1ll);
      if (All - k - sum[l + 1] + 1ll * n - 1ll * l <= 0) tmp = 0;
      ans = minll(ans, tmp + 1ll * n - 1ll * l);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
