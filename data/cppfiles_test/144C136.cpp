#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int rem = (n % m) * ((n + m - 1) / m);
    int peo = (n + m - 1) / m;
    if (n % m == 0) {
      rem = n;
      peo = n / m;
    }
    int now = 0;
    while (k--) {
      int sum = 0;
      int cnt = 0;
      for (int i = now; i < now + rem; i++) {
        if (sum % peo == 0) printf("%d ", peo);
        printf("%d ", i % n + 1);
        cnt++;
        sum++;
        if (cnt % peo == 0) {
          printf("\n");
        }
      }
      sum = 0;
      cnt = 0;
      for (int i = now + rem; i <= now + n - 1; i++) {
        if (sum % (peo - 1) == 0) printf("%d ", peo - 1);
        printf("%d ", i % n + 1);
        cnt++;
        sum++;
        if (cnt % (peo - 1) == 0) printf("\n");
      }
      now = (now + rem) % n;
    }
  }
}
