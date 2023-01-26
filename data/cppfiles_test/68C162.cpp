#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  long long n, a;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    a = (long long)pow(n, 0.5);
    n = n - a * a;
    if (n == 0)
      printf("%lld 1\n", a);
    else if (n <= a + 1)
      printf("%lld %lld\n", n, a + 1);
    else
      printf("%lld %lld\n", a + 1, 2 * a - n + 2);
  }
}
