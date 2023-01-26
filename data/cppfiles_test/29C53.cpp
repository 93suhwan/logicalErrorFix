#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    int zero = 0, one = 0;
    for (int i = 1, x; i <= n; i++) {
      scanf("%d", &x);
      if (!x) zero++;
      if (x == 1) one++;
    }
    printf("%lld\n", (1ll << zero) * one);
  }
}
