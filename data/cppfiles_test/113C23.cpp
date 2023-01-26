#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x1, p1;
    int x2, p2;
    scanf("%d%d", &x1, &p1);
    scanf("%d%d", &x2, &p2);
    int t = min(p1, p2);
    p1 -= t, p2 -= t;
    if (p1 > 10)
      puts(">");
    else if (p2 > 10)
      puts("<");
    else {
      long long y1 = x1, y2 = x2;
      while (p1--) y1 *= 10;
      while (p2--) y2 *= 10;
      if (y1 < y2)
        puts("<");
      else if (y1 > y2)
        puts(">");
      else
        puts("=");
    }
  }
  return 0;
}
