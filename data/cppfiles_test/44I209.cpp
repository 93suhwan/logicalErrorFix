#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%lld", &n);
  while (n--) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    if ((a + b) % 2 != 0) {
      printf("-1\n");
    } else {
      if (a == 0 && b == 0) {
        printf("0\n");
      } else if (a == b) {
        printf("1\n");
      } else {
        long long x = (abs(a - b) / 2) + 1;
        printf("2\n");
      }
    }
  }
  return 0;
}
