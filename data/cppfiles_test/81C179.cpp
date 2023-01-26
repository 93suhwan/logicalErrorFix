#include <bits/stdc++.h>
using namespace std;
namespace io {
inline long long read() {
  register char c = getchar();
  register long long x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
}  // namespace io
using namespace io;
int t;
int n, q, l, r;
int sum[300005];
int main() {
  t = read();
  while (t--) {
    n = read();
    q = read();
    char c;
    for (int i = 1; i <= n; i++) {
      c = getchar();
      if (c == '+')
        sum[i] = sum[i - 1] + (i & 1 ? 1 : -1);
      else
        sum[i] = sum[i - 1] - (i & 1 ? 1 : -1);
    }
    for (int i = 0; i < q; i++) {
      l = read();
      r = read();
      if (sum[r] == sum[l - 1])
        printf("0\n");
      else if ((r - l) & 1)
        printf("2\n");
      else
        printf("1\n");
    }
  }
  return 0;
}
