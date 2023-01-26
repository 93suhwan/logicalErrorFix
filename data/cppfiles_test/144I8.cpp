#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (n % m == 0) {
      for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
          printf("%d ", j);
          if (j % (n / m) == 0) printf("\n");
        }
      }
    } else {
      int rem = (n % m) * ((n + m - 1) / m);
      int peo = n / m + 1;
      int now = 0;
      while (k--) {
        if ((now + rem - 1) < n) {
          int sum = 0;
          for (int i = now; i <= now + rem - 1; i++) {
            printf("%d ", i + 1);
            sum++;
            if (sum % peo == 0) printf("\n");
          }
          sum = 0;
          for (int i = now + rem; i < n; i++) {
            printf("%d ", i + 1);
            sum++;
            if (sum % (peo - 1) == 0) printf("\n");
          }
          for (int i = 0; i < now; i++) {
            printf("%d ", i + 1);
            sum++;
            if (sum % (peo - 1) == 0) printf("\n");
          }
        } else {
          int sum = 0;
          for (int i = now; i < n; i++) {
            printf("%d ", i + 1);
            sum++;
            if (sum % peo == 0) printf("\n");
          }
          for (int i = 0; i <= (now + rem - 1) % n; i++) {
            printf("%d ", i + 1);
            sum++;
            if (sum % (peo - 1) == 0) printf("\n");
          }
          sum = 0;
          for (int i = (now + rem) % n; i < now; i++) {
            printf("%d ", i + 1);
            sum++;
            if (sum % (peo - 1) == 0) printf("\n");
          }
        }
        now = (now + rem) % n;
      }
    }
  }
}
