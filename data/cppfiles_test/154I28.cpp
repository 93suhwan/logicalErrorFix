#include <bits/stdc++.h>
int main() {
  int t, a, b, c;
  scanf("%u", &t);
  for (int i = 1; i < t + 1; i++) {
    scanf("%u", &a);
    scanf("%u", &b);
    scanf("%u", &c);
    if ((a + b + c) % 2 == 0 && a + b + c > 3) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
