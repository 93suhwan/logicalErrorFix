#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
inline void read(long long &x) {
  long long s = 0;
  x = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
  x *= s;
}
const long long N = 6e5 + 5, M = 25;
long long w[N], d[N];
long long n, logn[N << 2];
long long st[N][M];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void init() {
  for (long long i = 2; i <= n; i++) logn[i] = logn[i / 2] + 1;
  for (long long j = 0; j < M; j++)
    for (long long i = 2; i + (1 << j) - 1 <= n; i++)
      if (!j)
        st[i][j] = d[i];
      else
        st[i][j] = gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
}
long long query(long long l, long long r) {
  long long len = r - l + 1;
  long long k = logn[len];
  return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    read(n);
    for (long long i = (1); i <= (n); i++) read(w[i]);
    for (long long i = (2); i <= (n); i++) d[i] = w[i] - w[i - 1];
    init();
    long long res = 1;
    for (long long i = (2); i <= (n); i++) {
      long long l = i, r = n;
      while (l < r) {
        long long mid = l + r + 1 >> 1;
        if (abs(query(i, mid)) != 1)
          l = mid;
        else
          r = mid - 1;
      }
      if (abs(query(i, i)) == 1)
        continue;
      else
        res = max(res, l - i + 1 + 1);
    }
    cout << res << '\n';
  }
  return 0;
}
