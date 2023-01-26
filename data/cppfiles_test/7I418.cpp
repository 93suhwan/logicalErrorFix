#include <bits/stdc++.h>
using namespace std;
long long x[200010];
long long cha[200010];
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &x[i]);
      if (i > 1) cha[i - 1] = max(x[i] - x[i - 1], x[i - 1] - x[i]);
    }
    long long k = cha[1], fl = 1, mx = 1, tot = 2;
    for (int i = 1; i < n; i++) {
      if (i == 1 && cha[i] != 1) {
        mx = 2;
        continue;
      }
      k = gcd(k, cha[i]);
      if (k == 1) {
        k = cha[i];
        tot = 2;
        fl = i;
        for (int j = i - 1; j >= fl; j--) {
          if (gcd(k, cha[j]) != 1)
            k = gcd(k, cha[j]), tot++, fl = j;
          else
            break;
        }
      } else {
        tot++;
        mx = max(mx, tot);
      }
    }
    printf("%d\n", mx);
  }
  return 0;
}
