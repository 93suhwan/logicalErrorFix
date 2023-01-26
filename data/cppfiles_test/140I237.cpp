#include <bits/stdc++.h>
using namespace std;
const double kEps(1e-8);
#pragma gcc optimize(2)
int gcd(int x, int y) {
  while (y ^= x ^= y ^= x %= y)
    ;
  return x;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int qpow(int m, int n) {
  int res = 1;
  while (n) {
    if (n & 1) {
      res *= m;
    }
    n >>= 1;
    m *= m;
  }
  return res;
}
int max(int a, int b) {
  if (a > b) {
    return a;
  } else
    return b;
}
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 1;
    map<long long, long long> mp;
    for (long long i = 2; i < n; ++i) {
      if (i * i <= n) {
        ans++;
      }
      if (i * i * i <= n) {
        ans++;
      }
      mp[i * i]++;
      mp[i * i * i]++;
      if (i * i > n) {
        break;
      }
    }
    long long temp = 0;
    for (auto it : mp) {
      if (it.second > 1) {
        temp++;
      }
    }
    mp.clear();
    cout << ans - temp << '\n';
  }
}
