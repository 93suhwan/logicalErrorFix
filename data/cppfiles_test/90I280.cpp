#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long x, y, n;
int t;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &x, &y);
    long long l = 0, r = 2e18 + 1;
    while (l < r) {
      long long mid = l + r >> 1ll;
      if (mid % x < y % mid)
        l = mid + 1;
      else
        r = mid;
    }
    printf("%lld\n", r);
  }
  return 0;
}
