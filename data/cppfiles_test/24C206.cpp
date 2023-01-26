#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int first = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) {
    if (ch == '-') f = -1;
  }
  for (; isdigit(ch); ch = getchar()) {
    first = first * 10 + ch - 48;
  }
  return first * f;
}
int main() {
  int T = read();
  while (T--) {
    int n = read();
    printf("%d\n", (n + 1) / 10);
  }
  return 0;
}
