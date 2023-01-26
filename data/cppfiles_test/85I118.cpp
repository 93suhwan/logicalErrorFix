#include <bits/stdc++.h>
char a[100005];
int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while (t--) {
    int flag0 = 0, flag1 = 0, flag2 = 0, cnt = 0;
    gets(a);
    for (int i = 0; i < strlen(a); i++) {
      if (a[i] == '1') flag1 = 1;
      if (a[i] == '0') flag0 = 1;
      if (a[i] == '2') flag2 = 1;
      if (a[i] == '0') {
        cnt++;
        while (i < strlen(a) && a[i] != '0') i++;
      }
    }
    if (!flag0)
      printf("0\n");
    else if (flag1 == 0 && flag2 == 0)
      printf("1\n");
    else if (cnt >= 2)
      printf("2\n");
    else
      printf("1\n");
  }
  return 0;
}
