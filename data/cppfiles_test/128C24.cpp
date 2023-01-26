#include <bits/stdc++.h>
using namespace std;
const long long infl = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = (long long)1e9 + 7;
vector<long long> primes;
void simpleSieve(long long lmt, vector<long long>& prime) {
  bool mark[lmt + 1];
  memset(mark, false, sizeof(mark));
  for (long long i = 2; i <= lmt; ++i) {
    if (!mark[i]) {
      prime.push_back(i);
      for (long long j = i; j <= lmt; j += i) {
        mark[j] = true;
      }
    }
  }
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  long long n;
  cin >> n;
  long long c = 1;
  for (auto x : primes) {
    long long a = n - x - 1;
    long long b = x;
    if (gcd(a, b) == 1) {
      cout << a << " " << b << " " << c << "\n";
      return;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);
  long long tt;
  tt = 1;
  simpleSieve(1000000, primes);
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
