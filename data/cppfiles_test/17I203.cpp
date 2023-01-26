#include <bits/stdc++.h>
using namespace std;
struct node {
  long long a, b, c, d, e, zs, bh;
} s[50004];
bool cmpa(node x, node y) { return x.a < y.a; }
bool cmpb(node x, node y) { return x.b < y.b; }
bool cmpc(node x, node y) { return x.c < y.c; }
bool cmpd(node x, node y) { return x.d < y.d; }
bool cmpe(node x, node y) { return x.e < y.e; }
bool cmpzs(node x, node y) { return x.zs < y.zs; }
long long p[50004];
int main() {
  long long t, n, i, j, k, a, b, c, d, e, zx, pd, zc;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
      scanf("%lld%lld%lld%lld%lld", &s[i].a, &s[i].b, &s[i].c, &s[i].d,
            &s[i].e);
      s[i].zs = 0;
      s[i].bh = i;
    }
    sort(s + 1, s + 1 + n, cmpa);
    for (i = 1; i <= n; i++) s[i].zs += i;
    sort(s + 1, s + 1 + n, cmpb);
    for (i = 1; i <= n; i++) s[i].zs += i;
    sort(s + 1, s + 1 + n, cmpc);
    for (i = 1; i <= n; i++) s[i].zs += i;
    sort(s + 1, s + 1 + n, cmpd);
    for (i = 1; i <= n; i++) s[i].zs += i;
    sort(s + 1, s + 1 + n, cmpe);
    for (i = 1; i <= n; i++) s[i].zs += i;
    sort(s + 1, s + 1 + n, cmpzs);
    for (i = 2, pd = 1; i <= n; i++) {
      zc = 0;
      if (s[1].a < s[i].a) zc++;
      if (s[1].b < s[i].b) zc++;
      if (s[1].c < s[i].c) zc++;
      if (s[1].d < s[i].d) zc++;
      if (s[1].e < s[i].e) zc++;
      if (zc < 3) {
        pd = 0;
        break;
      }
    }
    if (pd == 1)
      printf("%lld\n", s[1].bh);
    else
      printf("-1\n");
  }
  return 0;
}
