#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    char a[60] = {};
    scanf("%s", a);
    int f = -1;
    for (int i = 0; i < n; i++)
      if (a[i] != '2' && a[i] != '3' && a[i] != '5' && a[i] != '7') {
        f = i;
        break;
      }
    if (f != -1)
      printf("1\n%c\n", a[f]);
    else {
      if (n <= 2) {
        printf("%d\n%s\n", n, a);
      } else {
        printf("2\n");
        if (a[0] == '2') {
          int i = 1;
          for (; i < n; i++) {
            if (a[i] == '2' || a[i] == '5' || a[i] == '7') break;
          }
          printf("%c%c\n", a[0], a[i]);
        } else if (a[0] == '3') {
          int i = 1;
          for (; i < n; i++) {
            if (a[i] == '2' || a[i] == '5' || a[i] == '3') break;
          }
          printf("%c%c\n", a[0], a[i]);
        } else if (a[0] == '5') {
          int i = 1;
          for (; i < n; i++) {
            if (a[i] == '2' || a[i] == '5' || a[i] == '7') break;
          }
          printf("%c%c\n", a[0], a[i]);
        } else if (a[0] == '7') {
          int i = 1;
          for (; i < n; i++) {
            if (a[i] == '2' || a[i] == '5' || a[i] == '7') break;
          }
          printf("%c%c\n", a[0], a[i]);
        }
      }
    }
  }
  return 0;
}
