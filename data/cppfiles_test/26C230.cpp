#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int n, T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    long long ans = 1;
    for (int i = 3; i <= 2 * n; i++) {
      ans = ans * i % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
