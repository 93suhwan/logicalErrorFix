#include <bits/stdc++.h>
using namespace std;
long long n, m, sq[100069];
pair<long long, long long> a[200069];
int main() {
  long long t, rr, i, k, l, sm, w;
  scanf("%lld", &t);
  for (rr = 0; rr < t; rr++) {
    scanf("%lld%lld", &n, &m);
    sm = 0;
    for (i = 1; i <= n; i++) {
      scanf("%lld%lld", &k, &l);
      k = min(k, m);
      l = max(m - l, 0ll);
      a[i] = {l, k};
      sm += k - (m - k);
    }
    for (i = 1; i <= n; i++) {
      k = a[i].first;
      l = a[i].second;
      w = min(max(sm, 0ll) / 2, l - k);
      sm -= w * 2;
      sq[i] = l - w;
    }
    printf("%lld\n", abs(sm));
    for (i = 1; i <= n; i++) {
      printf("%lld %lld\n", sq[i], m - sq[i]);
    }
  }
}
