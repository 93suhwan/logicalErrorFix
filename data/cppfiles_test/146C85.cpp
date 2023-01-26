#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T re() {
  T N = 0;
  char c = getchar();
  bool neg = 0;
  for (; c < '0' || c > '9'; c = getchar()) neg |= c == '-';
  for (; c >= '0' && c <= '9'; c = getchar()) N = (N << 3) + (N << 1) + c - '0';
  return neg ? -N : N;
}
const int MX = 1e5;
const int SQRTN = 320;
int n, q;
int p[MX + 5];
int rev[MX + 5];
int a[MX + 5];
int main() {
  n = re<int>();
  q = re<int>();
  for (int i = 1; i <= n; i++) rev[p[i] = re<int>()] = i;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
    for (int j = 0; j < SQRTN; j++) a[i] = p[a[i]];
  }
  for (int qq = 0, t, x, y; qq < q; qq++) {
    t = re<int>();
    x = re<int>();
    y = re<int>();
    if (t == 1) {
      swap(rev[p[x]], rev[p[y]]);
      swap(p[x], p[y]);
      for (int ff = 0, u; ff < 2; ff++) {
        u = x;
        for (int i = 0; i < SQRTN; i++) u = p[u];
        for (int i = 0; i < SQRTN; i++) {
          a[x] = u;
          x = rev[x];
          u = rev[u];
        }
        swap(x, y);
      }
    } else {
      for (; y >= SQRTN; y -= SQRTN) x = a[x];
      for (; y > 0; --y) x = p[x];
      printf("%d\n", x);
    }
  }
  return 0;
}
