#include <bits/stdc++.h>
using namespace std;
int n, sumx, sumy;
double p, ansx, ansy, retx, rety, ret, p1, p2, p3;
int main() {
  scanf("%d%lf", &n, &p);
  sumy = n * (n - 1) * (n - 2) / 6;
  ansy = sumy * 1.0;
  if (p == 0) {
    puts("0");
    return 0;
  }
  for (int i = n - 1; i; --i) {
    if (i == 1) {
      puts("1");
      return 0;
    }
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
