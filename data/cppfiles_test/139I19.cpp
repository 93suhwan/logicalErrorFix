#include <bits/stdc++.h>
int consider(char *s) {
  int len = strlen(s);
  if (len % 2 != 0) return 0;
  int i = 0, j = len / 2;
  while (j < len) {
    if (s[i] != s[j]) return 0;
    i++;
    j++;
  }
  return 1;
}
void solution() {
  int T;
  scanf("%s", &T);
  for (int t = 0; t < T; t++) {
    char s[1000];
    scanf("%s", s);
    if (consider(s))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
int main() {
  solution();
  return 0;
}
