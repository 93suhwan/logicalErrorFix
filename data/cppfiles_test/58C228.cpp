#include <bits/stdc++.h>
int main() {
  int i, j, n, t, count;
  char a[2][105];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    count = 0;
    scanf("%s%s", &a[0], &a[1]);
    for (j = 0; j < n; j++) {
      if (a[0][j] == '1' && a[1][j] == '1') {
        count++;
      }
    }
    if (count == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
