#include <bits/stdc++.h>
int main() {
  int t, n, k, i, p;
  long long int s, l;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d", &n, &k);
    p = 0;
    s = 0;
    l = 1;
    while (k) {
      if (k % 2) s = (s + l) % 1000000007;
      l = (l * n) % 1000000007;
      p++;
      k /= 2;
    }
    printf("%lld\n", s);
  }
  return 0;
}
