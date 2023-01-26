#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char ch = getchar();
  while (0 == isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (0 != isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  x *= f;
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    x = ~(x - 1);
    putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 100;
char s[N];
int sum[N];
int main() {
  int w;
  cin >> w;
  while (w--) {
    int n, m;
    read(n), read(m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + (i % 2 ? 1 : -1) * (s[i] == '+' ? 1 : -1);
    }
    while (m--) {
      int l, r;
      read(l), read(r);
      if (sum[r] - sum[l - 1] == 0)
        puts("0");
      else if ((r - l + 1) & 1)
        puts("1");
      else
        puts("2");
    }
  }
  return 0;
}
