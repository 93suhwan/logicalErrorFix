#include <bits/stdc++.h>
using namespace std;
namespace PrimeJudger {
const __int128 Test[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
__int128 pow(__int128 a, __int128 p, __int128 mod) {
  __int128 base = 1;
  for (; p; p >>= 1, a = a * a % mod)
    if (p & 1) base = base * a % mod;
  return base % mod;
}
__int128 Query(__int128 P) {
  if (P == 1 || (P > 2 && P % 2 == 0)) return 0;
  __int128 t = P - 1, k = 0;
  while (!(t & 1)) k++, t >>= 1;
  for (__int128 i = 0; i < 6; i++) {
    if (P == Test[i]) return 1;
    __int128 a = pow(Test[i], t, P), nxt = a;
    for (__int128 j = 1; j <= k; j++) {
      nxt = a * a % P;
      if (nxt == 1 && a != 1 && a != P - 1) return 0;
      a = nxt;
    }
    if (a != 1) return 0;
  }
  return 1;
}
}  // namespace PrimeJudger
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 7e5 + 5;
long long n, m;
char s[N], t[N];
long long z[N * 2];
void getZ(char *s, long long *z, long long n) {
  memset(z, 0, sizeof(n + 1));
  z[1] = n;
  for (long long i = 2, l = 0, r = 0; i <= n; i++) {
    if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
    while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) r = i + z[i] - 1, l = i;
  }
}
long long Rnd(long long l, long long r) { return rnd() % (r - l + 1) + l; }
long long getPrime(long long l, long long r) {
  long long x = Rnd(l, r);
  while (!PrimeJudger::Query(x)) x = Rnd(l, r);
  return x;
}
const long long P[6] = {getPrime(1e4, 1e9),   getPrime(1e12, 1e13),
                        getPrime(1e12, 1e13), getPrime(1e12, 1e13),
                        getPrime(1e12, 1e13), getPrime(1e13, 1e14)};
struct ele {
  long long a[6];
  long long &operator[](long long x) { return a[x]; }
  ele() {}
  ele(long long x) {
    for (long long i = 0; i < 6; i++) a[i] = x;
  }
  ele operator+(ele b) {
    ele ans;
    for (long long i = 0; i < 6; i++) ans[i] = (a[i] + b[i]) % P[i];
    return ans;
  }
  ele operator-(ele b) {
    ele ans;
    for (long long i = 0; i < 6; i++) ans[i] = (a[i] - b[i] + P[i]) % P[i];
    return ans;
  }
  ele operator*(ele b) {
    ele ans;
    for (long long i = 0; i < 6; i++) ans[i] = (__int128)a[i] * b[i] % P[i];
    return ans;
  }
  ele operator+(const unsigned long long &b) {
    ele ans;
    for (long long i = 0; i < 6; i++) ans[i] = (a[i] + b) % P[i];
    return ans;
  }
  ele operator*(const unsigned long long &b) {
    ele ans;
    for (long long i = 0; i < 6; i++) ans[i] = (__int128)a[i] * b % P[i];
    return ans;
  }
  bool operator==(ele b) {
    for (long long i = 0; i < 6; i++)
      if (a[i] != b[i]) return 0;
    return 1;
  }
} pw[N], hs[N], valx;
ele ghsh(long long l, long long r) { return hs[r] - hs[l - 1] * pw[r - l + 1]; }
void chk(long long l, long long r, long long L, long long R) {
  if (l > r || L > R || l < 1 || R > n) return;
  if (ghsh(l + m + 1, r + m + 1) + ghsh(L + m + 1, R + m + 1) == valx) {
    printf("%lld %lld\n%lld %lld\n", l, r, L, R);
    exit(0);
  }
}
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%s", t + 1);
  m = strlen(t + 1);
  for (long long i = 1; i <= n; i++) t[m + 1 + i] = s[i];
  getZ(t, z, n + 1 + m);
  getZ(t, z, n + 1 + m);
  pw[0] = ele(1);
  for (long long i = 1; i <= n + m + 1; i++)
    hs[i] = hs[i - 1] * 10 + (t[i] - '0'), pw[i] = pw[i - 1] * 10;
  valx = hs[m];
  for (long long i = m - 1; i <= n; i++) {
    if (i >= m) {
      long long lcp = z[i - m + 1 + m + 1];
      chk(i - m + 1, i, i + 1, i + m - lcp);
      chk(i - m + 1, i, i + 1, i + m - lcp + 1);
      chk(i - m + 1, i, i + 1, i + m - lcp - 1);
    }
    chk(i - m + 2, i, i + 1, i + m - 1);
  }
  for (long long i = 1; i <= n - m + 1; i++) {
    if (i + m - 1 <= n) {
      long long lcp = z[i + m + 1];
      chk(i - m + lcp, i - 1, i, i + m - 1);
      chk(i - m + lcp + 1, i - 1, i, i + m - 1);
      chk(i - m + lcp - 1, i - 1, i, i + m - 1);
    }
    chk(i - m + 1, i - 1, i, i + m - 2);
  }
  assert(0);
  return 0;
}
