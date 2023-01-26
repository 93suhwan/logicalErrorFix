#include <bits/stdc++.h>
using namespace std;
const long long mod = 993315154;
long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = getchar();
  }
  return s * w;
}
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const long long N = 4e5 + 100;
const long long inf = 0x3f3f3f3f;
long long arr[6];
long long n, m;
signed main() {
  long long T = 00;
  cin >> T;
  while (T--) {
    long long sum = 0;
    long long a, b, c;
    cin >> a >> b >> c;
    a = a % 2;
    b = b % 2;
    c = c % 2;
    if (a == 1) sum += 1;
    if (b == 1) sum += 2;
    if (c == 1) sum += 3;
    if (a == b && b == c) {
      cout << "0" << endl;
    } else {
      cout << sum % 2 << endl;
    }
  }
  return 0;
}
