#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long w[1005];
signed main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &w[i]);
      sum += w[i];
    }
    if (sum % n == 0) {
      puts("0");
    } else
      puts("1");
  }
}
