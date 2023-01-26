#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, k;
  bool flag = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0)
        flag = 1;
      else
        flag = 0;
    } else if (n % 2 == 1 && m % 2 == 0) {
      if (k >= m / 2 && (k - m / 2) % 2 == 0)
        flag = 1;
      else
        flag = 0;
    } else if (n % 2 == 0 && m % 2 == 1) {
      if (((n * m / 2) - k >= (n / 2)) &&
          (((n * m / 2) - k - (n / 2)) % 2 == 0))
        flag = 1;
      else
        flag = 0;
    } else {
      if (((n * m / 2) - k) % 2 == 0)
        flag = 1;
      else
        flag = 0;
    }
    if (flag == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
