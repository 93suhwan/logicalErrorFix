#include <bits/stdc++.h>
using namespace std;
int num[300000 + 5];
void init() {
  for (int i = 1; i < 300000 + 5; i++) {
    num[i] = num[i - 1] ^ i;
  }
}
int main() {
  int T, a, b;
  init();
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &a, &b);
    int c = num[a - 1] ^ b;
    if (c) {
      if (c == a) {
        printf("%d\n", a + 2);
      } else {
        printf("%d\n", a + 1);
      }
    } else {
      printf("%d\n", a);
    }
  }
  return 0;
}
