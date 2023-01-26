#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const double eps = 1e-8;
const long long mod = 1000000007;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
long long qpow(long long a, long long b) {
  long long s = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      s = s * a;
    }
    a = a * a;
    b = b >> 1;
  }
  return s;
}
long long qpowmod(long long a, long long b, long long c) {
  long long res, t;
  res = 1;
  t = a % c;
  while (b) {
    if (b & 1) {
      res = res * t % c;
    }
    t = t * t % c;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long read() {
  long long k = 0, f = 1;
  char ch = getchar();
  while (ch<'0' | ch> '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long maxn = 2e5 + 5;
long long t, n, k;
vector<long long> v1, v2;
void f1(long long x, long long now) {
  if (now <= 1e12)
    v1.push_back(now);
  else
    return;
  if (now * 10 + x != 0) f1(x, now * 10 + x);
}
void f2(long long x, long long y, long long now) {
  if (now <= 1e12)
    v2.push_back(now);
  else
    return;
  if (now * 10 + x != 0) f2(x, y, now * 10 + x);
  if (now * 10 + y != 0) f2(x, y, now * 10 + y);
}
signed main() {
  for (long long i = 0; i <= 9; i++) {
    f1(i, 0);
  }
  v1.erase(unique(v1.begin(), v1.end()), v1.end());
  sort(v1.begin(), v1.end());
  for (long long i = 0; i <= 9; i++) {
    for (long long j = i + 1; j <= 9; j++) {
      f2(i, j, 0);
    }
  }
  v2.erase(unique(v2.begin(), v2.end()), v2.end());
  sort(v2.begin(), v2.end());
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k == 1) {
      long long pos = lower_bound(v1.begin(), v1.end(), n) - v1.begin();
      cout << v1[pos] << "\n";
    } else {
      long long pos = lower_bound(v2.begin(), v2.end(), n) - v2.begin();
      cout << v2[pos] << "\n";
    }
  }
  return 0;
}
