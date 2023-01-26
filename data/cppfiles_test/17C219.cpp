#include <bits/stdc++.h>
using namespace std;
const int maxn = 55000;
int a[maxn][6];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 5; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
      int k = 0;
      for (int j = 1; j <= 5; j++) {
        if (a[ans][j] < a[i][j]) k++;
      }
      if (k < 3) ans = i;
    }
    int f = 0;
    for (int i = 1; i <= n; i++) {
      if (i == ans) continue;
      int k = 0;
      for (int j = 1; j <= 5; j++) {
        if (a[ans][j] < a[i][j]) k++;
      }
      if (k < 3) {
        printf("-1\n");
        f = 1;
        break;
      }
    }
    if (f == 0) printf("%d\n", ans);
  }
  return 0;
}
