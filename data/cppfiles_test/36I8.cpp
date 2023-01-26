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
const int maxn = 1e5 + 10, mod = 1e9 + 7;
int n, T;
int main() {
  read(T);
  while (T--) {
    read(n);
    if (n & 1) {
      for (register int i = 1; i < n / 2; i++) putchar('a');
      putchar('b');
      putchar('c');
      for (register int i = 1; i <= n / 2; i++) putchar('a');
    } else {
      for (register int i = 1; i < n / 2; i++) putchar('a');
      putchar('b');
      for (register int i = 1; i < n / 2; i++) putchar('a');
    }
    puts("");
  }
}
