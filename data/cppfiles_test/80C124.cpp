#include <bits/stdc++.h>
int t, n;
char s[20003];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%s", &n, s + 1);
    bool ok = 0;
    for (int i = 1; i <= n; i++)
      if (s[i] == '0') {
        ok = 1;
        if (i > (n >> 1))
          printf("1 %d 1 %d\n", i, i - 1);
        else
          printf("%d %d %d %d\n", i, n, i + 1, n);
        break;
      }
    if (!ok) printf("1 %d 2 %d\n", n - 1, n);
  }
  return 0;
}
