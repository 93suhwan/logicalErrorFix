#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
T firstTrue(T lo, T hi, U f) {
  assert(lo <= hi);
  ++hi;
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lastTrue(T lo, T hi, U f) {
  assert(lo <= hi);
  --lo;
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<long long> aa(n);
    for (int i = 0; i < n; i++) scanf("%lld", &aa[i]);
    printf("%d\n", lastTrue(1, 1000000000, [&](long long x) {
             vector<long long> a = aa;
             for (int i = 2; i < n; i++) {
               long long h = max({0LL, (x - a[i - 2] + 1) / 2, x - a[i - 1]});
               h = min(h, a[i] / 3);
               if (h >= 0) {
                 a[i] -= 3 * h;
                 a[i - 1] += h;
                 a[i - 2] += 2 * h;
               }
             }
             for (long long i : a)
               if (i < x) return false;
             return true;
           }));
  }
  return 0;
}
