#include <bits/stdc++.h>
int main() {
  char str[50];
  int t, l, A = 0, B = 0, C = 0, i;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", str);
    l = strlen(str);
    if (l % 2 != 0) printf("NO\n");
    if (l % 2 == 0) {
      for (i = 0; i < l; i++) {
        if (str[i] == 'A') A++;
        if (str[i] == 'B') B++;
        if (str[i] == 'C') C++;
      }
      if (A == B && C == 0)
        printf("YES\n");
      else if (B > A && B - A == C)
        printf("YES\n");
      else
        printf("NO\n");
    }
    A = 0;
    B = 0;
    C = 0;
  }
}
