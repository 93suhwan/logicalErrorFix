#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    char info[15];
    scanf("%s", info);
    int len = strlen(info);
    int a = 0, b = 0;
    for (int i = 0; i < len; ++i) {
      if (i % 2) {
        a = a * 10 + info[i] - '0';
      } else {
        b = b * 10 + info[i] - '0';
      }
    }
    printf("%lld\n", (a + 1ll) * (b + 1ll) - 2);
  }
  return 0;
}
