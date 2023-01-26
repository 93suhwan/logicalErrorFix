#include <bits/stdc++.h>
int main() {
  int t;
  int n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      printf("%d ", i + 2);
    }
    printf("\n");
  }
  return 0;
}
