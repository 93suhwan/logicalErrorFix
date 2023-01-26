#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const long long maxn = 2e5 + 1000;
const long long mode = 998244353;
string s;
long long n;
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= x * (a / b);
}
long long mi(long long a, long long b) {
  long long ans = 1;
  long long base = a;
  while (b) {
    if (b & 1) ans *= base;
    base *= base;
    ans %= mode;
    base %= mode;
    b >>= 1;
  }
  return ans;
}
signed main() {
  n = read();
  long long zero = 0, un = 0, zeroun = 0, unzero = 0, fr = 0, wb = 0, bw = 0;
  long long tot = n * 2;
  bool juge = false;
  for (long long i = 1; i <= n; ++i) {
    cin >> s;
    if (s[0] == 'W')
      zero++;
    else if (s[0] == 'B')
      un++;
    if (s[1] == 'W')
      zero++;
    else if (s[1] == 'B')
      un++;
    if (s == "BB" || s == "WW")
      juge = true;
    else if (s == "?B" || s == "W?")
      zeroun++;
    else if (s == "?W" || s == "B?")
      unzero++;
    else if (s == "??")
      fr++;
    else if (s == "WB")
      wb++;
    else if (s == "BW")
      bw++;
  }
  if (zero > n || un > n)
    cout << 0;
  else {
    long long a = tot - zero - un;
    long long b = n - zero;
    long long ans = 1;
    if (b != 0 && a != b) {
      long long faca = 1, facb = 1, facab = 1;
      for (long long i = 1; i <= a; ++i) faca = faca * i % mode;
      for (long long i = 1; i <= b; ++i) facb = facb * i % mode;
      for (long long i = 1; i <= a - b; ++i) facab = facab * i % mode;
      long long x, y;
      exgcd(facb, mode, x, y);
      facb = (x % mode + mode) % mode;
      exgcd(facab, mode, x, y);
      facab = (x % mode + mode) % mode;
      ans = faca * facb % mode * facab % mode;
    }
    if (juge)
      cout << ans;
    else {
      if ((zeroun || wb) && (unzero || bw)) {
        long long temp = mi(2, fr);
        ans = (ans - temp + mode) % mode;
      } else if (zeroun == 0 && wb == 0 && unzero == 0 && bw == 0) {
        long long temp = mi(2, fr) - 2;
        ans = (ans - temp + mode) % mode;
      } else {
        long long temp = mi(2, fr) - 1;
        ans = (ans - temp + mode) % mode;
      }
      cout << ans;
    }
  }
}
