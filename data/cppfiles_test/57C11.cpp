#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  long long s, n, k;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    if (s == k)
      printf("YES\n");
    else if (s < k)
      printf("NO\n");
    else
      printf("%s\n", n / k * k > s - n ? "YES" : "NO");
  }
}
