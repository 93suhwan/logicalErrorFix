#include <bits/stdc++.h>
using namespace std;
int n, sumx, sumy;
double p, ansx, ansy, retx, rety, ret, p1, p2, p3;
int main() {
  scanf("%d%lf", &n, &p);
  if (p == 0) {
    printf("%d\n", 0);
    return 0;
  }
  sumy = n * (n - 1) * (n - 2) / 6;
  ansy = sumy * 1.0;
  for (int i = 1; i <= n; ++i) {
    if (i == (n - 1)) {
      printf("%d\n", n - 1);
      return 0;
    }
    if (i == 1)
      p3 = 0;
    else
      p3 = i * (i - 1) * (i - 2) / 6;
    p2 = i * (i - 1) / 2 * (n - i);
    p1 = i * (n - i) * (n - i - 1) / 2;
    rety = ansy;
    retx = p3 + p2 + (p1 / 2.0);
    ret = retx / rety;
    if (ret >= p) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}
