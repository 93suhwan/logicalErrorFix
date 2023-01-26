#include <bits/stdc++.h>
using namespace std;
namespace mine {
long long qread() {
  long long ans = 0, f = 1;
  char c = getchar();
  while (c < '0' or c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c and c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans * f;
}
void write(long long num) {
  if (num < 0) putchar('-'), num = -num;
  if (num >= 10) write(num / 10);
  putchar('0' + num % 10);
}
void write1(long long num) {
  write(num);
  putchar(' ');
}
void write2(long long num) {
  write(num);
  putchar('\n');
}
template <typename T>
inline bool chmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool chmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
bool IN(long long x, long long l, long long r) { return l <= x and x <= r; }
void GG() {
  puts("-1");
  exit(0);
}
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int mm(const int x) { return x >= MOD ? x - MOD : x; }
template <typename T>
void add(T &x, const int &y) {
  x = (x + y >= MOD ? x + y - MOD : x + y);
}
long long qpower(long long x, long long e, int mod = MOD) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = ans * x % mod;
    x = x * x % mod;
    e >>= 1;
  }
  return ans;
}
long long invm(long long x) { return qpower(x, MOD - 2); }
const int N = 3e5 + 10, M = 2e6 + 10;
long long a[N];
void main() {
  int n = qread();
  long long sum = 0;
  for (int i = (1), I = (n); i <= I; i++) a[i] = qread(), sum += a[i];
  sort(a + 1, a + n + 1);
  for (int i = (1), I = (qread()); i <= I; i++) {
    long long x = qread(), y = qread();
    int p = lower_bound(a + 1, a + n + 1, x) - a;
    if (p > n) p = n;
    long long ans = max(0ll, x - a[p]) + max(0ll, y - (sum - a[p]));
    if (p != 1)
      chmin(ans, max(0ll, x - a[p - 1]) + max(0ll, y - (sum - a[p - 1])));
    write2(ans);
  }
}
};  // namespace mine
signed main() {
  srand(time(0));
  mine::main();
  printf("");
}
