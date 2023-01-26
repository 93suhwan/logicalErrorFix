#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int x = 1; x <= t; x++) {
    char s[50];
    scanf("%s", s);
    int ct = 0;
    for (int y = 0; y < strlen(s) - 1; y++) {
      int c = 0;
      for (int z = y + 1; z < strlen(s); z++) {
        if (s[y] == s[z] && s[y] != ' ') {
          s[z] = ' ';
          c++;
        }
      }
      if (c > 0) {
        s[y] = ' ';
        ct++;
      }
    }
    int c1 = 0;
    for (int y = 0; y < strlen(s); y++) {
      if (s[y] != ' ') c1++;
    }
    ct += c1 / 2;
    printf("%d\n", ct);
  }
  return 0;
}
