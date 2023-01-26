#include <bits/stdc++.h>
using namespace std;
bool isprime(long long k) {
  for (long long i = 2; i <= sqrt(k); i++)
    if (k % i == 0) return false;
  return true;
}
long long bm(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long t = bm(a, b / 2, mod);
  t = t * t % mod;
  return (b % 2 == 1 ? t * a % mod : t);
}
long long inv(long long a, long long mod) { return bm(a, mod - 2, mod); }
void gay(long long TC) { cout << "Case #" << TC << ": "; }
void solve(long long TC) {
  string s;
  cin >> s;
  long long n = s.length();
  if (n % 2) {
    cout << "NO\n";
    return;
  }
  if (s.substr(0, n / 2) != s.substr(n / 2, n / 2)) {
    cout << "NO\n";
  } else
    cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
