#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
const int MOD = 1e9 + 7;
const int N = 4e7;
void solve() {
  int n;
  cin >> n;
  for (long long i = (1); i < (n + 1); i++) {
    cout << 2 * (i) + 1 << ' ';
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
