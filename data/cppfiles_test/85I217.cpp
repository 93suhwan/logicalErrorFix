#include <bits/stdc++.h>
int f(int a, int b, int c) {
  if (a && b)
    return 2;
  else if (a && c)
    return 1;
  else if (b && c)
    return 0;
}
int f1(int a, int b) {
  if (a && !b) {
    if (a - '0')
      return 0;
    else
      return 1;
  }
  if (a && b) {
    if (!(a - '0') || !(b - '0'))
      return 1;
    else
      return 0;
  }
}
int main() {
  int t, i = 1;
  scanf("%d", &t);
  getchar();
  while (t--) {
    char ch;
    int s1 = 0, s2 = 0;
    int flag = 0, flagg = 0, flag0 = 0, flag1 = 0, flag2 = 0;
    int end = 0;
    while ((ch = getchar()) != '\n') {
      if (ch == '0') flag0 = 1;
      if (ch == '1') flag1 = 1;
      if (ch == '2') flag2 = 1;
      if (!flag) {
        flag = ch;
        continue;
        s1++;
      }
      if (ch != flag && !flagg)
        flagg = ch;
      else
        s1++;
      if (ch != flagg) {
        end = 1;
        s2++;
      }
    }
    if (s1 == s2) end = 0;
    if (end == 1)
      printf("%d\n", f(flag0, flag1, flag2));
    else
      printf("%d\n", f1(flag, flagg));
  }
  return 0;
}
