#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long query(long long i, long long j) {
  long long ans;
  cout << "? " << i << " " << j << endl;
  cin >> ans;
  return ans;
}
void solve() {
  long long x1 = query(1, 1);
  long long y1 = query(1 + x1 / 2, 1);
  long long z1, a1;
  if (y1 == (x1 + 1) / 2) {
    z1 = query(1, 1 + (1 + x1) / 2) + 1;
    a1 = query(z1, 1) + 1;
  } else {
    a1 = y1 + 1;
    z1 = query(1, a1) + 1;
  }
  long long x2 = query(1e9, 1e9);
  long long y2 = query(1e9 - x2 / 2, 1e9);
  long long z2, a2;
  if (y2 == (1 + x2) / 2) {
    z2 = query(1e9, 1e9 - (1 + x2) / 2);
    a2 = query(1e9 - z2 - 1, 1e9);
    z2 = 1e9 - z2;
    a2 = 1e9 - a2;
  } else {
    a2 = y2;
    z2 = 1e9 - query(1e9, 1e9 - a2);
    a2 = 1e9 - a2;
  }
  cout << "! " << z1 << " " << a1 << " " << z2 << " " << a2 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
}
