#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, c, r;
    scanf("%d", &n);
    int l = ceil(sqrt(n));
    int d = l * l - n;
    int k = d - l;
    if (d < l) {
      r = l;
      c = d + 1;
    }
    if (d >= l) {
      r = l - k - 1;
      c = l;
    }
    printf("%d %d\n", r, c);
  }
  return 0;
}
