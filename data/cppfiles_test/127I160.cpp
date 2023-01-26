#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    long long a = 0, b = 0, c = 0;
    sort(s.begin(), s.end());
    if (t == "abc") {
      for (long long i = 0; i < s.size(); i++) {
        if (s[i] == 'b') {
          s[i] = 'c';
          break;
        }
      }
      long long count = 0;
      for (long long i = 0; i < s.size(); i++) {
        if (s[i] == 'c' && count == 0) {
          count++;
        } else if (s[i] == 'c' && count == 1) {
          s[i] = 'b';
          break;
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
