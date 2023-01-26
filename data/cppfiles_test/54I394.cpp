#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int i, j, k, n, m, x, y, t;
int mi(int x, int y) {
  if (y == 0) return 1;
  int t = mi(x, y >> 1);
  ;
  t = (long long)t * t % mod;
  if (y & 1) t = (long long)t * x % mod;
  return t;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    int ans = 0;
    x = 1;
    for (i = 0; i <= n; i += 2) {
      ans = (ans + x) % mod;
      x = (long long)x * (n - i) % mod * (n - i - 1) % mod *
          mi(i + 1, mod - 2) % mod * mi(i + 2, mod - 2) % mod;
    }
    if (n & 1) ans++;
    printf("%d\n", mi(ans, m));
  }
  return 0;
}
