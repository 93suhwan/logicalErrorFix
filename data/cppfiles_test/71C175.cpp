#include <bits/stdc++.h>
bool isp(int x) {
  if (x < 2) return 0;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
int FPW(int x, int y, int mod) {
  int res = 1;
  for (; y; y >>= 1) {
    if (y % 2) res = res * x % mod;
    x = x * x % mod;
  }
  return res;
}
using namespace std;
int cnts(int x) {
  int ret = 0;
  while (x) {
    ret |= (1 << (x % 10));
    x /= 10;
  }
  return __builtin_popcount(ret);
}
int main() {
  int T = read();
  while (T--) {
    int N = read(), K = read();
    int ans = N;
    while (cnts(ans) > K) {
      int l = 1, r = ans;
      while (cnts(r) > K) {
        l *= 10, r /= 10;
      }
      l /= 10;
      ans /= l;
      ans++;
      ans *= l;
    }
    cout << ans << endl;
  }
  return 0;
}
