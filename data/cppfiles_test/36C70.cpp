#include <bits/stdc++.h>
using namespace std;
int T, n, m, k;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    if (n == 1)
      puts("a");
    else if (n % 2 == 0) {
      for (register int i = (1); i <= (n / 2); ++i) putchar('a');
      putchar('b');
      for (register int i = (1); i <= (n / 2 - 1); ++i) putchar('a');
      putchar('\n');
    } else {
      for (register int i = (1); i <= (n / 2); ++i) putchar('a');
      putchar('b');
      putchar('c');
      for (register int i = (1); i <= (n / 2 - 1); ++i) putchar('a');
      putchar('\n');
    }
  }
  return 0;
}
