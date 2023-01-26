#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x) {
  char ch = getchar();
  bool flag = false;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = true;
    ch = getchar();
  }
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
  if (flag) x = -x;
}
long long t, n, cnt;
int main() {
  read(t);
  while (t--) {
    cnt = 1;
    read(n);
    if (n == 1) {
      printf("0 1\n");
      continue;
    }
    if (n == 2) {
      printf("-1 2\n");
      continue;
    }
    while (n % 2 == 0) {
      cnt <<= 1;
      n >>= 1;
    }
    n >>= 1;
    printf("%lld %lld\n", n - cnt + 1, n + cnt);
  }
  system("pause");
  return 0;
}
