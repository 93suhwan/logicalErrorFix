#include <bits/stdc++.h>
int main() {
  char s[50], *ptr;
  long int t;
  int l, a = 0, b = 0, c = 0, i;
  scanf("%ld", &t);
  while (t--) {
    scanf("%s", s);
    ptr = s;
    l = strlen(s);
    if (l % 2 != 0) printf("No\n");
    if (l % 2 == 0) {
      for (i = 1; i <= l; i++) {
        if (*ptr == 'A') a++;
        if (*ptr == 'B') b++;
        if (*ptr == 'C') c++;
        ptr++;
      }
      if (b - a > 0 && (b - a) == c) printf("Yes\n");
      if (b - a < 0) printf("No\n");
      if (b - a == 0 && c == 0) printf("Yes\n");
      if (b - a > 0 && b - a < c) printf("No\n");
      if (b - a - c > 0) printf("No\n");
    }
    a = 0;
    b = 0;
    c = 0;
  }
}
