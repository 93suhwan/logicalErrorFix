#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char ch = getchar();
  bool f = false;
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = f ? -x : x;
  return;
}
template <typename T>
inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 ^ 48);
  return;
}
const long long MOD = 1e9 + 7, N = 2e5 + 3;
long long T;
long long f[N];
signed main() {
  read(T);
  while (T--) {
    long long n;
    read(n);
    long long ans = 1;
    for (register long long i = 1; i <= (n * 2); ++i) {
      if (i == 2) continue;
      ans = (ans * i) % MOD;
    }
    print(ans), putchar('\n');
  }
  return 0;
}
