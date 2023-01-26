#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int z = (n * m) / 2;
    if (n % 2 == 0) {
      if (k % 2 != 0) {
        printf("NO\n");
      } else {
        int x = k / n;
        x += (k % n != 0);
        x = x * 2;
        if (x > m)
          printf("NO\n");
        else
          printf("YES\n");
      }
    } else {
      int x = m / 2;
      k = k - x;
      if (k < 0) {
        printf("NO\n");
      } else {
        if (k % 2 == 0)
          printf("YES\n");
        else
          printf("NO\n");
      }
    }
  }
}
