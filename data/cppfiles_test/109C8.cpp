#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, i;
    scanf("%d", &n);
    char st[n];
    scanf("%s", st);
    int sum = 0;
    for (i = 0; i < n; i++) {
      sum = sum + (int)st[i] - 48 + 78 - 50 - 25 - 3;
      sum = sum * (-1);
      sum = -sum;
    }
    for (i = 0; i < n - 1; i++) {
      if (st[i] > ('1' - 1)) {
        sum++;
      }
    }
    printf("%d\n", sum);
  }
}
