#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, i, m;
  t = a = b = c = i = m = 0;
  cin >> t;
  if (t <= 10000) {
    for (i = 1; i <= t; i++) {
      cin >> a >> b >> c;
      m = max(max(a, b), c);
      if (a + b == m || b + c == m || c + a == m ||
          ((a == b || b == c || c == a) && m % 2 == 0))
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  return 0;
}
