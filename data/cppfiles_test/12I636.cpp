#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int z = (n * m) / 2;
    if (n == 1) {
      if (k == z) {
        printf("YES\n");
      } else
        printf("NO\n");
    } else if (m == 1) {
      if (k == 0) {
        printf("YES\n");
      } else
        printf("NO\n");
    } else {
      if (k == 0) {
        if (n % 2 == 0) {
          printf("YES\n");
        } else
          printf("NO\n");
      } else {
        if (n % 2 == 0 && m % 2 == 0) {
          if (k % 2 == 0)
            printf("YES\n");
          else
            printf("NO\n");
        } else if (n % 2 != 0 && m % 2 == 0) {
          if (m == 2) {
            if (k % 2 != 0) {
              printf("YES\n");
            } else
              printf("NO\n");
          } else if (k % 2 != 0 && k >= m / 2 && k <= z - 2) {
            printf("YES\n");
          } else
            printf("NO\n");
        } else if (n % 2 == 0 && m % 2 != 0) {
          if (k % 2 != 0 && k <= z - n / 2) {
            printf("NO\n");
          } else
            printf("YES\n");
        }
      }
    }
  }
}
