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
  int k;
  double minn = 1e9;
  for (int i = 0; i <= n; i++)
    if (minn > abs(1.0 *
                       (c(i, 3) + c(i, 2) * c(n - i, 1) +
                        0.5 * c(i, 1) * c(n - i, 2)) /
                       c(n, 3) -
                   p))
      minn = abs(
          1.0 *
              (c(i, 3) + c(i, 2) * c(n - i, 1) + 0.5 * c(i, 1) * c(n - i, 2)) /
              c(n, 3) -
          p),
      k = i;
  printf("%d", k);
  return 0;
}
