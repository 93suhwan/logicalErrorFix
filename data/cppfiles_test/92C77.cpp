#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
void BOOM_BAAM() {
  string s;
  cin >> s;
  long long n = s.size();
  vector<long long> x(n, 0);
  long long ab = 0, ba = 0;
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b') {
      ab++;
    }
    if (s[i] == 'b' && s[i + 1] == 'a') {
      ba++;
    }
  }
  if (ab == ba) {
    cout << s << endl;
    return;
  }
  char z = 'a';
  if (s[0] == 'a') {
    z = 'b';
  }
  s[0] = z;
  cout << s << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long T = 1;
  cin >> T;
  while (T--) {
    BOOM_BAAM();
  }
  return 0;
}
