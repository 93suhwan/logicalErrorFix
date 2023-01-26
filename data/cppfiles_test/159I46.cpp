#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n == 1) {
    printf("1\n1\n");
    return 0;
  }
  if (n & 1) n--;
  if (n % 2 == 0) {
    int k = n / 2;
    if (k % 2 == 0) {
      printf("%d\n", n - 1);
      for (int i = 1; i <= n; i++) {
        if (i == k) continue;
        printf("%d ", i);
      }
      printf("\n");
    } else {
      printf("%d\n", n - 2);
      for (int i = 1; i <= n; i++) {
        if (i == 2 || i == k) continue;
        printf("%d ", i);
      }
      printf("\n");
    }
  }
  return 0;
}
