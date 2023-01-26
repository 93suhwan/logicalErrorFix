#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
void read(T &res) {
  bool flag = false;
  char ch;
  while (!isdigit(ch = getchar())) (ch == '-') && (flag = true);
  for (res = ch - 48; isdigit(ch = getchar());
       res = (res << 1) + (res << 3) + ch - 48)
    ;
  flag && (res = -res);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long qp(long long a, long long b, long long mod) {
  long long ans = 1;
  if (b == 0) {
    return ans % mod;
  }
  while (b) {
    if (b % 2 == 1) {
      b--;
      ans = ans * a % mod;
    }
    a = a * a % mod;
    b = b / 2;
  }
  return ans % mod;
}
long long qpn(long long a, long long b, long long p) {
  long long ans = 1;
  a %= p;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % p;
      --b;
    }
    a = (a * a) % p;
    b >>= 1;
  }
  return ans % p;
}
signed main() {
  long long t;
  read(t);
  while (t--) {
    long long n, s;
    read(n);
    read(s);
    long long ans = s / n;
    ans = s / (n / 2 + 1);
    printf("%lld\n", ans);
  }
}
