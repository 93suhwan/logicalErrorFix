#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t, a, b, c;
  long long n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    a = (int)pow(n, 0.5);
    n = n - a * a;
    if (n == 0)
      printf("%d 1\n", a);
    else if (n <= a + 1)
      printf("%d %d\n", n, a + 1);
    else
      printf("%d %d\n", a + 1, 2 * a - n + 2);
  }
}
