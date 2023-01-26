#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    long long suma = 0, sumb = 0;
    for (int i = 1, x; i <= n; i++) {
      scanf("%d", &x);
      if (x == 0) suma++;
      if (x == 1) sumb++;
    }
    printf("%lld\n", sumb * (1LL << suma));
  }
  return 0;
}
