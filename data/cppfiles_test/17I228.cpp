#include <bits/stdc++.h>
using namespace std;
struct node {
  long long a, b, c, d, e, zs, bh;
  long long pm[6];
} s[50005];
long long slsl, n;
bool cmpa(node x, node y) { return x.a < y.a; }
bool cmpb(node x, node y) { return x.b < y.b; }
bool cmpc(node x, node y) { return x.c < y.c; }
bool cmpd(node x, node y) { return x.d < y.d; }
bool cmpe(node x, node y) { return x.e < y.e; }
bool cmpzs(node x, node y) { return x.zs < y.zs; }
bool cmpbh(node x, node y) { return x.bh < y.bh; }
bool cmp(node x, node y) {
  slsl++;
  if (slsl >= n * 100) return 0;
  return (x.a < y.a + x.b < y.b + x.c < y.c + x.d < y.d + x.e < y.e) >= 3;
}
long long p[50004];
int main() {
  long long t, i, j, k, a, b, c, d, e, zx, pd, zc;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
      scanf("%lld%lld%lld%lld%lld", &s[i].a, &s[i].b, &s[i].c, &s[i].d,
            &s[i].e);
      s[i].zs = 0;
      s[i].bh = i;
    }
    slsl = 0;
    sort(s + 1, s + 1 + n, cmp);
    for (j = 1; j <= min(150ll, n); j++) {
      for (i = 1, pd = 1; i <= n; i++) {
        if (i == j) continue;
        zc = 0;
        if (s[j].a < s[i].a) zc++;
        if (s[j].b < s[i].b) zc++;
        if (s[j].c < s[i].c) zc++;
        if (s[j].d < s[i].d) zc++;
        if (s[j].e < s[i].e) zc++;
        if (zc < 3) {
          pd = 0;
          break;
        }
      }
      if (pd == 1) break;
    }
    if (pd == 1)
      printf("%lld\n", s[j].bh);
    else
      printf("-1\n");
  }
  return 0;
}
