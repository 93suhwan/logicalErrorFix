#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long s, n, k;
    scanf("%lld%lld%lld", &s, &n, &k);
    if (k > s) {
      printf("NO\n");
      continue;
    }
    if (s / n > k) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
  }
}
