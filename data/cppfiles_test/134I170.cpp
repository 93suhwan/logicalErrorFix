#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    char buf[1000], ans[1000], c;
    scanf("%d%c", &n, &c);
    fgets(buf, 1000, stdin);
    strncpy(ans, buf, 2);
    int i = 1;
    char *a = ans + 1, *b = buf + 3;
    for (; i < n - 1; i++, a++, b += 3) {
      if (*(b - 2) == *b)
        strncpy(a, b, 2);
      else
        strncpy(++a, b, 2);
    }
    *a = '\0';
    if (strlen(ans) < n) {
      ans[n - 1] = *(b - 5);
      ans[n] = '\0';
    }
    puts(ans);
  }
  return 0;
}
