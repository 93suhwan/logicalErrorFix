#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int res = 0;
    for (int i = 1, x; i <= n; ++i) {
      scanf("%d", &x);
      res = max(res, x - i);
    }
    printf("%d\n", res);
  }
  return 0;
}
