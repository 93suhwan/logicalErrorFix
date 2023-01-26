#include <bits/stdc++.h>
int fun(char *t) {
  int i, n = 0;
  for (i = 0; t[i + 1]; i++) {
    if (t[i] + 1 == t[i + 1])
      continue;
    else
      n = 1;
  }
  return n;
}
int main() {
  int t, num;
  char z[50];
  scanf("%d", &t);
  while (t--) {
    scanf("%s", z);
    if (strlen(z) > 2) {
      (fun(z) == 1) ? (printf("Yes\n")) : (printf("No\n"));
    }
  }
  return 0;
}
