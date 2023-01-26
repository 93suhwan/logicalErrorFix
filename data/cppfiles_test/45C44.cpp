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
    long long n;
    read(n);
    long long f = 0;
    long long h = 1;
    long long op = 0;
    long long pre = 0;
    for (long long i = 1; i <= n; i++) {
      long long x;
      read(x);
      if (x == 1) {
        if (pre == 1) {
          h = h + 5;
        } else {
          h++;
        }
        pre = x;
        f = 0;
        continue;
      }
      f++;
      pre = 0;
      if (f == 2) {
        op = 1;
      }
    }
    if (op) {
      printf("-1\n");
      continue;
    }
    printf("%lld\n", h);
  }
}
