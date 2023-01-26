#include <bits/stdc++.h>
long test[10000];
long i, t;
long tinh[200001];
int main() {
  scanf("%ld", &t);
  for (i = 0; i < t; ++i) {
    scanf("%ld", &test[i]);
  }
  tinh[2] = 1;
  for (i = 3; i <= 200000; ++i) {
    tinh[i] *= i;
    tinh[i] %= 1000000007;
  }
  for (i = 0; i < t; ++i) {
    printf("%ld", tinh[test[i] * 2]);
    printf("\n");
  }
}
