#include <bits/stdc++.h>
using namespace std;
namespace IO_BUFF {
const long long BS = (1 << 24) + 5;
char Buffer[BS], *HD, *TL;
inline long long gc() {
  if (HD == TL) TL = (HD = Buffer) + fread(Buffer, 1, BS, stdin);
  return (HD == TL) ? EOF : *HD++;
}
inline long long inn() {
  long long x, ch;
  while ((ch = gc()) < '0' || ch > '9')
    ;
  x = ch ^ '0';
  while ((ch = gc()) >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ '0');
  return x;
}
char ss[19999999], tt[20];
long long ssl, ttl;
inline long long print(long long x) {
  if (x < 0) ss[++ssl] = '-', x = (-x);
  if (!x) ss[++ssl] = '0';
  for (ttl = 0; x; x /= 10) tt[++ttl] = char(x % 10 + '0');
  for (; ttl; ttl--) ss[++ssl] = tt[ttl];
  return ss[++ssl] = '\n';
}
inline long long Flush() {
  return fwrite(ss + 1, sizeof(char), ssl, stdout), ssl = 0, 0;
}
long long read() {
  char c = getchar();
  long long x = 1;
  long long s = 0;
  while (c < '0' || c > '9') {
    if (c == '-') x = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
}  // namespace IO_BUFF
using namespace IO_BUFF;
long long T;
const long long N = 1005;
long long n, m, q, x, y, f[N][N][2], summ, cnt, vis[N][N], ma[N][N];
struct node {
  long long x, y, id;
};
void solve() {
  n = read();
  m = read();
  q = read();
  cnt = summ = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long k = 1; k <= m; k++) {
      if (i > 1) f[i][k][0] = 1;
      if (k > 1) f[i][k][1] = 1;
      if (i > 1) f[i][k][0] = (f[i][k][0] + f[i - 1][k][1]);
      if (k > 1) f[i][k][1] = (f[i][k][1] + f[i][k - 1][0]);
      summ = summ + f[i][k][0] + f[i][k][1];
      ma[i][k] = 0;
    }
  }
  cnt = n * m;
  for (long long i = 1; i <= q; i++) {
    x = read();
    y = read();
    if (ma[x][y]) {
      ma[x][y] = 0;
      if (x > 1 && !ma[x - 1][y]) f[x][y][0] = 1;
      if (y > 1 && !ma[x][y - 1]) f[x][y][1] = 1;
      if (x > 1) f[x][y][0] = (f[x][y][0] + f[x - 1][y][1]);
      if (y > 1) f[x][y][1] = (f[x][y][1] + f[x][y - 1][0]);
      summ = summ + f[x][y][0] + f[x][y][1];
      vector<node> v;
      for (long long i = 1; i <= min(n - x, m - y); i++) {
        v.push_back((node){x + i, y + i - 1, 0});
        v.push_back((node){x + i - 1, y + i, 1});
        v.push_back((node){x + i, y + i, 3});
      }
      if (n - x != m - y) {
        if (n - x > m - y) {
          v.push_back((node){x + (m - y) + 1, m, 0});
        } else {
          v.push_back((node){n, y + (n - x) + 1, 1});
        }
      }
      for (long long i = 0; i < v.size(); i++) {
        long long xx = v[i].x, yy = v[i].y;
        if (ma[xx][yy]) continue;
        summ = summ - f[xx][yy][0] - f[xx][yy][1];
        f[xx][yy][0] = f[xx][yy][1] = 0;
        if (xx > 1 && !ma[xx - 1][yy]) f[xx][yy][0] = 1;
        if (yy > 1 && !ma[xx][yy - 1]) f[xx][yy][1] = 1;
        if (xx > 1 && !ma[xx - 1][yy])
          f[xx][yy][0] = (f[xx][yy][0] + f[xx - 1][yy][1]);
        if (yy > 1 && !ma[xx][yy - 1])
          f[xx][yy][1] = (f[xx][yy][1] + f[xx][yy - 1][0]);
        summ = summ + f[xx][yy][0] + f[xx][yy][1];
      }
      cnt++;
    } else {
      ma[x][y] = 1;
      summ = summ - f[x][y][0] - f[x][y][1];
      f[x][y][0] = f[x][y][1] = 0;
      vector<node> v;
      for (long long i = 1; i <= min(n - x, m - y); i++) {
        v.push_back((node){x + i, y + i - 1, 0});
        v.push_back((node){x + i - 1, y + i, 1});
        v.push_back((node){x + i, y + i, 3});
      }
      if (n - x != m - y) {
        if (n - x > m - y) {
          v.push_back((node){x + (m - y) + 1, m, 0});
        } else {
          v.push_back((node){n, y + (n - x) + 1, 1});
        }
      }
      for (long long i = 0; i < v.size(); i++) {
        long long xx = v[i].x, yy = v[i].y;
        if (ma[xx][yy]) continue;
        summ = summ - f[xx][yy][0] - f[xx][yy][1];
        f[xx][yy][0] = f[xx][yy][1] = 0;
        if (xx > 1 && !ma[xx - 1][yy]) f[xx][yy][0] = 1;
        if (yy > 1 && !ma[xx][yy - 1]) f[xx][yy][1] = 1;
        if (xx > 1 && !ma[xx - 1][yy])
          f[xx][yy][0] = (f[xx][yy][0] + f[xx - 1][yy][1]);
        if (yy > 1 && !ma[xx][yy - 1])
          f[xx][yy][1] = (f[xx][yy][1] + f[xx][yy - 1][0]);
        summ = summ + f[xx][yy][0] + f[xx][yy][1];
      }
      cnt--;
    }
    cout << summ + cnt << '\n';
  }
  for (long long i = 1; i <= n; i++)
    for (long long k = 1; k <= n; k++) ma[i][k] = 0;
}
signed main() {
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
