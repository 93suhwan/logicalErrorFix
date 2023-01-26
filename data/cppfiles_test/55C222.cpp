#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const double pi = acos(-1.0);
const double eps = 1e-9;
long long Pow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
int main() {
  int k;
  while (~scanf("%d", &k)) {
    long long two = 1;
    for (int i = 1; i <= k; i++) {
      two *= 2;
    }
    long long ans = Pow(4, two - 1 - 1) * 6 % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
