#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, i, m;
  t = a = b = c = i = m = 0;
  cin >> t;
  if (t <= 10000) {
    for (i = 1; i <= t; i++) {
      cin >> a >> b >> c;
      if (a >= 1 && a <= 100000000 && b >= 1 && b <= 100000000 && c >= 1 &&
          c <= 100000000) {
        m = max(max(a, b), c);
        if (a + b == m || b + c == m || c + a == m)
          printf("Yes\n");
        else if ((a == b && c % 2 == 0) ||
                 (b == c && a % 2 == 0) && (c == a && b % 2 == 0))
          printf("Yes\n");
        else
          printf("No\n");
      }
    }
  }
  return 0;
}
