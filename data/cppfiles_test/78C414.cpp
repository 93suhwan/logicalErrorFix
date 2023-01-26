#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
int main() {
  int t, a, b;
  for (scanf("%d", &t); t--;) {
    scanf("%d %d", &a, &b);
    if (a > (b >> 1))
      printf("%d\n", b % a);
    else
      printf("%d\n", b % ((b >> 1) + 1));
  }
  return 0;
}
