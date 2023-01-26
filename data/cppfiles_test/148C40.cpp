#include <bits/stdc++.h>
using namespace std;
long long t;
long long n, m;
long long k;
long long all;
int main(void) {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &n, &m);
    long long ans = 0;
    for (long long i = 0; i < 2; i++) {
      scanf("%lld", &k);
      vector<long long> vec;
      for (long long j = 0; j < k; j++) {
        scanf("%lld", &all);
        vec.push_back(all);
      }
      sort(vec.begin(), vec.end());
      ans = max(ans, (vec.back() - vec[0]) * m);
    }
    for (long long i = 0; i < 2; i++) {
      scanf("%lld", &k);
      vector<long long> vec;
      for (long long j = 0; j < k; j++) {
        scanf("%lld", &all);
        vec.push_back(all);
      }
      sort(vec.begin(), vec.end());
      ans = max(ans, (vec.back() - vec[0]) * n);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
