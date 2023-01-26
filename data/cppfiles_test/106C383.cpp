#include <bits/stdc++.h>
using namespace std;
long long ceilAB(long long a, long long b) { return (a + b - 1) / b; }
long long Pow(long long c, long long d) {
  return d == 0 ? 1 : c * pow(c, d - 1);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
const int mx = 1e6;
int a[mx];
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int i, j, k, n, m, x, y, z, c = 0, cnt = 0;
    string s;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cout << i + 1 << " ";
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}
