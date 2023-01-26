#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkMax(T &x, T y) {
  if (y > x) x = y;
}
template <typename T>
void chkMin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
  x *= f;
}
const int N = 300005;
int n, q, s[N];
char g[N];
int main() {
  int T;
  read(T);
  while (T--) {
    read(n), read(q);
    scanf("%s", g + 1);
    for (int i = 1; i <= n; i++) {
      int v = g[i] - '0';
      if (i % 2 == 0) v = -v;
      s[i] = s[i - 1] + v;
    }
    while (q--) {
      int l, r;
      read(l), read(r);
      int t = s[r] - s[l - 1];
      if (!t)
        puts("0");
      else if (t & 1)
        puts("1");
      else
        puts("2");
    }
  }
  return 0;
}
