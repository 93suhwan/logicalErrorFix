#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c, res = 0;
    scanf("%d%d%d", &a, &b, &c);
    if (c & 1) res += 3;
    if (b && res) {
      b--;
      res -= 2;
    }
    if (b & 1) res = abs(res - 2);
    res -= a;
    if (res < 0) res = res & 1;
    printf("%d\n", res);
  }
  return 0;
}
