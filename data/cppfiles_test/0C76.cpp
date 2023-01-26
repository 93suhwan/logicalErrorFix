#include <bits/stdc++.h>
const int P = 1e9 + 7;
int plus(const int x, const int y) {
  return (x + y >= P) ? (x + y - P) : (x + y);
}
int times(const int x, const int y) { return (long long)x * y % P; }
int power(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = times(r, a);
    a = times(a, a);
    b >>= 1;
  }
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, Q;
  std::cin >> n >> Q;
  int lim = n * 3 + 3;
  std::vector<int> fac(lim + 1), ifac(lim + 1);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= lim; ++i) fac[i] = times(fac[i - 1], i);
  ifac[lim] = power(fac[lim], P - 2);
  for (int i = lim; i > 1; --i) ifac[i - 1] = times(ifac[i], i);
  std::vector<int> a(lim + 1);
  for (int i = 0; i <= lim; ++i)
    a[i] = times(fac[lim], times(ifac[i], ifac[lim - i]));
  a[0] = plus(a[0], P - 1);
  a[1] = plus(a[1], P - 3);
  a[2] = plus(a[2], P - 3);
  a[3] = plus(a[3], P - 1);
  for (int i = lim; i >= 3; --i) {
    a[i - 1] = plus(a[i - 1], P - times(a[i], 3));
    a[i - 2] = plus(a[i - 2], P - times(a[i], 3));
  }
  while (Q--) {
    int x;
    std::cin >> x;
    std::cout << a[x + 3] << '\n';
  }
  return 0;
}
