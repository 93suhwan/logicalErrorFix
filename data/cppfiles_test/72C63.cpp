#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 1e9;
  auto ask = [&](int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int t;
    scanf("%d", &t);
    return t;
  };
  int res = ask(n, 1);
  auto ok = [&](int y) {
    int res2 = ask(n, y);
    return res - res2 == y - 1;
  };
  int l = 2, r = n - 1;
  int t1 = l;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid))
      t1 = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  int s2 = n - ask(n, t1);
  int s1 = ask(1, 1) - t1 + 2;
  int t2 = n - (ask(n, n) - (n - s2));
  printf("! %d %d %d %d\n", s1, t1, s2, t2);
  fflush(stdout);
  return 0;
}
