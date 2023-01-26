#include <bits/stdc++.h>
int main() {
  int nums;
  scanf("%d", &nums);
  while (nums--) {
    unsigned long long int n;
    scanf("%I64d", &n);
    if (n == 1) {
      printf("0 1\n");
    } else {
      printf("%I64d %I64d\n", -(n - 1), n);
    }
  }
  return 0;
}
