#include <bits/stdc++.h>
const int N = 120;
int n;
char s[N];
int a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '?') a[i] = -1;
      if (s[i] == 'R') a[i] = 1, flag = true;
      if (s[i] == 'B') a[i] = 0, flag = true;
    }
    if (flag == false) a[1] = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] < 0) continue;
      int j = i;
      while (j > 1 && a[j - 1] < 0) a[j - 1] = 1 - a[j], j--;
      j = i;
      while (j < n && a[j + 1] < 0) a[j + 1] = 1 - a[j], j++;
    }
    for (int i = 1; i <= n; i++)
      if (a[i] == 1)
        printf("R");
      else
        printf("B");
    printf("\n");
  }
}
