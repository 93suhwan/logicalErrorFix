#include <bits/stdc++.h>
using namespace std;
long long i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
long long r, c, x1, greniogin, x2, y2;
long long fxp(long long b, long long e) {
  long long r = 1, k = b;
  while (e != 0) {
    if (e % 2) r = (r * k) % 1000000007;
    k = (k * k) % 1000000007;
    e /= 2;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k >> r >> c >> x1 >> greniogin >> x2 >> y2;
  a = n * m;
  if (x1 != x2 || greniogin != y2) a -= (r * c);
  cout << fxp(k, a) << "\n";
  return 0;
}
