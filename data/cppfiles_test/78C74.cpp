#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[200005], c[35];
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &a[i]);
  memset(c, 0, sizeof(c));
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(30); j++)
      if (a[i] >> j & 1) c[j]++;
  int r = 0;
  for (int i = 0; i < (int)(30); i++) r = gcd(r, c[i]);
  for (int i = 1; i <= (int)(n); i++)
    if (r % i == 0) printf("%d ", i);
  printf("\n");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
