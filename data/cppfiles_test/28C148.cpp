#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
const long long MAXN = 1e7;
bool prime[MAXN + 5];
long long tot_primes_till[MAXN + 5];
void sieve() {
  int n = MAXN;
  fill(begin(prime), end(prime), true);
  prime[0] = prime[1] = false;
  for (long long i = 2; i <= n; i++) {
    tot_primes_till[i] = tot_primes_till[i - 1];
    if (!prime[i]) continue;
    tot_primes_till[i]++;
    for (long long j = 2 * i; j <= n; j += i) {
      prime[j] = false;
    }
  }
}
long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2, mod);
  ans *= ans;
  ans %= mod;
  if (b % 2) {
    ans *= a;
  }
  return ans % mod;
}
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long g1 = 0, g2 = 0;
  string s = "";
  if (a % 2) {
    s += '1';
  } else {
    s += '0';
  }
  if (b % 2) {
    s += '1';
  } else {
    s += '0';
  }
  if (c % 2) {
    s += '1';
  } else {
    s += '0';
  }
  if (s == "000" || s == "111" || s == "101" || s == "010") {
    cout << 0;
  } else {
    cout << 1;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
