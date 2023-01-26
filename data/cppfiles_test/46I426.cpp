#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
long long res, a[N];
vector<long long> v, pv;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]), v.push_back(a[i]);
  int psz = n;
  while (psz > 1) {
    pv.clear();
    int sz = 0, k = 0;
    for (int i = 0; i < psz; i += 2) {
      if (i == psz - 1) continue;
      if (v[i + 1] >= v[i]) res += k;
      if (v[i + 1] > v[i])
        k = 0;
      else if (v[i + 1] < v[i])
        k = 1;
      else if (v[i] == v[i + 1])
        k++;
    }
    for (int i = 0; i < psz; i += 2) {
      if (i == psz - 1) continue;
      long long d = llabs(v[i] - v[i + 1]);
      res += min(v[i], v[i + 1]);
      if (v[i] > v[i + 1]) {
        if (!(sz & 1))
          pv.push_back(d), sz++;
        else
          pv[sz - 1] += d;
      } else if (v[i] < v[i + 1]) {
        if (!(sz & 1)) {
          if (sz > 0) pv[sz - 1] += d;
        } else
          pv.push_back(d), sz++;
      }
    }
    if (sz == psz) return printf("%lld\n", res), 0;
    v = pv;
    psz = sz;
  }
  return printf("%lld\n", res), 0;
}
