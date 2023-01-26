#include <bits/stdc++.h>
using namespace std;
int n;
int num[1000000 + 5];
int a[15];
int main() {
  int i, j, u, T;
  scanf("%d", &T);
  while (T--) {
    memset(num, 0, sizeof(num));
    num[0] = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] < 0) {
        a[i] = -a[i];
      }
      for (j = 1000000 - a[i]; j >= 0; j--) {
        if (num[j] > 0) {
          num[j + a[i]]++;
        }
      }
    }
    for (i = 0; i <= 1000000; i++) {
      if (num[i] >= 2) {
        printf("YES\n");
        break;
      }
    }
    if (i > 1000000) {
      printf("NO\n");
    }
  }
  return 0;
}
