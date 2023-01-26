#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 9e18 + 37;
const int infi = 2e9;
const int N = 2e5 + 37;
const int Ns = 1;
const int Nf = 1;
long long fact[Nf] = {1};
int sp[Ns] = {0};
long long fpow(long long b, long long p) {
  long long ans = 1;
  while (p) {
    if (p % 2) ans = (ans * b) % mod;
    b = b * b % mod;
    p /= 2;
  }
  return ans;
}
long long sprime(long long n) {
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return i;
  return n;
}
inline long long ceil(long long a, long long b) { return (a + b - 1) / b; }
inline long long inv(long long n) { return fpow(n, mod - 2); }
inline long long rem(long long a, long long b) { return (a - 1) % b + 1; }
void factorial() {
  for (long long i = 1; i < Nf; i++) fact[i] = fact[i - 1] * i % mod;
}
long long C(long long n, long long r) {
  if (n < r) return 0;
  return fact[n] * inv(fact[n - r]) % mod * inv(fact[r]) % mod;
}
void sieve() {
  for (long long i = 2; i < Ns; i++)
    if (!sp[i]) {
      for (long long j = i * i; j < Ns; j += i)
        if (!sp[j]) sp[j] = i;
      sp[i] = i;
    }
}
void kingpin() {
  int i, j;
  int x, y;
  cin >> x >> y;
  if (x > y) {
    cout << x + y << endl;
    return;
  };
  {
    cout << y - y % x / 2 << endl;
    return;
  };
}
int main(void) {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) kingpin();
  return 0;
}
