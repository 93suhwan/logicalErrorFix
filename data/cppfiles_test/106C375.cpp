#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  int n;
  int i, j;
  for (i = 0; i < t; i++) {
    scanf("%d", &n);
    long long int a;
    a = 2;
    for (j = 0; j < n; j++) {
      printf("%d ", a);
      a++;
    }
    printf("\n");
  }
  return 0;
}
