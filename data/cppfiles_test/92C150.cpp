#include <bits/stdc++.h>
using namespace std;
int t;
char s[110];
int main() {
  scanf("%d", &t);
  getchar();
  while (t--) {
    scanf("%s", s);
    int ab = 0, ba = 0;
    for (int i = 0; i < strlen(s) - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') ab++;
      if (s[i] == 'b' && s[i + 1] == 'a') ba++;
    }
    if (ab > ba) {
      for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'b') {
          s[i] = 'a';
          break;
        }
      }
    } else if (ab < ba) {
      for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'a') {
          s[i] = 'b';
          break;
        }
      }
    }
    printf("%s\n", s);
  }
  return 0;
}
