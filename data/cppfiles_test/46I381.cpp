#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 1, s = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return x * s;
}
int a[100005];
int main() {
  int n = read();
  long long ans = 0;
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int l = 1; l <= n; l += 2) {
    int c = a[l], rem = 0, sum = 0;
    for (int r = l + 1; r <= n; r++) {
      if ((r - l) & 1) {
        sum += a[r];
        if (sum >= rem) {
          sum -= rem;
          rem = 0;
          if (c != a[l]) {
            ans++;
          }
          if (sum > c) {
            ans += c;
            break;
          } else {
            ans += sum;
            c -= sum;
            sum = 0;
          }
        } else {
          rem -= sum;
          sum = 0;
        }
      } else {
        rem += a[r];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
