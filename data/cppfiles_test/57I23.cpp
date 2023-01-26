#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  long long n, s, k;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    if (s >= (n / k * 2 * k + n % k)) {
      printf("NO\n");
    } else {
      if (n >= k) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}
