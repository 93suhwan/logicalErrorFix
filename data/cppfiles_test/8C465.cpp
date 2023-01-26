#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int res = 0;
  bool b = 0;
  while (c > '9' || c < '0') b = (c == '-'), c = getchar();
  while (c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
  return b ? -res : res;
}
int main() {
  int T = read();
  while (T--) {
    int n = read();
    int as1 = n / 3;
    if (n % 3 == 0)
      printf("%d %d\n", as1, as1);
    else if (n % 3 == 1)
      printf("%d %d\n", as1 + 1, as1);
    else
      printf("%d %d\n", as1, as1 + 1);
  }
  return 0;
}
