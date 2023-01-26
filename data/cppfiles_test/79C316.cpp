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
        for (int k = 0; k < n - 1; k++) {
          if (a[k] == '2') {
            int i = k + 1;
            for (; i < n; i++) {
              if (a[i] == '2' || a[i] == '5' || a[i] == '7') {
                printf("%c%c\n", a[k], a[i]);
                break;
              }
            }
            if (i < n) break;
          } else if (a[k] == '3') {
            int i = k + 1;
            for (; i < n; i++) {
              if (a[i] == '2' || a[i] == '5' || a[i] == '3') {
                printf("%c%c\n", a[k], a[i]);
                break;
              }
            }
            if (i < n) break;
          } else if (a[k] == '5') {
            int i = k + 1;
            for (; i < n; i++) {
              if (a[i] == '2' || a[i] == '5' || a[i] == '7') {
                printf("%c%c\n", a[k], a[i]);
                break;
              }
            }
            if (i < n) break;
          } else if (a[k] == '7') {
            int i = k + 1;
            for (; i < n; i++) {
              if (a[i] == '2' || a[i] == '5' || a[i] == '7') {
                printf("%c%c\n", a[k], a[i]);
                break;
              }
            }
            if (i < n) break;
          }
        }
      }
    }
  }
  return 0;
}
