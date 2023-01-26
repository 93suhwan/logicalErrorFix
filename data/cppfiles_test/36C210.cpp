#include <bits/stdc++.h>
using namespace std;
int T, n;
int a[110];
template <typename Tp>
void read(Tp &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
int main() {
  read(T);
  while (T--) {
    read(n);
    int sum = 0;
    for (int i = 1; i <= n; ++i) read(a[i]), sum += a[i];
    if (sum & 1) {
      for (int i = 2; i <= sqrt(sum); ++i) {
        if (sum % i == 0) goto loop;
      }
      printf("%d\n", n - 1);
      bool flag = true;
      for (int i = 1; i <= n; ++i) {
        if (flag && (a[i] & 1)) {
          flag = false;
          continue;
        }
        printf("%d ", i);
      }
      printf("\n");
    } else {
    loop:
      printf("%d\n", n);
      for (int i = 1; i <= n; ++i) printf("%d ", i);
      printf("\n");
    }
  }
  return 0;
}
