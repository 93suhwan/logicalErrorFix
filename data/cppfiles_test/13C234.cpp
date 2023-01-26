#include <bits/stdc++.h>
int main() {
  int t;
  char z[50];
  scanf("%d", &t);
  while (t--) {
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%s", z);
    for (int i = 0; i < strlen(z); i++) {
      if (z[i] == 'A')
        a += 1;
      else if (z[i] == 'B')
        b += 1;
      else if (z[i] == 'C')
        c += 1;
    }
    if (a + c == b)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
