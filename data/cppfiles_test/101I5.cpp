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
  long long t = 0, n = 0, f = 0;
  string s;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> n;
    long long a[n];
    for (long long j = 0; j < n; j++) cin >> a[j];
    cin >> s;
    long long l = 1, r = n;
    for (long long j = 0; j < n; j++) {
      if (s[j] == 'R') {
        if (a[j] > n) {
          f = 1;
          break;
        } else
          r--;
      }
    }
    for (long long j = 0; j < n; j++) {
      if (s[j] == 'B') {
        if (a[j] < 1) {
          f = 1;
          break;
        } else
          l++;
      }
    }
    if (f == 1)
      cout << "NO" << endl;
    else {
      if (r == l + 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    f = 0;
  }
}
