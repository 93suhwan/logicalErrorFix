#include <bits/stdc++.h>
using namespace std;
long long s[200005], pp[200005], qq[200005], p[200005];
int main() {
  long long t, n, i, j, k, a, b, pd, zc;
  string sr;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) scanf("%lld", &s[i]);
    sr.resize(n);
    scanf("%s", &sr[0]);
    for (i = a = b = 0; i <= n - 1; i++) {
      if (sr[i] == 'R')
        pp[++a] = s[i + 1];
      else
        qq[++b] = s[i + 1];
    }
    sort(qq + 1, qq + 1 + b);
    sort(pp + 1, pp + 1 + a);
    for (i = 1; i <= b; i++) p[i] = qq[i];
    for (i = 1; i <= a; i++) p[i + b] = pp[i];
    for (i = pd = 1; i <= n; i++) {
      if (i <= b) {
        if (i > p[i]) {
          pd = 0;
          break;
        }
      } else {
        if (i < p[i]) {
          pd = 0;
          break;
        }
      }
    }
    if (pd == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
