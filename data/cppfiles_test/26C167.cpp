#include <bits/stdc++.h>
long long test[10000];
long i, t;
long long tinh[200001];
int main() {
  scanf("%ld", &t);
  for (i = 0; i < t; ++i) {
    scanf("%lld", &test[i]);
  }
  tinh[2] = 1;
  for (i = 3; i <= 200000; ++i) {
    tinh[i] = (tinh[i - 1] * i) % 1000000007;
  }
  for (i = 0; i < t; ++i) {
    printf("%lld", tinh[test[i] * 2]);
    printf("\n");
  }
}
