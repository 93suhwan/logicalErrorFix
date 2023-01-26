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
void solve(long long TC) {
  string s;
  cin >> s;
  long long cnt = 0;
  for (long long i = 1; i < s.length(); i++) {
    if (s[i] != s[i - 1]) cnt++;
  }
  if (cnt == 0) {
    if (s[0] == '1')
      cout << "0\n";
    else
      cout << "1\n";
  } else if (cnt == 1) {
    cout << "1\n";
  } else if (cnt == 2 && s[0] == '1') {
    cout << "1\n";
  } else
    cout << "2\n";
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
