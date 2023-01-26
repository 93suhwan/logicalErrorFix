#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int limit = 5e5;
int read() {
  int s = 0;
  char c = getchar(), lc = '+';
  while (c < '0' || '9' < c) lc = c, c = getchar();
  while ('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
  return lc == '-' ? -s : s;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + '0');
  else
    write(x / 10), putchar(x % 10 + '0');
}
void print(long long x, char c = '\n') {
  write(x);
  putchar(c);
}
const int mod = 1e9 + 7;
const int M = 500 + 5;
const int S = (1 << 13) + 5;
const int N = 2e5 + 5;
int n, m, _, k;
long long a[N];
long long b[N], d[N];
signed main() {
  int T;
  while (cin >> T)
    while (T--) {
      scanf("%d", &n);
      for (int i = (1); i <= (n); i++) scanf("%lld", &b[i]);
      long long sum = 0;
      for (int i = (1); i <= (n); i++) sum += b[i];
      int ok = 1;
      int cnt = n * (n + 1) / 2;
      if (sum % cnt)
        ok = 0;
      else {
        sum = sum / cnt;
        for (int i = 1; i <= n && ok; i++) {
          int p = i - 1;
          if (p == 0) p = n;
          d[i] = b[i] - b[p] - sum;
          if (d[i] % n || d[i] >= 0) {
            ok = 0;
          } else {
            d[i] /= n;
            d[i] = -d[i];
          }
        }
      }
      if (ok) {
        puts("YES");
        for (int i = (1); i <= (n); i++) printf("%lld ", d[i]);
        puts("");
      } else {
        puts("NO");
      }
    }
  return 0;
}
