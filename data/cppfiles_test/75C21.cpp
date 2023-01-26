#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int i, l, r, n, pl, pr, t = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (l = 1; l < n && a[l] < a[l + 1]; ++l)
    ;
  for (r = n; r > 1 && a[r] < a[r - 1]; --r)
    ;
  pl = 1;
  pr = n;
  while (pl <= l && r <= pr) {
    if (pl == pr) {
      puts(n & 1 ? "Alice" : "Bob");
      return 0;
    }
    if (a[pl] < a[pr]) {
      if ((pr - r) & 1)
        ++pl;
      else {
        puts(!t ? "Alice" : "Bob");
        return 0;
      }
    } else if (a[pl] > a[pr]) {
      if ((l - pl) & 1)
        --pr;
      else {
        puts(!t ? "Alice" : "Bob");
        return 0;
      }
    } else {
      if (((l - pl) & 1) && ((pr - r) & 1)) {
        puts(!t ? "Bob" : "Alice");
        return 0;
      } else {
        puts(!t ? "Alice" : "Bob");
        return 0;
      }
    }
    t ^= 1;
  }
  puts((pl + n - pr + 1) & 1 ? "Alice" : "Bob");
  return 0;
}
