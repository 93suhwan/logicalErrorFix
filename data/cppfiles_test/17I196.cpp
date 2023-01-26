#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, sgn = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sgn = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return sgn * x;
}
int main() { return 0; }
