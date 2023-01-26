#include <bits/stdc++.h>
template <typename T>
bool _max(T& a, T b) {
  return (a < b) ? a = b, true : false;
}
template <typename T>
bool _min(T& a, T b) {
  return (b < a) ? a = b, true : false;
}
template <typename T>
T power(T base, T index, T mod) {
  return ((index <= 1) ? (index ? base : 1)
                       : (power(base * base % mod, index >> 1, mod) *
                          power(base, index & 1, mod))) %
         mod;
}
template <typename T>
T lowbit(T n) {
  return n & -n;
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T lcm(T a, T b) {
  return (a != 0 || b != 0) ? a / gcd(a, b) * b : (T)0;
}
template <typename T>
T exgcd(T a, T b, T& x, T& y) {
  if (!b) return y = 0, x = 1, a;
  T ans = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return ans;
}
int a[3];
int main() {
  unsigned t;
  int m;
  scanf("%u", &t);
  while (t--) {
    scanf("%d%d%d%d", a, a + 1, a + 2, &m);
    std::sort(a, a + 3);
    if (*a + a[1] + m + 1 < a[2])
      puts("No");
    else if (*a + a[1] + a[2] < m + 3)
      puts("No");
    else
      puts("Yes");
  }
  return 0;
}
