#include <bits/stdc++.h>
using namespace std;
long long maps[105][105];
int main() {
  long long a, b, c, d, i, j, k, l, t, n, m;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &a);
    for (i = 2; i * i <= a; i++) {
      if (a % i) {
        b = a % i;
        c = a - b;
        break;
      }
    }
    printf("%lld %lld\n", i, c);
  }
}
