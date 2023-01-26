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
    int x = a % 4;
    if (x == 0 && a == b)
      ++ans;
    else if (a == 1 && b == 1) {
      printf("3\n");
      continue;
    }
    for (int i = a - 1; i > a - x - 1; --i) {
      now = now ^ i;
    }
    if (now == b)
      printf("%d\n", ans);
    else
      printf("%d\n", ans + 1);
  }
  return 0;
}
