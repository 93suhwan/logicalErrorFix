#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 100;
long long n, m, k, cn[N][2], cm[N][2], b[2];
long long fn, fm, on, om, w, z[N];
long long dx[] = {0, 0, 1, -1};
long long dy[] = {1, -1, 0, 0};
unordered_map<long long, long long> col[N];
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
void add(long long x, long long y, long long k) {
  if (cn[x][0] || cn[x][1]) on--;
  if (cn[x][0] && cn[x][1]) fn--;
  cn[x][k ^ (y & 1)]++;
  if (cn[x][0] || cn[x][1]) on++;
  if (cn[x][0] && cn[x][1]) fn++;
  if (cm[y][0] || cm[y][1]) om--;
  if (cm[y][0] && cm[y][1]) fm--;
  cm[y][k ^ (x & 1)]++;
  if (cm[y][0] || cm[y][1]) om++;
  if (cm[y][0] && cm[y][1]) fm++;
  col[x][y] = k;
  b[(x + y) % 2 == k]++;
}
void del(long long x, long long y, long long k) {
  if (k == -1) return;
  if (cn[x][0] || cn[x][1]) on--;
  if (cn[x][0] && cn[x][1]) fn--;
  cn[x][k ^ (y & 1)]--;
  if (cn[x][0] || cn[x][1]) on++;
  if (cn[x][0] && cn[x][1]) fn++;
  if (cm[y][0] || cm[y][1]) om--;
  if (cm[y][0] && cm[y][1]) fm--;
  cm[y][k ^ (x & 1)]--;
  if (cm[y][0] || cm[y][1]) om++;
  if (cm[y][0] && cm[y][1]) fm++;
  col[x][y] = -1;
  b[(x + y) % 2 == k]--;
}
void prework() {
  z[0] = 1;
  n = 1000000;
  for (long long i = 1; i <= n; i++) z[i] = z[i - 1] * 2 % 998244353;
}
signed main() {
  prework();
  n = read();
  m = read();
  k = read();
  for (long long i = 1; i <= k; i++) {
    long long x = read(), y = read(), op = read();
    if (op == -1) {
      if (col[x].count(y)) {
        if (col[x][y] != -1) {
          w--;
          del(x, y, col[x][y]);
        }
      }
    } else {
      if (col[x].count(y)) {
        if (col[x][y] == -1)
          w++;
        else
          del(x, y, col[x][y]);
      } else
        w++;
      add(x, y, op);
    }
    if (fn && fm) {
      printf("0\n");
      continue;
    }
    if (fn) {
      printf("%lld\n", z[m - om]);
      continue;
    }
    if (fm) {
      printf("%lld\n", z[n - on]);
      continue;
    }
    long long ans = (z[n - on] + z[m - om]) % 998244353;
    if (b[0] == w) ans--;
    if (b[1] == w) ans--;
    ans = (ans + 998244353) % 998244353;
    printf("%lld\n", ans);
  }
}
