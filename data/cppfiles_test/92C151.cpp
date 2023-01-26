#include <bits/stdc++.h>
using namespace std;
char s[105];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int ab = 0, ba = 0;
    for (int i = 1; i < n; ++i) {
      if (s[i] == 'a' && s[i + 1] == 'b') ab++;
      if (s[i] == 'b' && s[i + 1] == 'a') ba++;
    }
    if (ab == ba) {
      for (int i = 1; i <= n; ++i) printf("%c", s[i]);
      puts("");
      continue;
    }
    for (int i = 1; i < n; ++i) printf("%c", s[i]);
    if (ab > ba)
      printf("a\n");
    else
      printf("b\n");
  }
  return 0;
}
