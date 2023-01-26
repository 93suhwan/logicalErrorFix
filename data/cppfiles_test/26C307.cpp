#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
long long f[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 1;
    n *= 2;
    for (int i = 3; i <= n; ++i) ans = ans * i % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
