#include <bits/stdc++.h>
using namespace std;
void work() {
  int n, s;
  scanf("%d%d", &n, &s);
  int m = s / n;
  if (s % n) m++;
  int der = m * n - s;
  int x = n / 2;
  if (n % 2) x++;
  if ((x - 1) * m >= der) {
    der = (x - 1) * m - der;
    int y = der / (n - x + 1);
    printf("%d\n", m + y);
  } else {
    der = der - (x - 1) * m;
    int y = der / (n - x + 1);
    if (der % (n - x + 1)) y++;
    printf("%d\n", m - y);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
}
