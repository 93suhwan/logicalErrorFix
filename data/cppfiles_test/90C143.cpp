#include <bits/stdc++.h>
using namespace std;
int mylog(int a) {
  int ans = 0;
  if (a & 0xffff0000) {
    ans += 16;
    a >>= 16;
  }
  if (a & 0x0000ff00) {
    ans += 8;
    a >>= 8;
  }
  if (a & 0x000000f0) {
    ans += 4;
    a >>= 4;
  }
  if (a & 0x0000000c) {
    ans += 2;
    a >>= 2;
  }
  if (a & 0x00000002) {
    ans += 1;
    a >>= 1;
  }
  return ans;
}
inline int read() {
  register int a = 0, b = 0;
  register char c;
  c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') b = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a *= 10;
    a += c - '0';
    c = getchar();
  }
  return b ? -a : a;
}
const int MAXN = 100010;
int a[MAXN];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main() {
  int t = read();
  while (t--) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    if (y >= x) {
      long long k = ((y - x) % x) >> 1;
      printf("%lld\n", y - k);
    } else {
      printf("%lld\n", x + y);
    }
  }
  return 0;
}
