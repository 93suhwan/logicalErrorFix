#include <bits/stdc++.h>
using namespace std;
int a[1005][10];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 5; j++) scanf("%d", &a[i][j]);
    }
    bool f = false;
    for (int i = 1; i <= 5; i++) {
      if (f) break;
      for (int j = 1; j <= 5; j++) {
        if (i == j) continue;
        int b1 = 0, b2 = 0;
        bool flag = true;
        for (int k = 1; k <= n; k++) {
          if (!a[k][i] && !a[k][j]) {
            flag = false;
            break;
          }
          if (a[k][i] && a[k][j]) continue;
          if (a[k][i])
            b1++;
          else
            b2++;
        }
        if (b1 > n / 2 || b2 > n / 2) flag = false;
        if (flag) {
          f = true;
          break;
        }
      }
    }
    if (f)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
