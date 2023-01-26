#include <bits/stdc++.h>
#pragma GCC optimize(2)
template <class T>
inline T read(const T sample) {
  T x = 0;
  char s;
  bool f = 0;
  while ((s = getchar()) > '9' or s < '0') f |= (s == '-');
  while (s >= '0' and s <= '9')
    x = (x << 1) + (x << 3) + (s ^ 48), s = getchar();
  return f ? -x : x;
}
template <class T>
inline void write(const T x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
const int maxn = 105;
const int mod = 998244353;
int n, a[maxn], p[maxn];
int ask(int p, int a, int b) {
  putchar('?');
  for (int i = 1; i <= n; ++i)
    if (p ^ i)
      printf(" %d", b);
    else
      printf(" %d", a);
  puts("");
  fflush(stdout);
  return read(9);
}
int main() {
  n = read(9);
  int x, pos;
  for (int i = 1; i <= n; ++i) {
    x = ask(i, 1, 2);
    if (!x) {
      pos = i;
      break;
    } else {
      if (x ^ i) p[i] = x;
    }
  }
  a[pos] = 1;
  for (int i = 1; i < n; ++i) {
    int ind = 0;
    for (int j = 1; j <= n; ++j)
      if (p[j] == pos) {
        ind = j;
        break;
      }
    if (ind) {
      a[ind] = i + 1;
      pos = ind;
    } else {
      x = ask(pos, 2, 1);
      a[x] = i + 1;
      pos = x;
    }
  }
  putchar('!');
  for (int i = 1; i <= n; ++i) printf(" %d", a[i]);
  puts("");
  fflush(stdout);
  return 0;
}
