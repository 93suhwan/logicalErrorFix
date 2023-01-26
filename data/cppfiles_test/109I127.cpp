#include <bits/stdc++.h>
int main() {
  int i, j, n, t, mov = 0, d = 0;
  char a[100];
  scanf("%d", &t);
  while (t > 0) {
    scanf("%d", &n);
    scanf("%s", a);
    for (i = 0; i < n - 1; i++) {
      if (a[i] != '0') {
        mov = mov + a[i] - '0' + 1;
      }
    }
    if (a[n - 1] != 0) {
      mov = mov + a[i] - '0';
    }
    printf("%d\n", mov);
    t--;
  }
  return 0;
}
