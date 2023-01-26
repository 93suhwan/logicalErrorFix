#include <bits/stdc++.h>
using namespace std;
mt19937 gene(233);
inline char GET_CHAR() {
  const int maxn = 131072;
  static char buf[maxn], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, maxn, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int getInt() {
  int res(0);
  char c = getchar();
  while (c < '0') c = getchar();
  while (c >= '0') {
    res = res * 10 + (c - '0');
    c = getchar();
  }
  return res;
}
inline long long fastpo(long long x, long long n, long long mod) {
  long long res(1);
  while (n) {
    if (n & 1) {
      res = res * (long long)x % mod;
    }
    x = x * (long long)x % mod;
    n /= 2;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline string itoa(int x, int width = 0) {
  string res;
  if (x == 0) res.push_back('0');
  while (x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  while ((int)res.size() < width) res.push_back('0');
  reverse(res.begin(), res.end());
  return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
  fwrite(buf, 1, _bl, stdout);
  _bl = 0;
}
__inline void _putchar(char c) {
  if (_bl == _B) flush();
  buf[_bl++] = c;
}
inline void print(long long x, char c) {
  static char tmp[20];
  int l = 0;
  if (!x)
    tmp[l++] = '0';
  else {
    while (x) {
      tmp[l++] = x % 10 + '0';
      x /= 10;
    }
  }
  for (int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
  _putchar(c);
}
struct P {
  double x, y;
};
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N], f[N];
int main() {
  int t;
  scanf("%d", &t);
  for (int qq = 1; qq <= t; qq++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int ans = inf;
    for (int o = 0; o <= 6; o++) {
      for (int t = 0; t <= 6; t++) {
        fill(f, f + o + t * 2 + 1, false);
        for (int i = 0; i <= o; i++) {
          for (int j = 0; j <= t; j++) {
            f[i + j * 2] = true;
          }
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
          int tmp = inf;
          for (int j = o + t * 2; j >= 0; j--) {
            if (f[j] && (a[i] - j) % 3 == 0) {
              tmp = (a[i] - j) / 3;
              break;
            }
          }
          mx = max(mx, tmp);
        }
        ans = min(ans, o + t + mx);
      }
    }
    printf("%d\n", ans);
  }
}
