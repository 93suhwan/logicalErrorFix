#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int inf = 1 << 30;
const long long inff = 1ll << 60;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int n, q, a[N], b[N], c[N], l, r;
long long s[N];
struct ST_RMQ {
  long long Max[N][35], Min[N][35];
  int lg[N];
  void init(int n, long long a[]) {
    for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; i++) Max[i][0] = Min[i][0] = a[i];
    for (int j = 1; j <= lg[n]; j++)
      for (int i = 1; i <= n - (1 << j) + 1; i++)
        Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]),
        Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
  }
  long long mx(int l, int r) {
    int k = lg[r - l + 1];
    return max(Max[l][k], Max[r - (1 << k) + 1][k]);
  }
  long long mn(int l, int r) {
    int k = lg[r - l + 1];
    return min(Min[l][k], Min[r - (1 << k) + 1][k]);
  }
} ST;
int main() {
  int tests = 1;
  while (tests--) {
    n = read(), q = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) {
      b[i] = read();
      c[i] = b[i] - a[i];
      s[i] = s[i - 1] + c[i];
    }
    ST.init(n, s);
    while (q--) {
      l = read(), r = read();
      if (s[r] - s[l - 1])
        puts("-1");
      else {
        if (ST.mn(l, r) < s[l - 1])
          puts("-1");
        else
          printf("%lld\n", ST.mx(l, r) - s[l - 1]);
      }
    }
  }
  return 0;
}
