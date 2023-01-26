#include <bits/stdc++.h>
using namespace std;
vector<long long> factorial;
vector<long long> inv;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long prime = 998244353;
long long binomial_coefficient(long n, long k) {
  return (factorial[n] *
          power(factorial[k] * factorial[n - k], prime - 2, prime)) %
         prime;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long wl = 0, wr = 0, bl = 0, br = 0, remR = 0, remL = 0;
  factorial.resize(n + 1);
  factorial[0] = 1;
  for (long i = 1; i <= n; i++) {
    factorial[i] = (factorial[i - 1] * i) % prime;
  }
  inv.resize(n + 1);
  inv[1] = 1;
  for (int i = 2; i < n; ++i) inv[i] = n - (n / i) * inv[n % i] % prime;
  bool same = false;
  bool isbw = false;
  bool iswb = false;
  long long qCount = 0;
  for (long long i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "??") qCount++;
    if (s == "BW" || s == "B?" || s == "?W") isbw = true;
    if (s == "WB" || s == "W?" || s == "?B") iswb = true;
    if (s == "BB" || s == "WW") same = true;
    if (s[0] == 'W') wl++;
    if (s[0] == 'B') bl++;
    if (s[1] == 'W') wr++;
    if (s[1] == 'B') br++;
  }
  remR = n - wr - br;
  remL = n - wl - bl;
  if (wl > br) {
    wl = wl - br;
    br = 0;
  } else {
    br = br - wl;
    wl = 0;
  }
  if (wr > bl) {
    wr = wr - bl;
    bl = 0;
  } else {
    bl = bl - wr;
    wr = 0;
  }
  long long res = 0;
  for (long long i = 0; i <= remR; ++i) {
    long long b = br + i;
    long long w = wr + remR - i;
    if (b < wl || w < bl) continue;
    res += binomial_coefficient(remR, i) * binomial_coefficient(remL, b - wl);
  }
  if (!same) {
    res -= power(2, qCount, prime);
    if (!isbw) res++;
    if (!iswb) res++;
    res %= prime;
  }
  res %= prime;
  cout << (res + prime) % prime << endl;
  return 0;
}
