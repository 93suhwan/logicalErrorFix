#include <bits/stdc++.h>
using namespace std;
long long ggcd(long long a, long long b) {
  if (!a) return b;
  if (!b) return a;
  return ggcd(b % a, a);
}
int t, n;
long long a[110];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long v1 = 0, v2 = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2)
        v1 = ggcd(v1, a[i]);
      else
        v2 = ggcd(v2, a[i]);
    }
    bool ok1 = 1, ok2 = 1;
    for (int i = 1; i < n; i += 2)
      if (a[i] % v2 == 0) ok2 = 0;
    for (int i = 0; i < n; i += 2)
      if (a[i] % v1 == 0) ok1 = 0;
    if (ok1)
      printf("%lld\n", v1);
    else if (ok2)
      printf("%lld\n", v2);
    else
      printf("0\n");
  }
}
