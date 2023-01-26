#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    long int n;
    scanf("%ld", &n);
    printf("%ld\n", (n + 1) / 10);
  }
}
