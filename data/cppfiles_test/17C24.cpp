#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
int a[M][10];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 5; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int ma = 1;
    for (int i = 2; i <= n; i++) {
      int tmp = 0;
      for (int j = 1; j <= 5; j++) {
        if (a[i][j] < a[ma][j]) tmp++;
      }
      if (tmp >= 3) ma = i;
    }
    for (int i = 1; i <= n; i++) {
      if (i == ma) continue;
      int tmp = 0;
      for (int j = 1; j <= 5; j++) {
        if (a[i][j] < a[ma][j]) tmp++;
      }
      if (tmp >= 3) {
        ma = -1;
        break;
      }
    }
    printf("%d\n", ma);
  }
  return 0;
}
