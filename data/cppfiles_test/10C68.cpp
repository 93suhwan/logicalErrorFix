#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
const int mod = 1e9 + 7;
long long n, m, k, r, c, x, y, xx, yy;
long long fpow(long long n, long long m) {
  long long res = 1;
  while (m) {
    if (m & 1) res = res * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return res;
}
int main() {
  cin >> n >> m >> k >> r >> c >> x >> y >> xx >> yy;
  if (x == xx && y == yy) {
    cout << fpow(k, n * m);
  } else
    cout << fpow(k, n * m - r * c);
}
