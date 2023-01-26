#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, k;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    int c1 = n / m, c2 = (n + m - 1) / m;
    int num = n - c1 * m;
    if (!num) num = m;
    int st = 1;
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= num; j++) {
        printf("%d ", c2);
        for (int k = 0; k < c2; k++)
          printf("%d ", st), st = (st - 1 + 1) % n + 1;
        puts("");
      }
      int st1 = st;
      for (int j = 1; j <= m - num; j++) {
        printf("%d ", c1);
        for (int k = 0; k < c1; k++)
          printf("%d ", st1), st1 = (st1 - 1 + 1) % n + 1;
        puts("");
      }
    }
    puts("");
  }
  return 0;
}
