#include <bits/stdc++.h>
using namespace std;
unsigned long long revbits(unsigned long long x) {
  unsigned long long ret = 0;
  while (x) ret = (ret << 1) | (x & 1), x >>= 1;
  return ret;
}
bool testsub(unsigned long long x, unsigned long long y) {
  int nx = sizeof(unsigned long long) * 8 - __builtin_clzll(x);
  int ny = sizeof(unsigned long long) * 8 - __builtin_clzll(y);
  x = ((unsigned long long)1 << nx) - 1 - x;
  for (int i = 0; i <= ny - nx; ++i)
    if (__builtin_popcountll(y ^ (x << i)) == ny) return true;
  return false;
}
int main() {
  unsigned long long x, xx, y;
  bool ans = false;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> x >> y;
  ans = (x == y);
  xx = x >> __builtin_ctzll(x);
  ans |= testsub(xx, y) | testsub(revbits(xx), y);
  xx = (x << 1) ^ 1;
  ans |= testsub(xx, y) | testsub(revbits(xx), y);
  cout << (ans ? "YES\n" : "NO\n");
  return 0;
}
