#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int n, m, k;
int d;
int a[300005];
int t;
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    long long ans = 1LL;
    for (int i = 1; i < 2 * n; ++i) {
      ans = ans * (long long)i % mod;
    }
    ans = ans * (long long)n % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
