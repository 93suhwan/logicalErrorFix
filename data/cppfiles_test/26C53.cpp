#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int res[200005];
long long fac[200005];
int mul(int a, int b) {
  int res = 0;
  while (b) {
    if (b & 1) {
      res = (res + a) % mod;
    }
    a = (a + a) % mod;
    b /= 2;
  }
  return res;
}
int main() {
  fac[1] = 1;
  fac[2] = 1;
  for (int i = 3; i <= 200005; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%lld\n", fac[2 * n]);
  }
}
