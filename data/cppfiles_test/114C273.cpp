#include <bits/stdc++.h>
using namespace std;
const long long MAX18 = 1e18 + 5;
const int MOD = 1e9 + 5;
const int MAX9 = 1e9 + 5;
const int MAX = 1e6 + 5;
const int MAX5 = 1e5 + 5;
inline long long mygcd(long long x, long long y) {
  return x % y == 0 ? y : mygcd(y, x % y);
}
inline long long mylcm(long long x, long long y) { return x / mygcd(x, y) * y; }
inline long long mymax(long long x, long long y) { return x < y ? y : x; }
inline long long mymin(long long x, long long y) { return x > y ? y : x; }
void P(long long x) { cout << x << "\n"; }
void _() {
  cout << "=========="
       << "\n";
}
void _(long long x) { cout << "cout<<" << x << "\n"; }
void _(long long x, long long y) {
  cout << "cout<<" << x << " and " << y << "\n";
}
void _(long long x, long long y, long long z) {
  cout << "cout<<" << x << " " << y << " and " << z << "\n";
}
void _(long long x, long long y, long long z, long long u) {
  cout << "cout<<" << x << " " << y << " " << z << " and " << u << "\n";
}
inline double mymax(double x, double y) { return x > y ? y : x; }
inline double mymin(double x, double y) { return x > y ? y : x; }
inline long long mypow(long long n, long long k, long long p) {
  long long r = 1 % p;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
inline long long mypow(long long n, long long k) {
  int p = MOD;
  long long r = 1 % p;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
inline long long mymul(unsigned long long n, unsigned long long k,
                       unsigned long long p) {
  n %= p, k %= p;
  unsigned long long c = (long double)n * k / p, x = n * k, y = c * p;
  long long ans = (long long)(x % p) - (long long)(y % p);
  if (ans < 0) ans += p;
  return ans;
}
inline long long mymul(long long n, long long k) {
  unsigned long long p = MOD;
  n %= p, k %= p;
  unsigned long long c = (long double)n * k / p, x = n * k, y = c * p;
  long long ans = (long long)(x % p) - (long long)(y % p);
  if (ans < 0) ans += p;
  return ans;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
long long n, ans, num[MAX], a[MAX];
bool Ans;
void clear() {
  ans = 0;
  Ans = true;
}
void solve() {
  cin >> n;
  for (int i = (int)(1); i <= (int)(n); i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = (int)(n); i >= (int)(1); i--) {
    if (ans == n / 2) break;
    cout << a[i] << " " << a[1] << "\n";
    ans++;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T-- > 0) {
    clear();
    solve();
  }
  return 0;
}
