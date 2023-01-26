#include <bits/stdc++.h>
int main() {
  int test;
  scanf("%d", &test);
  while (test > 0) {
    int n;
    long long sum = 0;
    scanf("%d", &n);
    long a[n];
    for (int i = 0; i < n; i++) {
      scanf("%ld", &a[i]);
      sum += a[i];
    }
    if (sum % n == 0)
      printf("0\n");
    else
      printf("1\n");
    test--;
  }
}
