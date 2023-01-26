#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long fastpow(long long base, long long p) {
  long long res = 1;
  for (; p; base = base * base % mod, p >>= 1)
    if (p & 1) res = res * base % mod;
  return res;
}
int n, m, r, c;
long long k;
int ax, ay, bx, by;
long long count(long long L, long long R, long long LL, long long RR) {
  if (LL == L && RR == R) {
    return fastpow(k, LL * RR);
  }
  if ((LL << 1) <= L || (RR << 1) <= R) {
    return fastpow(k, L * R - LL * RR);
  }
  return count(LL, RR, 2ll * LL - L, 2ll * RR - R) *
         fastpow(k, 2 * (L - LL) * (R - RR)) % mod;
}
int main() {
  cin >> n >> m >> k >> r >> c;
  cin >> ax >> ay >> bx >> by;
  if (abs(ax - bx) >= r || abs(ay - by) >= c) {
    cout << fastpow(k, 1ll * n * m - 1ll * r * c) << '\n';
  } else {
    long long LL = r - abs(ax - bx), RR = c - abs(ay - by);
    cout << count(r, c, LL, RR) *
                fastpow(k, 1ll * n * m - 2ll * r * c + LL * RR) % mod
         << '\n';
  }
  return 0;
}
