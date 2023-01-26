#include <bits/stdc++.h>
using namespace std;
long long n, a[1010];
int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  long long ans = 0;
  for (int i = 0; i < n; i += 2) {
    long long between = 0;
    for (int j = i + 1; j < n; j += 2) {
      long long rem1 = a[i], rem2 = a[j];
      if (between > 0)
        rem2 -= between;
      else
        rem1 += between;
      if (rem1 <= 0 || rem2 <= 0) continue;
      ans += min(rem1, rem2);
      between -= a[j];
      if (j + 1 < n) between += a[j + 1];
    }
  }
  printf("%lld\n", ans);
}
