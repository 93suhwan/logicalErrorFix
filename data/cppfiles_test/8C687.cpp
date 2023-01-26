#include <bits/stdc++.h>
int n;
int a, b;
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    a = b = n / 3;
    if (n % 3 == 1) ++a;
    if (n % 3 == 2) ++b;
    printf("%d %d\n", a, b);
  }
  return 0;
}
