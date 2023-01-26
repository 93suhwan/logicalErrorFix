#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int a[N];
char s[N];
int main() {
  long long _, x, y;
  scanf("%lld", &_);
  while (_--) {
    scanf("%lld%lld", &x, &y);
    if (x > y) {
      printf("%lld\n", x * y + y);
    } else if (x == y) {
      printf("%lld\n", x);
    } else {
      printf("%lld\n", (x + y) / 2ll);
    }
  }
  return 0;
}
