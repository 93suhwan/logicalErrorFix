#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x;
}
bool bz[200005];
int main() {
  int t = read();
  while (t--) {
    memset(bz, 0, sizeof bz);
    int a = read(), b = read(), n = a + b;
    for (register int i = 0; i <= a + b + 1 >> 1; ++i) {
      int num = b - i, num1 = (a + b >> 1) - num;
      if (num >= 0 && num1 >= 0) bz[num1 + i] = 1;
      num = a - i, num1 = (a + b >> 1) - num;
      if (num >= 0 && num1 >= 0) bz[num1 + i] = 1;
    }
    int aa = 0;
    for (register int i = 0; i <= a + b; ++i)
      if (bz[i]) aa++;
    printf("%d\n", aa);
    for (register int i = 0; i <= a + b; ++i)
      if (bz[i]) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
