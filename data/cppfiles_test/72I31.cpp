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
  long long d1 = query(1, 1e9);
  long long d2 = query(1e9, 1e9);
  long long y = 1 + (1e9 - 1 - d1 + d2) / 2;
  long long d3 = query(1e9, y);
  long long d4 = query(1, y);
  cout << "! " << 1 + d4 << " " << 1 + abs(d2 - d3) << " " << 1e9 - d3 << " "
       << 1e9 - abs(d1 - d3) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
}
