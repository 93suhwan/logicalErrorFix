#include <bits/stdc++.h>
long long a[10100];
int main() {
  int t;
  int n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    a[0] = 2;
    int j = 0;
    for (int i = 1; j < n; i++) {
      if (i > a[j] && i % a[j] != 0) {
        a[j + 1] = i;
        j++;
      }
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
  }
  return 0;
}
