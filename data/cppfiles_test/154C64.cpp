#include <bits/stdc++.h>
int main() {
  int t, a, b, c;
  scanf("%u", &t);
  for (int i = 1; i < t + 1; i++) {
    scanf("%u", &a);
    scanf("%u", &b);
    scanf("%u", &c);
    if ((a + b + c) % 2 == 0 && a + b + c > 3) {
      if (a == b && c % 2 == 0) {
        printf("YES\n");
      } else if (b == c && a % 2 == 0) {
        printf("YES\n");
      } else if (a == c && b % 2 == 0) {
        printf("YES\n");
      } else if (a + b == c) {
        printf("YES\n");
      } else if (b + c == a) {
        printf("YES\n");
      } else if (a + c == b) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
