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
  long long n;
  string s;
  cin >> s;
  vector<long long> v(26, 0);
  n = s.length();
  for (long long i = 0; i < n; i++) {
    v[s[i] - 'a']++;
  }
  long long z = 0;
  long long ans = 0, b = 0;
  long long k = 0;
  for (long long i = 0; i < v.size(); i++) {
    if (v[i] >= 2) {
      ans++;
    } else {
      if (v[i]) z++;
    }
  }
  ans = ans + z / 2;
  cout << ans << endl;
  return;
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
