#include <bits/stdc++.h>
template <class T>
void chkmax(T& a, T b) {
  a > b ? (a = a) : (a = b);
}
template <class T>
void chkmin(T& a, T b) {
  a > b ? (a = b) : (a = a);
}
template <class T>
T min(T a, T b) {
  return a > b ? b : a;
}
template <class T>
T max(T a, T b) {
  return a < b ? b : a;
}
template <class T>
T abs(T a) {
  return a < 0 ? -a : a;
}
template <class T>
inline bool rd(T& ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return true;
}
template <class T>
inline void print(T x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
  return;
}
using std::cin;
using std::cout;
using std::map;
using std::priority_queue;
using std::queue;
using std::string;
using std::unordered_map;
using std::vector;
const int N = 2e5 + 5;
int f[N];
int n, mod;
int main() {
  rd(n);
  rd(mod);
  f[1] = 1;
  f[2] = 2;
  int sum = 3;
  for (int i = 3; i <= n; ++i) {
    f[i] = sum;
    for (int lr = 2, rs; lr <= i; lr = rs + 1) {
      rs = min(i / (i / lr), i);
      f[i] = (f[i] + 1ll * f[i / lr] * (rs - lr + 1)) % mod;
    }
    sum = (sum + f[i]) % mod;
  }
  print(f[n]);
  puts("");
  return 0;
}
