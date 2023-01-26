#include <bits/stdc++.h>
using namespace std;
void err() { cout << "\033[39;0m" << endl; }
template <class T, class... Ts>
void err(const T& arg, const Ts&... args) {
  cout << arg << " ";
  err(args...);
}
const int N = 100010;
const int mod = 998244353;
long long fac[N], inv[N];
long long ksm(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
void init(int n) {
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  inv[n] = ksm(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1) % mod;
  }
}
long long C(int a, int b) { return fac[a] * inv[b] % mod * inv[a - b] % mod; }
int n;
string s;
int main() {
  init(100000);
  scanf("%d", &n);
  int bc, wc, bw, wb, wwbb, xx;
  bc = wc = bw = wb = wwbb = xx = 0;
  for (int i = int(1); i <= int(n); i++) {
    cin >> s;
    if (s == "WW" || s == "BB") wwbb++;
    if (s == "??") xx++;
    if (s == "B?" or s == "?W" or s == "BW") bw++;
    if (s == "W?" or s == "?B" or s == "WB") wb++;
    for (auto c : s) {
      if (c == 'B')
        bc++;
      else if (c == 'W')
        wc++;
    }
  }
  if (bc > n or wc > n) {
    puts("0");
    return 0;
  }
  long long res = C(2 * n - bc - wc, n - bc);
  if (!wwbb) {
    res = (res + mod - ksm(2, xx)) % mod;
    if (bw + wb == 0) {
      res = (res + 2) % mod;
    } else if (bw == 0 || wb == 0) {
      res = (res + 1) % mod;
    }
  }
  printf("%lld\n", res);
}
