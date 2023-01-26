#include <bits/stdc++.h>
int main() {
  int nums;
  scanf("%d", &nums);
  while (nums--) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
      printf("0 1\n");
    } else {
      printf("%d %d\n", -(n - 1), n);
    }
  }
  return 0;
}
