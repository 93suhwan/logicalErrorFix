#include <bits/stdc++.h>
using namespace std;
int n;
double p;
int c(int n, int m) {
  if (n < m) return 0;
  if (m == 1) return n;
  if (m == 2) return n * (n - 1) / 2;
  if (m == 3) return n * (n - 1) * (n - 2) / 6;
}
int main() {
  scanf("%d%lf", &n, &p);
  for (int i = 0; i <= n; i++) {
    if (abs(1.0 *
                (c(i, 3) + c(i, 2) * c(n - i, 1) +
                 0.5 * c(i, 1) * c(n - i, 2)) /
                c(n, 3) -
            p) <= 0.001) {
      printf("%d", i);
      return 0;
    }
  }
  return 0;
}
