#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t > 0) {
    --t;
    int n, ans = 0;
    scanf("%d", &n);
    char a[2][n + 2];
    scanf("%s %s", &a[1], &a[0]);
    a[1][n] = -1;
    for (int i = 0; i < n; ++i) {
      if (a[0][i] == '1') {
        if (a[1][i] == '0')
          ans++, a[1][i] = '3';
        else if (a[1][i - 1] == '1' && i - 1 >= 0)
          ans++, a[1][i - 1] = '3';
        else if (a[1][i + 1] == '1')
          ans++, a[1][i + 1] = '3';
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
