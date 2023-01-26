#include <bits/stdc++.h>
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    puts((a + 2 * b + 3 * c) & 1 ? "1" : "0");
  }
  return 0;
}
