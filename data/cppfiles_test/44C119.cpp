#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%lld", &n);
  while (n--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if ((a + b) % 2 != 0) {
      printf("-1\n");
    } else {
      if (a == 0 && b == 0) {
        printf("0\n");
        continue;
      }
      if (a == b && a != 0 && b != 0) {
        printf("1\n");
        continue;
      } else {
        printf("2\n");
        continue;
      }
    }
  }
  return 0;
}
