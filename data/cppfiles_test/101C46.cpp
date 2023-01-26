#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
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
const long long mod = 998244353;
const int N = 1e6 + 5;
long long n, m, _;
int i, j, k;
vector<int> row, col;
int havex[N], havey[N];
map<pair<int, int>, int> mpx, mpy;
void clear() {
  row.clear();
  col.clear();
  fill_n(havex, sizeof(havex) / sizeof(0), 0);
  fill_n(havey, sizeof(havey) / sizeof(0), 0);
  mpx.clear();
  mpy.clear();
}
signed main() {
  int T;
  while (cin >> T)
    while (T--) {
      scanf("%d%d%d", &n, &m, &k);
      for (int i = (1); i <= (n); i++) {
        row.push_back(read());
      }
      for (int i = (1); i <= (m); i++) {
        col.push_back(read());
      }
      long long ans = 0;
      while (k-- > 0) {
        int x, y;
        scanf("%d%d", &x, &y);
        auto nx = lower_bound(row.begin(), row.end(), x);
        auto ny = lower_bound(col.begin(), col.end(), y);
        if (x == *nx && y == *ny) continue;
        if (x == *nx) {
          ans += havey[*ny] - mpy[{*ny, *nx}];
          havey[*ny]++;
          mpy[{*ny, *nx}]++;
        } else {
          ans += havex[*nx] - mpx[{*nx, *ny}];
          havex[*nx]++;
          mpx[{*nx, *ny}]++;
        }
      }
      pair<long long, long long>(ans);
      clear();
    }
  return 0;
}
