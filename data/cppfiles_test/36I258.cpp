#include <bits/stdc++.h>
using namespace std;
long long bp(long long x, long long y) {
  long long r = 1;
  while (y > 0) {
    if (y & 1) r = r * x;
    x = x * x;
    y >>= 1;
  }
  return r;
}
long long is(long long s) {
  long long f = 1;
  for (long long i = 2; i * i <= s; i++) {
    if (s % i == 0) {
      f = 0;
      break;
    }
  }
  return f;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    long long s = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    long long p = 0;
    if (is(s) == 0) {
      cout << n << endl;
      for (long long i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << endl;
      continue;
    }
    for (long long i = 0; i < n; i++) {
      if (is(s - a[i]) == 0) {
        p = i;
        break;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (i != p) {
        cout << i + 1 << " ";
      }
    }
    cout << endl;
  }
}
