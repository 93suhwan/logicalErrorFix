#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 5;
constexpr int MOD = 1e9 + 7;
int T;
int main() {
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    ll d = 1;
    ll ret = 0;
    while (k) {
      if (k & 1) {
        ret = (ret + d) % MOD;
      }
      d = d * n % MOD;
      k >>= 1;
    }
    printf("%lld\n", ret);
  }
}
