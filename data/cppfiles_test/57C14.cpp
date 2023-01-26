#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long s, n, k;
    scanf("%lld%lld%lld", &s, &n, &k);
    if (s < k)
      printf("NO\n");
    else if (s == k)
      printf("YES\n");
    else {
      long long left_sum = s - n;
      long long extra_sum = (n / k) * k;
      if (left_sum < extra_sum)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
