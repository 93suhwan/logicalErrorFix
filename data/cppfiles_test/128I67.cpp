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
      if (n & 1)
        printf("%d %d %d\n", n / 2 - 2, n / 2 + 2, 1);
      else {
        printf("%d %d %d\n", n / 2, n / 2 - 1, 1);
      }
    }
  return 0;
}
