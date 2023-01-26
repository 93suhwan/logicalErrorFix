#include <bits/stdc++.h>
int main(void) {
  int i, t, flag = 0;
  char ch;
  scanf("%d", &t);
  scanf("%c", &ch);
  for (i = 0; i < t; i++) {
    int a = 0, b = 0, c = 0;
    scanf("%c", &ch);
    while (ch != ' ' && ch != '\n') {
      if (ch == 'A')
        a++;
      else if (ch == 'B')
        b++;
      else
        c++;
      scanf("%c", &ch);
    }
    if (b == (a + c))
      printf("yes\n");
    else
      printf("no\n");
  }
}
