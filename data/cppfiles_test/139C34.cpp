#include <bits/stdc++.h>
using namespace std;
vector<int> _primes(int n) {
  vector<bool> prime(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  vector<int> res;
  for (int i = 2; i <= n; i++) {
    if (prime[i]) {
      res.push_back(i);
    }
  }
  return res;
}
unsigned long long _power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long _modInverse(unsigned long long n, int p) {
  return _power(n, p - 2, p);
}
unsigned long long _ncr(unsigned long long n, int r, int p) {
  if (n < r) {
    return 0;
  }
  if (r == 0) {
    return 1;
  }
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] * i) % p;
  }
  return (fac[n] * _modInverse(fac[r], p) % p * _modInverse(fac[n - r], p) %
          p) %
         p;
}
void solve() {
  string s;
  cin >> s;
  string ans = "NO";
  if (s.size() % 2 != 0) {
    cout << ans << endl;
    return;
  }
  string a = "";
  string b = "";
  for (int i = 0; i < s.size() / 2; i++) {
    a += s[i];
    b += s[i + s.size() / 2];
  }
  if (a == b) {
    ans = "YES";
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
