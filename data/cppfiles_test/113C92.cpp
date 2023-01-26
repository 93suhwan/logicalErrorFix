#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long a;
    scanf("%lld", &a);
    sum += a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  int m;
  scanf("%d", &m);
  while (m--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    vector<long long>::iterator it = lower_bound(v.begin(), v.end(), x);
    if (it != v.end()) {
      long long s = sum - (*it);
      if (s >= y) {
        printf("0\n");
      } else {
        long long p = y - s;
        if (it != v.begin()) {
          it--;
          long long q = sum - (*it);
          long long r = x - (*it);
          if (q >= y) {
            long long l = min(p, r);
            printf("%lld\n", l);
          } else {
            long long l = min(p, (r + (y - q)));
            printf("%lld\n", l);
          }
        } else {
          printf("%lld\n", p);
        }
      }
      continue;
    }
    long long s = sum - v[n - 1];
    if (s >= y) {
      long long l = x - v[n - 1];
      printf("%lld\n", l);
    } else {
      long long l = (y - s) + (x - v[n - 1]);
      printf("%lld\n", l);
    }
  }
  return 0;
}
