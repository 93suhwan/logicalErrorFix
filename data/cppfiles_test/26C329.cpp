#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 1000000007;
int main() {
  int n, m, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long ans = 1;
    for (int i = 3; i <= n * 2; i++) {
      ans = ans * i % mod;
    }
    printf("%lld\n", ans);
  }
}
