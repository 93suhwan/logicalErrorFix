#include <bits/stdc++.h>
using namespace std;
long long a, b, T, q, w, e, d[100001], v[100001], t[100001], B = 2;
int main() {
  scanf("%lld%lld", &a, &b);
  for (int i = 1; i <= a; i++) scanf("%lld", &d[i]), v[d[i]] = i, t[i] = i;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= B; j++) t[i] = d[t[i]];
  for (int ii = 1; ii <= b; ii++) {
    scanf("%lld%lld%lld", &q, &w, &e);
    if (q == 1) {
      swap(d[w], d[e]);
      swap(v[d[w]], v[d[e]]);
      long long tt = e, yy = v[t[d[e]]];
      for (int i = 1; i <= B; i++) t[tt] = yy, tt = v[tt], yy = v[yy];
      tt = w, yy = v[t[d[w]]];
      for (int i = 1; i <= B; i++) t[tt] = yy, tt = v[tt], yy = v[yy];
    } else {
      long long ff = w;
      for (int i = 1; i <= e / B; i++) ff = t[ff];
      e %= B;
      for (int i = 1; i <= e; i++) ff = d[ff];
      printf("%lld\n", ff);
    }
  }
  return 0;
}
