#include <bits/stdc++.h>
using namespace std;
inline long long qmi(long long a, long long b, long long mod) {
  long long ans = 1 % mod;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans % mod;
}
inline long long inv(long long a, long long mod) {
  return qmi(a, mod - 2, mod);
}
namespace FastIO {
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
int p, p3 = -1;
void read() {}
void print() {}
inline int getc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void flush() { fwrite(buf2, 1, p3 + 1, stdout), p3 = -1; }
template <typename T, typename... T2>
inline void read(T &x, T2 &...oth) {
  int f = 0;
  x = 0;
  char ch = getc();
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getc();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getc();
  }
  x = f ? -x : x;
  read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth) {
  if (p3 > 1 << 20) flush();
  if (x < 0) buf2[++p3] = 45, x = -x;
  do {
    a[++p] = x % 10 + 48;
  } while (x /= 10);
  do {
    buf2[++p3] = a[p];
  } while (--p);
  buf2[++p3] = hh;
  print(oth...);
}
}  // namespace FastIO
const int N = 1010;
int g[N][N];
int n, m, q;
long long ans = 0;
int dp1[N][N], dp2[N][N];
void change(int i, int j) {
  while (i <= n && j <= m) {
    if (i < n) {
      ans -= dp1[i + 1][j];
      dp1[i + 1][j] = g[i + 1][j] * (1 + dp2[i][j]);
      ans += dp1[i + 1][j];
    }
    if (j < m) {
      ans -= dp2[i][j + 1];
      dp2[i][j + 1] = g[i][j + 1] * (1 + dp1[i][j]);
      ans += dp2[i][j + 1];
    }
    if (i < n && j < m) {
      ans -= dp1[i + 1][j + 1] + dp2[i + 1][j + 1];
      dp1[i + 1][j + 1] = g[i + 1][j + 1] * (1 + dp2[i][j + 1]);
      dp2[i + 1][j + 1] = g[i + 1][j + 1] * (1 + dp1[i + 1][j]);
      ans += dp1[i + 1][j + 1] + dp2[i + 1][j + 1];
    }
    i++, j++;
  }
}
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dp1[i][j] = dp2[i][j] = 1;
      g[i][j] = 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i > 1) dp1[i][j] = dp2[i - 1][j] + 1;
      if (j > 1) dp2[i][j] = dp1[i][j - 1] + 1;
      ans += dp1[i][j] + dp2[i][j];
    }
  int base = n * m;
  while (q--) {
    int x, y;
    cin >> x >> y;
    g[x][y] ^= 1;
    if (!g[x][y]) {
      base--;
      ans -= (dp1[x][y] + dp2[x][y]);
      dp1[x][y] = dp2[x][y] = 0;
    } else {
      base++;
      ans -= (dp1[x][y] + dp2[x][y]);
      if (x > 1)
        dp1[x][y] = dp2[x - 1][y] + 1;
      else
        dp1[x][y] = 1;
      if (y > 1)
        dp2[x][y] = dp1[x][y - 1] + 1;
      else
        dp2[x][y] = 1;
      ans += dp1[x][y] + dp2[x][y];
    }
    change(x, y);
    cout << ans - base << endl;
  }
  return 0;
}
