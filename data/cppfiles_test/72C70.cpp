#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  char ch;
  bool ok;
  for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') ok = 1;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  if (ok) x = -x;
}
const int maxn = 110, mod = 998244353;
int ask(int x, int y) {
  int now;
  printf("? %d %d\n", x, y);
  fflush(stdout);
  read(now);
  return now;
}
int d1, d2, d3, d5, n = 1e9;
int main() {
  d1 = ask(1, 1), d2 = ask(n, 1);
  d3 = ask(1 + (n - 1 + d1 - d2) / 2, 1);
  d5 = ask(1 + (n - 1 + d1 - d2) / 2, n);
  printf("! %d %d %d %d\n", 1 + d1 - d3, 1 + d3, n - (d2 - d3), n - d5);
  fflush(stdout);
}
