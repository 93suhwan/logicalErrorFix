#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
inline bool Min(S& a, const T& b) {
  return a > b ? a = b, true : false;
}
template <typename S, typename T>
inline bool Max(S& a, const T& b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline bool IsPri(T x) {
  if (x < 2) return false;
  for (T i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
template <class T>
T gcd(T a, T b) {
  a = abs(a), b = abs(b);
  return b == 0 ? a : gcd(b, a % b);
};
template <typename T>
inline int _BitCnt(T x) {
  int cnt = 0;
  while (x) ++cnt, x &= x - 1;
  return cnt;
}
template <class T>
double dpow(double a, T b) {
  double res = 1.0;
  for (; b > 0; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
inline int read() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  int x = false;
  char ch =
      p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
          ? EOF
          : *p1++;
  ;
  bool sgn = false;
  while (ch != '-' && (ch < '0' || ch > '9'))
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  if (ch == '-')
    sgn = true,
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48),
    ch = p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
  ;
  return sgn ? -x : x;
}
long long qpow(long long a, long long b, long long mod) {
  long long res = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
inline long long inv(long long a, long long p) { return qpow(a, p - 2, p); }
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int M = 5e3 + 10;
const double PI = acos(-1.0);
const double eps = 1e-8;
long long d[N];
long long sum[N];
int main() {
  int n, m;
  cin >> n >> m;
  d[2] = 2;
  d[1] = 1;
  sum[1] = 1, sum[2] = 3;
  for (int i = 3; i <= n; i++) {
    int tmp = sqrt(i);
    d[i] = (d[i] + sum[i - 1]) % m;
    for (int j = 2; j <= i;) {
      int now = j;
      int tmp = i / j;
      int nex = i / tmp;
      int nexn = min(nex, n);
      d[i] = (d[i] + 1ll * (nexn - now + 1) * d[tmp] % m) % m;
      j = nexn + 1;
    }
    sum[i] = (sum[i - 1] + d[i]) % m;
  }
  cout << d[n] << endl;
  return 0;
}
