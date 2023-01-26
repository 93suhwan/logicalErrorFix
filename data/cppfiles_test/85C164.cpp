#include <bits/stdc++.h>
using namespace std;
int n, t;
char s[121212];
int main() {
  scanf("%d", &t);
  while (t--) {
    int zero = 0, div = 0;
    scanf("%s", s);
    getchar();
    int len = strlen(s);
    for (int i = 0; i < len; i++)
      if (s[i] == '0') {
        if (div)
          continue;
        else {
          div = 1;
          zero++;
        }
      } else
        div = 0;
    if (zero >= 2)
      printf("2");
    else if (zero == 0)
      printf("0");
    else
      printf("1");
    putchar('\n');
  }
  return 0;
}
