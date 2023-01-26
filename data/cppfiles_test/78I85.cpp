#include <bits/stdc++.h>
using namespace std;
int T, n;
char s[505];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s + 1), n = strlen(s + 1);
    int j = 1;
    for (int i = 2; i <= n; i++)
      if (s[i] < s[j]) j = i;
    putchar(s[j]), putchar(' ');
    for (int i = 1; i <= n; i++)
      if (i != j) putchar(s[i]);
    putchar('\n');
  }
}
