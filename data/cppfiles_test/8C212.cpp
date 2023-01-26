#include <bits/stdc++.h>
int main() {
  long t, n;
  scanf("%ld", &t);
  for (long i = 0; i < t; i++) {
    scanf("%ld", &n);
    if (n % 3 == 0)
      printf("%ld %ld\n", n / 3, (n / 3));
    else if (n % 3 == 2)
      printf("%ld %ld\n", n / 3, (n / 3) + 1);
    else
      printf("%ld %ld\n", n / 3 + 1, n / 3);
  }
}
