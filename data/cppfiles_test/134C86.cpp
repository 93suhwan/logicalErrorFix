#include <bits/stdc++.h>
using namespace std;
long long power(long long base, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2)
      res *= base, n--;
    else
      base *= base, n /= 2;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    vector<long long> odd, even, v;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      v.push_back(a);
      if (i % 2 == 0)
        even.push_back(a);
      else
        odd.push_back(a);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    long long x = even[0];
    for (long long i = 1; i < even.size(); i++) {
      x = gcd(x, even[i]);
    }
    long long y = odd[0];
    for (long long i = 1; i < odd.size(); i++) {
      y = gcd(y, odd[i]);
    }
    long long ok = 0;
    for (long long i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (v[i] % x != 0) ok = 1;
      } else {
        if (v[i] % x == 0) ok = 1;
      }
      if (ok) break;
    }
    if (!ok) {
      cout << x << endl;
      continue;
    }
    ok = 0;
    for (long long i = 0; i < n; i++) {
      if (i % 2 == 1) {
        if (v[i] % y != 0) ok = 1;
      } else {
        if (v[i] % y == 0) ok = 1;
      }
      if (ok) break;
    }
    if (!ok) {
      cout << y << endl;
      continue;
    }
    cout << 0 << endl;
    ;
  }
  return 0;
}
