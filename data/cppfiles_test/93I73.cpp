#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, now = 0;
    scanf("%d%d", &a, &b);
    int ans = 0;
    ans += a;
    if (a == 1) {
      if (b == 1)
        printf("3\n");
      else
        printf("2\n");
      continue;
    }
    int x = a % 4;
    if (x == 0) now = 0;
    for (int i = a - 1; i > a - x; --i) {
      now = now ^ i;
    }
    if (now == b)
      printf("%d\n", ans);
    else
      printf("%d\n", ans + 1);
  }
  return 0;
}
