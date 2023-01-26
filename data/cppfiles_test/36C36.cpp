#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    int n;
    scanf("%d", &n);
    if (n == 1)
      putchar('l');
    else if (n & 1) {
      for (int i = 1; i <= n / 2 - 1; ++i) putchar('l');
      putchar('j'), putchar('s');
      for (int i = 1; i <= n / 2; ++i) putchar('l');
    } else {
      for (int i = 1; i <= n / 2 - 1; ++i) putchar('l');
      putchar('j');
      for (int i = 1; i <= n / 2; ++i) putchar('l');
    }
    puts("");
  }
  return 0;
}
