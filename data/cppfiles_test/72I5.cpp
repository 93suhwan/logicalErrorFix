#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long x, long long y) {
  if (y == 0) return 1;
  long long p = powmod(x, y / 2) % 1000000007;
  p = (p * p) % 1000000007;
  return (y % 2 == 0) ? p : (x * p) % 1000000007;
}
long long inverse(long long a) { return powmod(a, 1000000007 - 2); }
bool codejam = 0, testcases = 0;
void solve() {
  long long x, y, p, q;
  long long l = 2, r = 1000000000;
  while (l < r) {
    long long mid = (l + r) / 2;
    long long d[3];
    for (long long i = -1; i <= 1; i++) {
      cout << "? " << 1 << ' ' << mid + i << endl;
      cin >> d[i + 1];
    }
    if (d[1] > d[2])
      l = mid + 1;
    else if (d[0] <= d[1])
      r = mid - 1;
    else
      break;
  }
  x = l;
  l = 2, r = 1000000000;
  while (l < r) {
    long long mid = (l + r) / 2;
    long long d[3];
    for (long long i = -1; i <= 1; i++) {
      cout << "? " << mid + i << ' ' << 1 << endl;
      cin >> d[i + 1];
    }
    if (d[1] > d[2])
      l = mid + 1;
    else if (d[0] <= d[1])
      r = mid - 1;
    else
      break;
  }
  y = l;
  l = 2, r = 1000000000;
  while (l < r) {
    long long mid = (l + r) / 2;
    long long d[3];
    for (long long i = -1; i <= 1; i++) {
      cout << "? " << 1000000000 << ' ' << mid + i << endl;
      cin >> d[i + 1];
    }
    if (d[1] >= d[2])
      l = mid + 1;
    else if (d[0] > d[1])
      r = mid - 1;
    else
      break;
  }
  p = l;
  l = 2, r = 1000000000;
  while (l < r) {
    long long mid = (l + r) / 2;
    long long d[3];
    for (long long i = -1; i <= 1; i++) {
      cout << "? " << mid + i << ' ' << 1000000000 << endl;
      cin >> d[i + 1];
    }
    if (d[1] >= d[2])
      l = mid + 1;
    else if (d[0] > d[1])
      r = mid - 1;
    else
      break;
  }
  q = l;
  cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  if (testcases) cin >> t;
  for (long long i = 0; i < t; i++) {
    if (codejam) cout << "Case #" << i + 1 << ": ";
    solve();
  }
}
