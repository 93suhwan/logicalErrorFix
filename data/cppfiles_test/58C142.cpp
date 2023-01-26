#include <bits/stdc++.h>
using namespace std;
char a[3][110];
int n;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= 2; i++) scanf("%s", a[i] + 1);
    if (a[1][1] == '1' || a[2][n] == '1')
      printf("NO\n");
    else {
      int flag = 0;
      for (int i = 1; i <= n; i++) {
        if (a[1][i] == '1' && a[2][i] == '1') {
          flag = 1;
          break;
        }
      }
      if (flag == 0)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
