#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  return x * f;
}
int main() {
  int T = read();
  while (T--) {
    long long s = read(), n = read(), k = read();
    if (k > s)
      puts("NO");
    else if (k == s)
      puts("YES");
    else {
      long long mx;
      if (s % k == 0) {
        mx = (s / k + 1) / 2ll * k;
      } else {
        if ((s / k) & 1)
          mx = (s / k + 1) / 2ll * k;
        else
          mx = (s / k) / 2ll * k + (s % k);
      }
      if ((s / k) & 1) mx--;
      if (n > mx)
        puts("YES");
      else
        puts("NO");
    }
  }
}
