#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int Mxdt = 100000, mod = 998244353;
char gc() {
  return getchar();
  static char buf[Mxdt], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, Mxdt, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int a = 0;
  bool opt = 0;
  char c = gc();
  while (c < '0' || c > '9') opt |= c == '-', c = gc();
  while (c >= '0' && c <= '9') a = (a << 3) + (a << 1) + (c ^ 48), c = gc();
  return opt ? -a : a;
}
int Mod(int x) { return x < mod ? x : x - mod; }
void Add(int& x, int y) { x = Mod(x + y); }
int T, n, a[100005], s[2][100005], sz[2][100005], top[2], ans;
void ADD(int opt, int x, int num) {
  if (top[opt] && x == s[opt][top[opt]]) {
    Add(sz[opt][top[opt]], num);
  } else {
    s[opt][++top[opt]] = x;
    sz[opt][top[opt]] = num;
  }
}
int main() {
  T = read() + 1;
  while (--T) {
    n = read();
    ans = 0;
    for (int i = 1; i <= n; ++i) a[i] = read();
    int now = 0;
    top[now] = 0;
    for (int i = n; i; --i) {
      top[now ^ 1] = 0;
      for (int j = 1; j <= top[now]; ++j) {
        int x = (a[i] - 1) / (s[now][j]) + 1;
        Add(ans, 1ll * (x - 1) * sz[now][j] % mod * i % mod);
        ADD(now ^ 1, a[i] / x, sz[now][j]);
      }
      ADD(now ^ 1, a[i], 1);
      now ^= 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
