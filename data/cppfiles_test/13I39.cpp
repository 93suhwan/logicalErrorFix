#include <bits/stdc++.h>
int main() {
  int t, b, c;
  char x;
  scanf("%d", &t);
  while (t--) {
    b = 0;
    c = 1;
    while (c) {
      scanf("%c", &x);
      switch (x) {
        case 'A':
        case 'C':
          b--;
          break;
        case 'B':
          b++;
          break;
        case '\n':
          c = 0;
      }
    }
    if (b)
      puts("NO");
    else
      puts("YES");
  }
}
