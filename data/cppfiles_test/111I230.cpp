#include <bits/stdc++.h>
using namespace std;
const long long NMX = 60, oo = 0x3C3C3C3C3C3C3C3C, Bs = 1000000007;
int q, n, k, f[NMX][NMX];
long long fv(long long x, long long y) {
  return x > n ? y == 0
               : (y < 0 ? 0
                        : (f[x][y] > -1
                               ? f[x][y]
                               : (f[x][y] = fv(x + 1, y + 1) +
                                            (y > 0) * fv(x + 1, y - 1))));
}
void xv(long long x, long long y) {
  if (x > n || y < 0) return;
  if (k <= fv(x + 1, y + 1)) {
    cout << "(";
    xv(x + 1, y + 1);
    return;
  }
  cout << ")";
  k -= fv(x + 1, y + 1);
  xv(x + 1, y - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> q;
  while (q--) {
    cin >> n;
    n *= 2;
    for (long long i = 1; i <= n / 2; i++) {
      k = i;
      memset(f, -1, sizeof(f));
      xv(1, 0);
      cout << '\n';
    }
  }
  return 0;
}
