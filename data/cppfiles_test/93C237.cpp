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
    for (int i = a - 1; i > a - x - 1; --i) {
      now = now ^ i;
    }
    if (now == b)
      printf("%d", ans);
    else if ((now ^ b) != a)
      printf("%d", ans + 1);
    else
      printf("%d", ans + 2);
    puts("");
  }
  return 0;
}
