#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long v[1000005];
long long n, d;
long long fi(long long x) {
  v[x] = 1;
  if (!a[x]) return 0;
  return fi((x + d) % n) + 1;
}
int main() {
  long long tt;
  scanf("%lld", &tt);
  while (tt--) {
    scanf("%lld%lld", &n, &d);
    for (long long i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (long long i = 0; i < n; i++) v[i] = 0;
    long long len = -1;
    for (long long i = 0; i < n; i++)
      if (!a[i]) {
        v[i] = 1;
        len = max(len, fi((i + d) % n));
      }
    long long flag = 1;
    for (long long i = 0; i < n; i++)
      if (!v[i]) flag = 0;
    if (flag)
      printf("%lld\n", len);
    else
      printf("-1\n");
  }
  return 0;
}
