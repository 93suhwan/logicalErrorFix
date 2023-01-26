#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    c &= 1, b &= 1;
    int s = a + b * 2 + c * 3;
    if (a >= abs(c * 3 - b * 2))
      printf("%d\n", s & 1);
    else if (c)
      printf("%d\n", abs(3 - b * 2 - a));
    else
      printf("%d\n", abs(b * 2 - a));
  }
  return 0;
}
