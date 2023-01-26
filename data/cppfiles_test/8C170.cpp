#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
using namespace std;
const int N = 1e5 + 5, M = 3e3 + 5, MOD = 1e9 + 7;
int TC;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  scanf("%d", &TC);
  while (TC--) {
    long long n = 0, ans1 = 0, ans2 = 0;
    scanf("%lld", &n);
    ans1 = n / 3;
    ans2 = n / 3;
    for (int i = ans1; ((2ll * ans1 + 4ll * ans2) != 2 * n &&
                        (4ll * ans1 + 2ll * ans2) != 2 * n);
         i++)
      ans2++;
    (ans1 * 2 + ans2 == n) ? printf("%lld %lld\n", ans2, ans1)
                           : printf("%lld %lld\n", ans1, ans2);
  }
  return 0;
}
