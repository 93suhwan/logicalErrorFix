#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  if (n > m) {
    printf("0\n");
    return;
  }
  m = m + 1;
  long long pow2 = 1;
  while (pow2 <= n) pow2 = pow2 * 2;
  pow2 = pow2 / 2;
  while (pow2 > 0) {
    if ((n & pow2) != 0 && (m & pow2) == 0) {
      pow2 = pow2 * 2;
      m = (m / pow2) * pow2;
      break;
    } else if ((n & pow2) != 0)
      m -= pow2;
    pow2 = pow2 / 2;
  }
  printf("%lld\n", m);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
