#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar(), last = ' ';
  while (!isdigit(c)) last = c, c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (last == '-') x = -x;
}
int qpow(int x, int p, int mod) {
  int ret = 1;
  for (; p; x = 1ll * x * x % mod, p >>= 1)
    if (p & 1) ret = 1ll * ret * x % mod;
  return ret;
}
long long qpowl(long long x, long long p, long long mod) {
  long long ret = 1;
  for (; p; x = x * x % mod, p >>= 1)
    if (p & 1) ret = ret * x % mod;
  return ret;
}
long long qmul(long long a, long long b, int mod) {
  if (a < b) swap(a, b);
  long long ret = 0;
  for (; b; a = a * 2 % mod, b >>= 1)
    if (b & 1) ret = (ret + a) % mod;
  return ret;
}
long long qpowl_qmul(long long x, long long p, long long mod) {
  long long ret = 1;
  for (; p; x = qmul(x, x, mod), p >>= 1)
    if (p & 1) ret = qmul(ret, x, mod);
  return ret;
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
int split_int(int x, int *s) {
  int cnt = 0;
  while (x) {
    s[++cnt] = x % 10;
    x /= 10;
  }
  return cnt;
}
const int MAXN = 1e6 + 5;
int n, m;
int is[MAXN];
int lg[MAXN], ST[MAXN][20];
void ST_init() {
  for (int i = 2; i <= m; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= m; i++) ST[i][0] = is[i];
  int k = lg[m];
  for (int j = 1, lim; j <= k; j++) {
    lim = m - (1 << j) + 1;
    for (int i = 1; i <= lim; i++)
      ST[i][j] = max(ST[i][j - 1], ST[i + (1 << j - 1)][j - 1]);
  }
}
int RMQ(int l, int r) {
  int k = lg[r - l + 1];
  return max(ST[l][k], ST[r - (1 << k) + 1][k]);
}
int main() {
  read(n), read(m);
  vector<vector<char> > c(n + 5, vector<char>(m + 5));
  char in[MAXN];
  for (int i = 1; i <= n; i++) {
    scanf(" %s", in + 1);
    for (int j = 1; j <= m; j++) c[i][j] = in[j];
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      if (c[i][j - 1] == 'X' && c[i - 1][j] == 'X') is[j] = 1;
    }
  }
  ST_init();
  int q;
  read(q);
  for (int l, r; q--;) {
    read(l), read(r);
    if (l == r)
      puts("YES");
    else {
      puts(RMQ(l + 1, r) ? "NO" : "YES");
    }
  }
  return 0;
}
