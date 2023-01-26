#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
long long mod = 1e9 + 7;
const long long inf = 9e18 + 37;
const int infi = 2e9 + 37;
const int N = 2e5 + 37;
vector<long long> fact = {1};
vector<int> sp;
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
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return i;
  return n;
}
inline long long ceil(long long a, long long b) { return (a + b - 1) / b; }
inline long long inv(long long n) { return fpow(n, mod - 2); }
void factorial(int Nf) {
  for (int i = 1; i < Nf; i++) fact.push_back(fact[i - 1] * i % mod);
}
long long C(long long n, long long r) {
  if (n < r) return 0;
  return fact[n] * inv(fact[n - r]) % mod * inv(fact[r]) % mod;
}
void sieve(int Ns) {
  sp.resize(Ns, 0);
  for (long long i = 2; i < Ns; i++)
    if (!sp[i]) {
      for (long long j = i * i; j < Ns; j += i)
        if (!sp[j]) sp[j] = i;
      sp[i] = i;
    }
}
void kingpin() {
  int i, j;
  string s, t;
  cin >> s >> t;
  string p;
  int ca = 0, cb = 0, cc = 0;
  for (char x : s)
    if (x == 'a')
      ca++;
    else if (x == 'b')
      cb++;
    else if (x == 'c')
      cc++;
    else
      p += x;
  if (t != "abc") {
    for (i = 0; i < ca; i++) cout << 'a';
    for (i = 0; i < cb; i++) cout << 'b';
    for (i = 0; i < cc; i++) cout << 'c';
  } else {
    for (i = 0; i < ca; i++) cout << 'a';
    for (i = 0; i < cc; i++) cout << 'c';
    for (i = 0; i < cb; i++) cout << 'b';
  }
  cout << p << '\n';
}
int main(void) {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) kingpin();
  return 0;
}
