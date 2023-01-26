#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  long long s, n, k;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    if (s - n / k * k - n >= 0) {
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
