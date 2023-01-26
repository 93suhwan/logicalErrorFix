#include <bits/stdc++.h>
using namespace std;
long long po(long long a, long long b, long long M) {
  long long res = 1;
  a = a % M;
  while (b) {
    if (b % 2) res = (res * a) % M;
    b /= 2;
    a = (a * a) % M;
  }
  return res;
}
long long pw(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return po(x, y / 2, 1000000007) % 1000000007 * po(x, y / 2, 1000000007) %
           1000000007;
  else
    return x * po(x, y / 2, 1000000007) % 1000000007 *
           po(x, y / 2, 1000000007) % 1000000007;
}
long long modInverse(long long n, long long M) { return po(n, M - 2, M); }
long long nCrModPFermat(long long n, long long r, long long M) {
  if (!r) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  long long i;
  for (i = 1; i < n + 1; i++) {
    fac[i] = fac[i - 1] * i % M;
  }
  return (fac[n] * modInverse(fac[r], M) % M * modInverse(fac[n - r], M) % M) %
         M;
}
long long logk(long long a, long long b) { return log(a) / log(b); }
bool isPrime(long long N) {
  for (long long i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool prime[1000001];
void SieveOfEratosthenes(long long n) {
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long n, ans = 0;
  cin >> n;
  long long a[n + 1];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i += 2) {
    long long ominusc = a[i];
    long long open = a[i];
    for (long long j = i + 1; j < n && ominusc >= 0; j++) {
      if (j % 2) {
        ominusc -= a[j];
        ans += max(min(open, open - ominusc), 0ll);
        open = min(open, ominusc + 1);
      } else {
        ominusc += a[j];
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
