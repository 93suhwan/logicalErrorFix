#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
const long long N = 1e7 + 5;
bool sieve[N];
void soe() {
  for (long long i = 2; i < N; ++i) sieve[i] = true;
  for (long long i = 2; i * i < N; ++i) {
    if (sieve[i] == true) {
      for (long long j = i * i; j < N; j += i) {
        sieve[j] = false;
      }
    }
  }
}
long long countDivisors(long long n) {
  long long cnt = 0;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fact(long long n);
long long nCr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res;
}
long long PowMod(long long n) {
  long long ret = 1;
  long long a = 2;
  while (n > 0) {
    if (n & 1) ret = ret * a % 1000000007;
    a = a * a % 1000000007;
    n >>= 1;
  }
  return ret;
}
long long powermod(long long x, long long y, long long p) {
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
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  ;
  long long n;
  cin >> n;
  long long tot_node_except_root = pow(2, n) - 2;
  long long ans = powermod(4, tot_node_except_root, 1000000007);
  cout << (ans * 6) % 1000000007 << endl;
  return 0;
}
