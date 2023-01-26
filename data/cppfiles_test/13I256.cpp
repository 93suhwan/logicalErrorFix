#include <bits/stdc++.h>
int main() {
  int t, a = 0, b = 0, c = 0;
  char z[50];
  scanf("%d", &t);
  while (t--) {
    scanf("%s", z);
    for (int i = 0; i < strlen(z); i++) {
      if (z[i] == 'A')
        a += 1;
      else if (z[i] == 'B')
        b += 1;
      else if (z[i] == 'C')
        c += 1;
      if (a + b == c)
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  return 0;
}
