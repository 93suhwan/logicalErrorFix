#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, x0, y0, x, y;
    int s1 = 0, s2 = 0;
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &x0, &y0);
    if (x > x0) {
      s1 = n - x + n - x0;
    } else {
      s1 = x0 - x;
    }
    if (y > y0) {
      s2 = m - y + m - y0;
    } else {
      s2 = y0 - y;
    }
    printf("%d\n", min(s1, s2));
  }
  return 0;
}
