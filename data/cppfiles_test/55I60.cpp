#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int p(int x, int y) {
  if (y == 0) {
    return 1;
  }
  int r = p(x, y / 2);
  if (y % 2) {
    return (1LL * (1LL * r * r % MOD) * x) % MOD;
  }
  return (1LL * r * r) % MOD;
}
int fac[200100];
int fiv[200100];
int main() {
  fac[0] = 1;
  fac[1] = 1;
  for (int i = 2; i <= 200000; i++) {
    fac[i] = (1LL * fac[i - 1] * i) % MOD;
  }
  fiv[200000] = p(fac[200000], MOD - 2);
  for (int i = 199999; i >= 0; i--) {
    fiv[i] = 1LL * fiv[i + 1] * (i + 1) % MOD;
  }
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i += 2) {
    }
  }
  return 0;
}
