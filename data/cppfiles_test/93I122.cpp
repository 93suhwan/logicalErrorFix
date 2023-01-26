#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, now;
    scanf("%d%d", &a, &b);
    int ans = 0;
    ans += a;
    if (a == b) ans++;
    if (a <= 4) {
      if (a == 4) now = 0;
      if (a == 3) now = 3;
      if (a == 2) now = 1;
      if (a == 1) now = 0;
    } else {
      now = 0;
      int x = a - 4;
      x = x % 4;
      if (x != 0) {
        for (int i = a - 1; i >= a - x; --i) {
          now = i ^ now;
        }
      }
    }
    if (now == b)
      printf("%d\n", ans);
    else
      printf("%d\n", ans + 1);
  }
  return 0;
}
