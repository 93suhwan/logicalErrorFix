#include <bits/stdc++.h>
using namespace std;
int gys(int x, int y) {
  if (!y)
    return x;
  else
    return gys(y, x % y);
}
int main() {
  int t, k;
  int a, b, c = 1;
  cin >> t;
  while (t--) {
    cin >> k;
    k--;
    for (b = 2; 2 * b < k; ++b) {
      if (gys(k - b, b) == 1) break;
    }
    a = k - b;
    printf("%d %d %d\n", a, b, c);
  }
  return 0;
}
