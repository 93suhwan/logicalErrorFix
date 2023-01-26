#include <bits/stdc++.h>
using namespace std;
long long n;
double p;
long long C1(long long x) { return x; }
long long C2(long long x) { return x * (x - 1) / 2; }
long long C3(long long x) { return x * (x - 1) * (x - 2) / 6; }
signed main() {
  scanf("%lld%lf", &n, &p);
  long long l = 0, r = n, ans;
  while (l <= r) {
    long long mid = l + r >> 1;
    long long c0 = C3(n - mid), c1 = C1(mid) * C2(n - mid),
              c2 = C2(mid) * C1(n - mid), c3 = C3(mid);
    double tmp = (c3 + c2 + c1 * 0.5) / (c3 + c2 + c1 + c0);
    if (tmp >= p)
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  printf("%lld", ans);
  return 0;
}
