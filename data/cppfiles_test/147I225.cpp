#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  long long t = 0;
  string s;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> s;
    long long n = s.length();
    if (s[n - 1] == 'E')
      cout << "YES" << endl;
    else {
      long long f = 0;
      for (long long j = 0; j < n - 1; j++) {
        if (s[j] == 'N') {
          f = 1;
          break;
        }
      }
      if (f == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
